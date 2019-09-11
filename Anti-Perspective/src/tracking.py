import cv2
import numpy as np

class Tracker:
    def __init__(self):
        self.cam = cv2.VideoCapture(0)
        self.cam.read() # takes a frame or two for a good result
        self.get_frame()
    def get_frame(self):
        success, self.frame = self.cam.read()
        assert success
        return self.frame
    def __call__(self):
        return self.find_face()
    def find_face(self):
        pass

#Ignore size tracking and any sort of smoothing for now
class RepeatingDetector(Tracker):
    def __init__(self):
        super().__init__()
        self.haar = cv2.CascadeClassifier(
            "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml"
        )
    def find_face_rect(self):
        gray = cv2.cvtColor(self.frame, cv2.COLOR_BGR2GRAY)
        rects = self.haar.detectMultiScale(gray)
        return max(rects, key=lambda r:r[2]*r[3])
    def find_face(self):
        face = self.find_face_rect()
        return face[0]+(face[2]//2), face[1]+(face[3]//2)

class FacemarkRepeatingDetector(RepeatingDetector):
    def __init__(self):
        super().__init__()
        self.facemark = cv2.face.createFacemarkLBF()
        self.facemark.loadModel('../lbfmodel.yaml')
        print('loaded')
    def find_face(self):
        rect = self.find_face_rect()
        success, face = self.facemark.fit(self.frame, np.array([rect]))
        assert success
        return face[0][27]

import cv2

class Tracker:
    def __init__(self):
        self.cam = cv2.VideoCapture(0)
        cam.read() # takes a frame or two for a good result
        self.get_frame()
    def get_frame(self):
        success, self.frame = cam.read()
        assert success
        return self.frame
    def __call__(self):
        return self.find_face()
    def find_face(self):
        pass

#Ignore size tracking and any sort of smoothing for now
class RepeatingDetector(Tracker):
    def find_face(self):
        pass

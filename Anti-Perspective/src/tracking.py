import cv2

class Tracker:
    def __init__(self):
        self.cam = cv2.VideoCapture(0)
        cam.grab() # takes a frame or two for a good result
        cam.grab()
    def get_frame(self):
        success, frame = cam.read()
        assert success
        return frame
    def __call__(self):
        return self.find_face()
    def find_face(self):
        pass

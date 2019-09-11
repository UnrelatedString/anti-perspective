import cv2
from transform import VirtualImage

class SliderFrontend:
    def __init__(self, path):
        self.vi = VirtualImage(cv2.imread(path), (700,700))
        cv2.imshow('Source', self.vi.img)
        cv2.namedWindow('Result')
        cv2.createTrackbar('distance',
                           'Result',
                           1,
                           10000,
                           self.vi.update_distance)
        cv2.createTrackbar('angle',
                           'Result',
                           0,
                           180,
                           self.vi.update_angle)
    def __call__(self):
        self.run()
    def run(self):
        while cv2.waitKey(15) & 0xff != 27:
            cv2.imshow('Result', self.vi())
    def __del__(self):
        cv2.destroyWindow('Source')
        cv2.destroyWindow('Result')

class TrackerFrontend:
    pass

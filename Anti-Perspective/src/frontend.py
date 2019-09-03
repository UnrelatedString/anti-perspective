from transform import *

class SliderFrontend:
    def __init__(self, path):
        self.vi = VirtualImage(cv2.imread(path), (700,700))
        cv2.imshow('Source', vi.img)
        cv2.namedWindow('Result')
        cv2.createTrackbar('distance',
                           'Result',
                           1,
                           10000,
                           vi.update_distance)
        cv2.createTrackbar('angle',
                           'Result',
                           0,
                           180,
                           vi.update_angle)
    def __call__(self):
        while cv2.waitKey(15) & 0xff != 27:
            cv2.imshow('Result', vi())
    def __del__(self):
        cv2.destroyWindow('Source')
        cv2.destroyWindow('Result')

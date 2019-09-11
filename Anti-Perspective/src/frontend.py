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
    def __init__(self, tracker):
        cv2.namedWindow('Tracking')
        self.tracker = tracker
    def __call__(self):
        self.run()
    def run(self):
        while cv2.waitKey(15) & 0xff != 27:
            frame = tracker.get_frame()
            point = tracker()
            frame = cv2.drawMarker(frame, point, (0,255,255), thickness = 2)
            frame = cv2.putText(frame,
                                "x:%d y:%%d"%point.x%point.y,
                                (100,80),
                                cv2.HERSHEY_FONT_SIMPLEX,
                                .75,
                                (255,255,0))
            cv2.imshow('Tracking',frame)

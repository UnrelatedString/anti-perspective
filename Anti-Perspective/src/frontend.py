import cv2
from transform import VirtualImage
from math import acos, degrees

class SliderFrontend:
    def __init__(self, path):
        self.vi = VirtualImage(cv2.imread(path), (700,700))
        cv2.imshow('Source', self.vi.img)
        cv2.namedWindow('Result', cv2.WINDOW_NORMAL)
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
        self.tracker = tracker
        cv2.namedWindow('Tracking', cv2.WINDOW_NORMAL)
        cv2.imshow('Tracking', self.tracker.get_frame())
    def __call__(self):
        self.run()
    def run(self):
        while cv2.waitKey(15) & 0xff != 27:
            frame = self.tracker.get_frame()
            try:
                point = self.tracker()
            except Exception as e:
                print(repr(e))
                continue
            x, y = point
            frame = cv2.drawMarker(frame, (x,y), (50,255,50), thickness = 2)
            frame = cv2.putText(frame,
                                "x:%d y:%%d"%x%y,
                                (100,80),
                                cv2.FONT_HERSHEY_SIMPLEX,
                                .75,
                                (255,255,0))
            cv2.imshow('Tracking',frame)

#Ignore distance for now, I guess
class AntiPerspectiveFrontend:
    def __init__(self, path, tracker):
        self.vi = VirtualImage(cv2.imread(path), (700,700))
        self.vi.update_distance(2000)
        self.tracker = tracker
        cv2.namedWindow('Result', cv2.WINDOW_NORMAL)
        #Distance slider I guess?
        cv2.createTrackbar('distance',
                           'Result',
                           1,
                           10000,
                           self.vi.update_distance)
    def __call__(self):
        self.run()
    def run(self):
        while cv2.waitKey(15) & 0xff != 27:
            frame = self.tracker.get_frame()
            try:
                point = self.tracker()
            except Exception as e:
                print(repr(e))
                continue
            x = point[0]-(frame.shape[1]//2) #??
            self.vi.update_angle(-90+degrees(acos(x/self.vi.transform.d))) #??
            print(-90+degrees(acos(x/self.vi.transform.d)))
            cv2.imshow('Result', self.vi())

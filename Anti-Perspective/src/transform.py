import numpy as np
import cv2
from math import sin, cos, radians
from data_classes import *

class Transform:
    def __init__(self):
        self.d = 1
        self.theta = 0
    def get_mat(self):
        a = radians(self.theta)
        s = sin(a)
        c = cos(a)
        d = self.d
        return np.array([
            [c,   0, -s*d],
            [0,   1, 0],
            [s/d, 0, c]
        ])
    def __call__(self, size):
        return np.array([
                [1, 0, size[0]//2],
                [0, 1, size[1]//2],
                [0, 0, 1]
            ]) @\
            self.get_mat() @\
            np.array([
                [1, 0, -size[0]//2],
                [0, 1, -size[1]//2],
                [0, 0, 1]
            ])

class VirtualImage:
    def __init__(self, img, size):
        self.img = cv2.resize(img, size, interpolation=cv2.INTER_NEAREST)
        self.size = size
        self.transform = Transform()
    def update_distance(self, d):
        self.transform.d = d or 1
    def update_angle(self, theta):
        self.transform.theta = theta
    def __call__(self):
        return cv2.warpPerspective(self.img,
                                   self.transform(self.size),
                                   self.size,
                                   flags = cv2.INTER_NEAREST)

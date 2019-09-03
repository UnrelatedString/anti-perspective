import numpy as np
import cv2
from math import sin, cos, radians
from data_classes import *

class Transform:
    def __init__(self):
        self.d = 1
        self.theta = 0
    def get_mat(self):
        a = radians(theta)
        s = sin(a)
        c = cos(a)
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
            get_mat() @\
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
        transform.d = d
    def update_angle(self, theta):
        transform.theta = theta
    def __call__(self):
        return cv2.warpPerspective(img,
                                   transform(),
                                   size,
                                   flags = cv2.INTER_NEAREST)

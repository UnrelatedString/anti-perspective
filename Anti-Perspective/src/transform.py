import numpy as np
import cv2
from math import sin, cos, radians
from data_classes import *

class Transform:
    def __init__():
        self.d = 1
        self.theta = 0
    def get_mat():
        a = radians(theta)
        s = sin(a)
        c = cos(a)
        return np.array([
            [c,   0, -s*d],
            [0,   1, 0],
            [s/d, 0, c]
        ])
    def __call__(size):
        return np.array([
                [1, 0, size[0]//2],
                [0, 1, size[1]//2],
                [0, 0, 1]
            ]) @
            get_mat() @
            np.array([
                [1, 0, -size[0]//2],
                [0, 1, -size[1]//2],
                [0, 0, 1]
            ])

class VirtualImage:
    pass

class Observer:
    def __init__(self, x, y, u):
        self.x = x
        self.y = y
        self.u = u

class Location:
    def __init__(self, d, theta, phi):
        self.d = d
        self.theta = theta
##        self.phi = phi #vertical

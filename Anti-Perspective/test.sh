#!/usr/bin/env bash

cd src
python3 -c "from frontend import TrackerFrontend as f; from tracking import RepeatingDetector as d; f(d())()"

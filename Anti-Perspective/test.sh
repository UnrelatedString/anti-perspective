#!/usr/bin/env bash

cd src
python3 -c "from frontend import AntiPerspectiveFrontend as f; from tracking import FacemarkRepeatingDetector as d; f('../$1',d())()"

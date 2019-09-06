#!/usr/bin/env bash

cd src
python3 -c "from frontend import SliderFrontend as f; f('../$1')()"

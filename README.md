# anti-perspective

The end goal is that you can boot this up and no matter what angle you're looking at the image from it looks like you're staring at it head on. We're not quite there yet.


### WHAT WE HAD TO DO ON CLIFF'S UBUNTU

```bash
cd /usr/local/include/opencv/build/lib
sudo su
for p in $( echo libopencv_*.so.3.4.5 ); do x=$(sed "s/.so.3.4.5/.3.4.5.so/" <(echo $p)); ln -s $p $x; done
ldconfig /usr/local/include/opencv/build/lib
```

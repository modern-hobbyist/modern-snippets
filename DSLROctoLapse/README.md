# OctoLapse with a DSLR camera
The goal of this project was to create a timelapse of my 3d prints with a much better resolution that I could get out of the cheap webcam I have (actually it's salvaged from an old laptop) and the Raspberry Pi camera, which had a very short cable.

OctoLapse is a very useful plugin for OctoPrint and it has many options that can be configured to work for your purpose. By configuring custom camera profiles to trigger a script, and with the help of FormerLurker (the original OctoLapse Author) I was able to capture timelapses of my 3d prints using my Nikon D80. FormerLurker provided a script to capture the image from your digital camera and download it to the directory OctoLapse needed it, so OctoLapse could render the image, but I wanted to save all of my snapshots on my SD card so I could render the timelapse myself in Premiere Pro. To do this, I updated FormerLurker's script a little bit to save the snapshot to my camera rather than the OctoPi directory. 

[FormerLurker](https://github.com/FormerLurker)
[OctoLapse with DSLR](https://github.com/FormerLurker/Octolapse/wiki/Configuring-an-External-Camera)
[OctoLapse](https://github.com/FormerLurker/Octolapse)
[GPhoto2](http://www.gphoto.org/)
[GPhoto2 Compatible Cameras](http://gphoto.org/proj/libgphoto2/support.php)

# Setup
To get started, follow the instruction provided by FormerLurker that are provided above. If you want to have the snapshots on your SD card as well, either copy the original `take-snapshot.sh` script and make the necessary changes, or download the `take-snapshot-to-sd.sh` script I wrote and point OctoLapse to it.

The main change in my script, is the GPhoto2 command. Previously, the script captured the snapshot and downloaded it to the OctoPi directory that OctoLapse used. In my version, the script captures a snapshot but saved it onto the SD card of the camera. This way I not only have access to every snapshot after the print, but I can render the timelapse myself.

This is handy if you need to create a thumbnail for your video, or if you want to share just one picture of your print to show off the cool infil patterns or shapes at that point.

Make sure to checkout my setup video on my YouTube Channel [Modern Hobbyist](https://www.youtube.com/channel/UCjgA1ehfjkZ4WMa5Cw9f1LA)!

# Multiple Timelapses
One thing that OctoLapse allows you to do, is setup multiple camera profiles. Using this feature, I was able to setup a USB webcam that was inside my enclosure, and a DSLR camera that was outside my enclosure. With them both enabled, OctoLapse triggered my digital camera and also captured the USB webcam snapshot each time the printhead was in position. This way you can create multiple timelapses of a single print, to highlight your print from multiple angles. Check out my video on this project if you want to learn more!

# Credit
Huge shout out to [FormerLurker](https://github.com/FormerLurker) for his work on OctoLapse, it truly is a great program that is fully customizable to your needs. Also, thanks for the great documentation you provided on your DSLR setup.
# KZ BHOP GENERATOR
This program will create a .vmf file with the specified number of blocks placed at random (within the specified range) starting from the center of the grid and going up the X axis (right in Hammer's top view).

## Usage
bhop -blocks # -width # -height # -distmin # -distmax #  
E.g.: bhop -blocks 10 -width 64 -height 128 -distmin 64 -distmax 80
will create a .vfm file with 10 64x64x128 blocks with a random distance (chosen from a range of 64-80) between them. Distance is calculated independently for X and Y axes.  
Solid.dat, vmf_top.dat, and vmf_bottom.dat need to be in the same folder as the executable.

# Mesh Bed Leveling
Mesh bed leveling is a process of creating a mesh model of your 3d printer's bed, that allows your printer to compensate for a warped 
bed while printing. 

In this document, I will cover the steps that I follow when I create a mesh for my bed, and I will share some commands that 
will allow you to update a single point on your mesh, so you don't have to do the entire mesh creation process.

[Marlin Documentation](https://marlinfw.org/docs/gcode/G029-mbl.html)

Make sure to check out my video on this topic!
...

## Important Commands
```
G29 S0    # Fetch and Display existing mesh table
G29 S1    # Start Mesh Creation Process
G29 S2    # Move to Next mesh point
G29 S3 X<x coord> Y<y coord> Z<z offset>    # Update specific mesh point z offset
G29 S5    # Delete and disable existing mesh
```

## Steps
1. Heat bed to operational temperature
    1. Your bed changes shape as it heats up, so for all steps outlined below, make sure your bed is heated.
1. Level your bed 
    1. Use the default bed leveling method for your printer.
1. Start the mesh bed leveling procedure from the touchscreen on the printer
1. Adjust the distance between the bed and the nozzle using the touchscreen options
    1. *Use only software to adjust the distance between the nozzle and the bed* 
1. Proceed to the next calibration point.
1. Repeat steps 4 & 5 until all calibration points have been completed.
1. Add the following commands below the G28 line in the "Start GCODE" option within your slicer.
    ```
    M501
    M420 S1
    ```
1. Done!

## Manual Commands
1. To start the mesh creation procedure send 
    ```
    G29 S1
    ```
1. Set the printer to absolute positioning
    ```
    G91
    ```
1. Incrementally adjust nozzle height until it is a suitable distance from the print bed at the current calibration point
    1.
    ```
    G1 Z<adjustment incremtent>
    ```
    1. e.g. Moves the printhead up
    ```
    G1 Z0.01
    ```
    1. e.g. Moves the printhead down
    ```
    G1 Z-0.01
    ```
1. Return to absolute positioning
    ```
    G90
    ```
1. Move to the next calibration point
    ```
    G29 S2
    ```
1. Repeat adjustment steps until all calibration points are completed
1. Save to EEPROM
    ```
    M500
    ```
    
## Individual Point Adjustment
1. To adjust an individual point, you must first have created a mesh following the steps above.
1. Print out the current mesh
    ```
    G29 S0
    ```
1. Adjust the point you want with the coordinates 
    ```
    G29 S3 X<x coord> Y<y coord> Z<z offset>
    ```
    1. Add 1 to each coordinate since the table is 1 offset in EEPROM
    2. Z offset is the absolute height that you want to adjust to, NOT AN INCREMENT
    3. e.g. Adjust the center point <3,3> to a height of 0.12mm above absolute 0
    ```
    G29 S3 X3 Y3 Z0.12
    ```
    

    

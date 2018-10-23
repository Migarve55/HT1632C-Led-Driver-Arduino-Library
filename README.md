# HT1632C-Led-Driver-Arduino-Library
This arduino library allows you to control a HT1632C Led driver through an arduino. This is typically used for controlling LED matrixes. 

This is can be used for controlling any kind of 16 by 16 LED Matrix, however, you may find problems using this driver with your particular board,
mainly becouse the name of the connectors in your matrix. You should figure out which pin is which.

Use the examples provided to see how to connect the pins.

This is the general layout:

    - A, B, C, D pins for selecting the data line (most boards are labeled like this).
    - CLK pin for the clock. It should be easy to find.
    - DI: Data In. 
    - OE: This name changes from board to board.
    - ST: Ditto.

There are only two pins that may change their name, so just swap them and see if it works. Do not worry, this will not destroy the driver, so it will not take more than one minute to make it work. 
ticktickboom
============

An Arduino based word game

Selects a random category and card, turns on a timer with a LED connected to digital
 pin 13 and a ticking buzzer connected to digital
  pin 3, when pressing a pushbutton attached to pin 2.
   Then it gives out a text on the lcd.
    After the time is up the buzzer will make a noise for
     a second.


      The circuit:
       * LED attached from pin 13 to ground
        * buzzer attached from pin 3 to ground
         * pushbutton attached to pin 2 from +5V
          * 10K resistor attached to pin 2 from ground

# TRACKzeron: Adding trackball functionality to the [Azeron Keypad](https://www.azeron.eu/)

This repository contains source code and prebuilt firmware files for a modified Azeron keypad.

![](https://user-images.githubusercontent.com/16569424/107110059-db20ec00-6812-11eb-9fe6-563b27339a3a.jpg)

***Thanks to the staff at Azeron for sharing my modification and dual keypad setup on their social media! People had questions about the mod, so I compiled this document.***

***If you have any other questions, you can message me in Azeron’s Discord.***

***Kind regards,***
***MK***

## Answers to questions:

### “TRACKzeron”? Huh?
Trackball + Azeron = TRACKzeron.

### How did you add the trackball?
See the guide below.

### How do you use Azeron Software with two keypads at once?
**Short answer:** I don’t.  
**Long answer:** I had to compile custom firmware to make the trackball work, so this modded keypad doesn’t work with the official Azeron software. I use reWASD to remap the keys.
Also, using two keypads simultaneously isn’t officially supported by Azeron software, even if they’re both stock firmware/unmodded.

### Do you have a video where you’re playing with both keypads together?
~~No, I don’t. Sorry :(~~  
Video is here: [https://youtu.be/LT7abxc7oYk](https://youtu.be/LT7abxc7oYk). There will be more on [my Twitch channel](https://twitch.tv/allphobic13)

## Notes

-   This mod has no official Azeron support.
-   I had to compile custom firmware to make the trackball work, so this modded keypad does not work with the official Azeron software.
-   This mod requires soldering   
-   Modifying your device always comes with risk attached. I’m sharing what worked for me and offer no guarantees.

## Files

### Trackball Assembly STL ([Trackball_Holder.stl](https://github.com/melaphor/trackzeron/blob/main/STL/Trackball_Holder.stl))

### Firmware
Ready-to-flash firmware files are here: [Prebuilt_hex](https://github.com/melaphor/trackzeron/tree/main/Prebuilt_hex)

#### [AzeronTrackballMod (“reWASD” firmware)](https://github.com/melaphor/trackzeron/tree/main/AzeronTrackballMod)
This is the firmware I usually use on my keypad. I use reWASD to remap.

#### [AzeronXimAlt-trackballmod“ (JoyToKey” firmware)](https://github.com/melaphor/trackzeron/tree/main/AzeronXimAlt-trackballmod)

It's a modified version of W11cE's Simple XIM Firmware. All buttons are joystick buttons. Intended for use with JoyToKey. May also still work with XIM but I haven’t tested that.

#### [QMK Firmware](https://github.com/melaphor/trackzeron/tree/main/QMK)
[QMK](https://qmk.fm/) port. Includes support for the [VIA configurator](https://caniusevia.com/).

~~NOTE: Click and drag DOES NOT work in QMK Firmware.~~ 
**2021-Feb-05:** Click and drag works now! Shout out to [drashna](https://github.com/drashna) and [ploopyco](https://github.com/ploopyco) for their work on the [Ploopy trackball QMK code](https://github.com/qmk/qmk_firmware/tree/master/keyboards/ploopyco/trackball), which I adapted for the TRACKzeron.

##### VIA Keymap ([trackzeron.json](https://github.com/melaphor/trackzeron/blob/main/VIA_keymap/trackzeron.json))

Needed for VIA to recognize the device. Must use with QMK firmware.  
Load into VIA using *Design > Load Draft Definition*

## Source Code:

- Teensy/Arduino sketches: 
	- [AzeronTrackballMod](https://github.com/melaphor/trackzeron/tree/main/AzeronTrackballMod)
	- [AzeronXimAlt-trackballmod](https://github.com/melaphor/trackzeron/tree/main/AzeronXimAlt-trackballmod)
-   [QMK](https://github.com/melaphor/trackzeron/tree/main/QMK)
    

## Guide

### Parts
- Azeron Keypad: [https://www.azeron.eu/](https://www.azeron.eu/)
- PMW3360 Motion Sensor: [https://www.tindie.com/products/jkicklighter/pmw3360-motion-sensor/](https://www.tindie.com/products/jkicklighter/pmw3360-motion-sensor/)   
- 3D printed trackball holder assembly: [https://www.thingiverse.com/thing:4667691](https://www.thingiverse.com/thing:4667691)
- 52mm ball: (I used the ball from an Elecom Huge: [https://www.elecom.co.jp/products/M-HT1DRBK.html](https://www.elecom.co.jp/products/M-HT1DRBK.html))
- 3x 3mm ceramic bearing balls

### Tools
- screwdrivers: hex and Philips heads   
- precision tweezers
- Soldering Iron & solder
- Solder Wick / desoldering tool
- 30 AWG hook up wire (I reused the wires from the thumb assembly)
- wire stripper
- wire cutters
- M2.5 machine screws x2 (idk what length.. I used the thumb rail screws)

### Preparing
-   Remove the Azeron palmrest to reveal the Teensy Board

![Azeron-unchanged](https://user-images.githubusercontent.com/16569424/107108978-5b8f1f00-680a-11eb-86c0-2a26af66000b.png)
    
-   Disconnect the thumbstick, thumb button and D-pad from the Teensy board and grounding block.  
    ![Azeron-removethumb](https://user-images.githubusercontent.com/16569424/107108984-706bb280-680a-11eb-9773-adbbb86909cb.png)
    
- Remove the thumb assembly and thumb button from the rails.
- Print the trackball assembly.   
- Push the ceramic ball bearings into the trackball assembly.   
- Fit the trackball assembly into the Azeron thumb rail.    
- Strip and tin 30 AWG hookup wire OR desolder the wires attached to the thumbstick and D-pad. Need 6 wires.
- Solder wires to the PMW3360 sensor pins (The other two are not used):
	- GD
	- SS    
	- SC
	- MO
	- MI    
	- VI 

## Connecting the PMW3360 Sensor:

- Disconnect the pinky and ring finger switches from the Teensy board (leave the ground [black] wires connected to the grounding block)    
- Reconnect the pinky and ring finger switches as follows:
   	-   Ring finger:
		- High flick/green wire: F7
	    - Flick/red wire: F6
	    - Push/orange wire: F5
	    - Pull/purple wire: F4
	-   Pinky finger:
	    - High flick/green wire: F3
	    - Flick/red wire: F2
	    - push/orange wire: F1
	    - pull/purple wire: F0
	    
![Azeron-movepinkyring](https://user-images.githubusercontent.com/16569424/107109037-e4a65600-680a-11eb-983f-14ca71fb90f0.png)

-   Connect the sensor to the Teensy board as follows:
	- GD: GND    
	- SS: B0
	- SC: B1
	- MO: B2
	- MI: B3
	- VI: +5V
    
![Azeron-addsensor](https://user-images.githubusercontent.com/16569424/107109075-17e8e500-680b-11eb-8602-91806c507511.png)
![Sensor-Teensy](https://user-images.githubusercontent.com/16569424/107109078-1ae3d580-680b-11eb-8402-30c224dd913e.png)

**NOTE:** It's important for the switches and sensor to be connected ***exactly as indicated*** or the device will not work.
- Screw the sensor into the trackball assembly. 
- Load firmware using the Teensy Loader.
- Enjoy trackball keypad

## Default keybinds:

Using “reWASD” version of firmware or QMK firmware:

![TRACKzeron default keymap](https://user-images.githubusercontent.com/16569424/107109080-23d4a700-680b-11eb-86ef-2168594ed880.png)

  

## JoyToKey Button Assignments (using “JoyToKey” firmware):

![TRACKzeron JoyToKey](https://user-images.githubusercontent.com/16569424/107109082-28995b00-680b-11eb-82fe-a649f6bf350d.png)

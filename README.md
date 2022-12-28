# TRACKzeron: Adding trackball functionality to the [Azeron Keypad](https://www.azeron.eu/)

This repository contains source code and prebuilt firmware files for a modified Azeron keypad.

![](https://user-images.githubusercontent.com/16569424/107110059-db20ec00-6812-11eb-9fe6-563b27339a3a.jpg)

## Only for Classic and Compact models with TEENSY++ 2.0 mainboards

**This does not work with the Cyborg/Cyborg compact models.** It is for Azeron devices that use the Teensy++ 2.0 (green) mainboard. The Teensy++ 2.0 was discontinued in 2021, and Azeron started shipping models with their proprietary ARM/STM32-based (black) mainboard in mid-2022. I will not be adding support for the Azeron proprietary mainboards and there is no ETA on a mod for Cyborg models with Teensy mainboards.

## Notes

-   This mod has no official Azeron support.
-   I had to compile custom firmware to make the trackball work, so this modded keypad does not work with the official Azeron software.
-   This mod requires soldering. (No soldering to anything on the keypad, just the sensor module)   
-   Modifying your device always comes with risk attached. I’m sharing what worked for me and offer no guarantees.

## FAQs:

### “TRACKzeron”?
Trackball + Azeron = TRACKzeron.

### Will this work on my device with a black mainboard?
The firmware will not work. The new black mainboards have a different chip. The firmware was not designed for it. I cannot confirm whether the new mainboard can be rewired to accommodate the sensor. 

### Will this work on the Azeron Cyborg or Cyborg Compact model?
No. The Cyborg models are wired differently. Unfortunately I have not figured out the rewiring and I do not have an ETA on if/when the Cyborg mod will be done.

### How did you add the trackball?
See the [guide](#guide).

### How does this work in the Azeron Software?
***This mod is not compatible with the official Azeron Software.*** You will need to use a different software to set your keybinds. I have used reWASD and JoyToKey.

### How do you use the Azeron Software with two keypads at once?
Using two keypads simultaneously isn’t officially supported by the Azeron software (yet? seems like they're working on that), even if they’re both stock firmware/not modified, but a workaround for two unmodified keypads is to plug in one keypad, set the keybinds, then unplug. Plug in the second keypad and set those keybinds. You won't be able to change the keybinds while they're both plugged in, but they should work in-game.

### Do you have a video where you’re playing with both keypads together?
Yes; there's a [YouTube clip](https://youtu.be/LT7abxc7oYk) of me playing Mass Effect Andromeda,
and some of me playing Borderlands on [my Twitch channel](https://twitch.tv/allphobic13).

### Can you make me one?
No.

## Guide

### Parts
- [Azeron Keypad](https://www.azeron.eu/) (Classic or Compact)
- [PMW3360 Motion Sensor](https://www.tindie.com/products/jkicklighter/pmw3360-motion-sensor/)   
- [3D printed trackball holder assembly](https://www.thingiverse.com/thing:4667691)
- 52mm ball: (I use the ball from an [Elecom Huge](https://elecomus.com/web/product/3271/) trackball, but I have verified that a 2 <sup>1</sup>/<sub>16</sub> inch[52.5mm] [snooker/billiard ball](https://www.johnparrottsports.com/snooker/snooker-balls/#category175) works)
- Three (3) [3mm ceramic bearing balls](https://www.bcprecision.com/products/3mm-zro2-zirconium-oxide-ceramic-ball-bearings-g5) 
- [28 AWG wire](https://www.mouser.com/c/wire-cable/hook-up-wire/?wire%20gauge%20-%20awg=28%20AWG) (I reused the wires from the thumb assembly; you'll need solder wick or a desoldering tool to reuse wire)
-  2 to 4 [M2.5x10 machine screws](https://store.azeron.eu/index.php?route=product/product&path=62&product_id=82)
- 2 M2.5 [hex nuts](https://www.mcmaster.com/nuts/hex-nuts/) if using the updated model
### Tools
- screwdrivers: hex, Philips, and flat heads 
- precision tweezers
- Soldering Iron & solder
- wire stripper
- wire cutters

### Preparing
- 3D print the trackball assembly.   
- Push the ceramic ball bearings into the trackball assembly.   
- Strip and tin 7-9 inches of 28 AWG hookup wire OR desolder the wires attached to the thumbstick and D-pad. Need 6 wires.
- Solder wires to the PMW3360 sensor pins (The other two are not used):
	- GD
	- SS    
	- SC
	- MO
	- MI    
	- VI 

### Rewire the Azeron
-   Remove the Azeron palmrest to reveal the Teensy Board

![Azeron-unchanged](https://user-images.githubusercontent.com/16569424/107108978-5b8f1f00-680a-11eb-86c0-2a26af66000b.png)   

- Disconnect the thumbstick and D-pad from the Teensy board and grounding block.  
- Remove the thumbstick assembly from the rail.

![Azeron-removethumb](https://user-images.githubusercontent.com/16569424/107108984-706bb280-680a-11eb-9773-adbbb86909cb.png)

- Disconnect the pinky and ring finger switches from the Teensy board (**leave the ground [black] wires connected to the grounding block**)    
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


### Connect the PMW3360 Sensor:
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
- Attach the sensor to the trackball assembly. 
- Fit the trackball assembly to the Azeron thumb rail.   
- Reattach the palmrest
- Place ball in cup.
- Load firmware HEX file using the Teensy Loader.
- Enjoy trackball keypad

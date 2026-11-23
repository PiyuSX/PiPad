---
title: "PiPad"
description: "A custom macro pad"
created_at: "2026-11-07"
total_time: "19h 36m" (Estimated Maybe More)
---

# November 7, 2026: Made the Schematics

Ahh i was watching Joe Scotto tutorial for KI CAD "How to Design Mechanical Keyboard PCBs with Kicad
" cuz i was totally begginer and still struggling from 2-3 hours for basics but Still havent figured out what the error was but i fixed it eventually. 

SO i have Made the schematics and in the PCB way and going on

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/01_78c49b3c_Screenshot_2026-11-07_150948.png)
![](https://cdn.piyushrajbanshi.com.np/pipad_assets/02_e71b3aaa_Screenshot_2026-11-07_154814.png)
![](https://cdn.piyushrajbanshi.com.np/pipad_assets/03_f5c35924_Screenshot_2026-11-07_161709.png)
![](https://cdn.piyushrajbanshi.com.np/pipad_assets/04_2725a7cf_Screenshot_2026-11-07_184504.png)
![](https://cdn.piyushrajbanshi.com.np/pipad_assets/05_ff08ec48_Screenshot_2026-11-07_184744.png)

**Total time spent: 3h 30m**

# November 7, 2026: More on PCB

I made this upto here so The thing is i forgot to add the battery and the knob so next i will be doing is updating the schematics and then im coming back soon



[![PiPad Demonstration](https://cdn.piyushrajbanshi.com.np/pipad_assets/Screenshot%202026-11-23%20201208.png)](https://cdn.piyushrajbanshi.com.np/pipad_assets/Recording%202026-11-07%20200044.mp4)

[▶ Watch PiPad Demonstration](https://cdn.piyushrajbanshi.com.np/pipad_assets/Recording%202026-11-07%20200044.mp4)



**Total time spent: 1h 48m**

# November 7, 2026: PCB design

I forgotted to add knob so i did it and there was some error in the 3d files so i downloaded it from external site and I attached the knob so this will be gonna the final Layout for this PiPad

Since im lil bit new so im taking much more time than a begginer and i followed upon tutorial for starting and now i can do things on my own and I added this Display , knob on my own the tutorial didnt had this and im loving this thanks hackclub for showing me my this side

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/06_f85c1471_Screenshot_2026-11-07_211734.png)
![](https://cdn.piyushrajbanshi.com.np/pipad_assets/07_673e1413_Screenshot_2026-11-07_211805.png)

**Total time spent: 1h**

# November 8, 2026: Routed the PCB 

Hmm today I fixed some errors , I today did the Wires routing part and I moved the board in left to that dont interfare with the Pins of the knob and the PCB parts are finally done and i Have produced the gerbers.zip using Fabricate plugin and Moving next to CAD.

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/08_9fc4d205_Screenshot_2026-11-08_145440.png)

**Total time spent: 3h**

# November 9, 2026: PCB CASE 

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/09_6d526324_image.png)

After making the 3d CAD design i got to know that my PIPad  got bulky SO i am rediting my PCB again to putting the screws to center and I want minimal design and after this i will design the CAD again in FUSION. Lol i might have OCD 

This much hours cuz im begginer and have to consume lots of tutorial for The 3d case

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/10_c6a47ad1_Screenshot_2026-11-09_194244.png)

**Total time spent: 4h**

# November 9, 2026: CAD CASE 

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/11_f5aac755_image.png)
As of OCD i redesined the whole case and still have some errors but fixing it tommorrow and with the the case is also 70% completed and Probably next i will be writing the Firmware

**Total time spent: 3h**

# November 10, 2026: More on Case 

SO today i completed the total Case , i smoothed the Edges and Made hole for display and Added screw poles and The Case is all done next I will be going to Make The Firmware

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/12_81832f2e_Screenshot_2026-11-10_123706.png)
![](https://cdn.piyushrajbanshi.com.np/pipad_assets/13_ffc6a82b_Screenshot_2026-11-10_123814.png)

**Total time spent: 1h 30m**

# November 10, 2026: Firmware

I wrote the Firmware with QMK and its passing here but havent tested yet in the hardware cuz im broke to afford and I made it like 4 profiles with 9 keys so total 36 macros and its going from 

       ┌───-┬───-┬──-─┐
     * │ F13│ F14│ F15│
     * ├───-┼───-┼──-─┤
     * │ F16│ F17│ F18│
     * ├───-┼───-┼──-─┤
     * │ F19│ F20│ F21│
     * └───-┴───-┴───-┘


so Thats it 

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/14_f6cc200a_image.png)

**Total time spent: 1h 48m**



# November 23, 2026: Fixed the Flaws

![](https://cdn.piyushrajbanshi.com.np/pipad_assets/Screenshot%202026-11-23%20163747.png)

So the reviewer send PiPad back with few case problems, so i went through the whole fusion design and fixed them.

What I changed 

Keyswitch hole : They were exactly 14.00mm which is too tight for the Keys so i changed all 9 to 14.2

And switch plate height : While checking if found the plate sat about 1mm hight, the switch top housing is 15.6mm wide and overlapped the plate .I lowered the plate to sit on the witch neck, so the switches can actually clickin.

Mounting: The case is 3 printed parts, the body (floor + sidewalls + 4 posts as once piece), the switch plate and the top plate 

I also renamed the parts in the STEP so everything is celar now .

Top Plate: It was only about 0.6 mm thick, so I made it 2.2 mm. It now sits on top of the sidewalls instead of overlapping them. The display window is now 24 x 7.6 mm  and a small frame under it holds the OLED in place

I checked the assembly for overlaps and the top plate does not collied anything .

**Total time spent: 2h**



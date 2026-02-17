https://github.com/josefadamcik/SofleKeyboard

https://josefadamcik.github.io/SofleKeyboard/build_guide_rgb.html

https://docs.keeb.io/elite-pi-guide

https://docs.beekeeb.com/build-guide/sofle-rgb-v2.1-soflekeyboard-build-log-guide-with-photos

### 3D Prints

https://www.printables.com/model/1006363-mx-keycap-set-for-preonic-style-ortholinear-keyboa/files

https://www.thingiverse.com/thing:5444009/files

https://www.printables.com/model/466661-sofle-rgb-full-case/files - The knob from this one

https://github.com/braindefender/KLP-Lame-Keycaps

### Kit List

https://kriscables.com/product/sofle-rgb-kit/

https://mechboards.co.uk/collections/switches/products/gateron-baby-kangaroo

https://www.reddit.com/r/ErgoMechKeyboards/comments/15gbrip/elitec_v4_vs_elitepi/

This needs to be turned into a sharepoint file or word document

### 3D Printing

Already, the cost of this keyboard is pretty high. The total of purchased items is about £160 with shipping if I don’t break anything and don’t need to replace anything. So my plan was to 3D print as much as I can. There are a load of designs on websites like Printables and Thingiverse so I spent a little while searching and came across these designs I liked. The first part that interested me was the keys. As I am using the MX version, the keycaps I need have a cross slot, other than that, the profile and size are mostly up to me. I picked this set because I quite liked the font, I liked the use of two colours, and also the ease of printing. All keys were flat to the bed. I think it is possible to get some more interesting shapes with different print bed alignment but I wanted to get something that worked right away. I made use of the Bambu A1 mini for the keys, and we managed to rig up some other mystery filament that was gifted into the machines so I can get some glow in the dark keys, and some transparent green filament. All of this worked pretty well, and I also printed some blank keys for fun. One thing I would recommend with printers that can use multiple filament prints is to not have two large items with two solid blocks of different colours on the same layer. This is because for every single layer, it will switch between colours, extruding and removing excess and quite frankly it added about 3 hours to this set of 24 keys, so printing them separately will be faster.

Next comes the case. There are a few options. Tenting cases are pretty cool and I would really like to go for that eventually but rather than throw myself in the deep end I am starting with a low profile case that allows for the under-glow LEDs to shine through. But also, I need something to cover the encoder so I print this too. I used these designs.

### Second set of Keys

After practicing typing with the keys printed face down on the Bambu textured print plate, I was finding that the coarseness of the keys was causing my fingers to get sore, so I tried a second set of models that can be found here: 

https://github.com/braindefender/KLP-Lame-Keycaps

I oriented the keys to print at a 15 degree angle from the build plate to minimise the distinctive edges between layers and although these keys do not include a printed legend, I would like to use this keyboard for touch typing and also had not settled on a specific keyboard layout yet.

I ended up using this many of each type:

### Soldering the PCB

Once most of my parts had arrived, I got started on the soldering. 

I started off by seeing if I could make full use of the maker space available to me and use the Voltera PCB reflow oven and solder paste application. Even if I couldn’t do both sides of the PCB with this, it would be great to save myself some time by soldering half of the parts on the boards. Unfortunately the PCB for the Sofle V2.1 RBG is slightly too big. I could fit the PCB on the machine, but some parts were overhanging over the screw holes used for the clamps, and the Y axis limit for the probe was a lot smaller than I realised. I attempted to split the PCB design in kicad and tell the machine it was only doing one part, and after some adjustment I managed to fit the PCB in a way that it could reach the pads I wanted. However, at this moment, there was an issue with the sensors to calibrate the X axis and a horrid grinding noise started, so I gave up on this machine and decided to do it by hand.

I thought I would make one whole side of the keyboard first, learn from my mistakes in how I order the pieces or solder them on, and do a better job of it on the second half. I started with the surface mount LEDs on the underside first. It was the first bit of soldering I had done in a while and they were a little finicky because they require that you manage to get solder across the underneath of the LED, even with ample quantities of flux. I think on the opposite side, I will start by applying a tiny amount of solder to each of the pads on the bed, placing the LED on top, then heating the pad and hoping that it will be enough to melt the solder and that the solder flows happily onto the LED pads. 

Next came the diodes, although for someone starting a surface mount soldering journey, I would probably recommend that you start with those. They are smaller than the LEDs but a lot less expensive and a lot more difficult to ruin. Some of the pins might start off a tiny bit bent but carefully push them back in to place. Obviously follow the instructions and be careful about direction but these components all go on the underside. I did these by starting with a tiny blob of solder on one of the pads, placing the diode on top in the right place then heating the pad so the solder melts around the diode pin, then doing the other side by just heating the pad (and the pin but mainly by proximity) and then putting a tiny amount of solder on top. With the diodes I would say that you can probably manage with the student equipment, with thicker solder and thicker soldering iron tips, but I would strongly discourage using the student equipment on the LEDs. They really do say that you will easily melt through the LEDs and you can with the smaller iron but it is a little bit more difficult.

Then comes the under key LEDs. So these shine through the front of the plate obviously but actually all the soldering happens on the back and the body of the LED pokes through. Because of this, soldering the LEDs are not as difficult as I expected, the LEDs I used and the PCB cut out are just the right clearance to be able to wedge the LEDs in the slot before soldering. My approach to this was to apply a load of flux to the pads, and the back of the LED. Apply solder to the silkscreen pin and then very carefully, briefly heat the corresponding pad on the LED and try to drag the solder across. Once that first pin is connected, the LED is mostly in place. But I warn that if you see bubbling through the top side of the LED, or if a pin on the LED melts off, it’s pretty much ruined and also much harder to get off the board than to get it on. With my very careful and light handed approach, my main concern is that the LEDs will not be connected, and the solder on the LED and the pad may not be fully connected. My plan is to solder the rest, plug it in, and then see which ones don’t shine and follow the debugging procedure listed in the handbook. Resolder the last one that works, and the first one to fail and then see what happens. Another thing to note is that the ground pin will be harder to heat and therefore harder to remelt solder if you mess it up, so if you can’t quite get the alignment right, I would leave the ground pin until last because it is harder to de-solder.

It was at this point that I moved onto the student soldering iron as it was past 5pm. I tried to continue soldering the LEDs which I believe was a mistake. The iron was much bigger, hotter and with worse temperature regulation, so I think I will have cooked more LEDs than I would have if I had just waited.

Given that I couldn’t spend all of the time I had free in the technicians office using the thin soldering iron, I moved onto the student equipment to solder the kalih switch sockets on to the board. As these also go on the back, and they are fairly flat components, it hasn’t been a problem to solder these on even before finishing the LEDs. With these I would recommend just putting a fairly generous blob of solder on one or both of the pads, then placing the socket on top and attempting to get it as flat to the board as possible without bending any of the metal out of the plastic, then heating the bed and the solder should melt around the metal wire. It may take going between the two pins a few times and getting it incrementally closer to a flatter fit but overall it’s a fairly fast component to solder. The further in the two pin sockets are in the PCB, the better and the less likely it will be to bend any of the pins on the switches when you insert them.

Also, while waiting to make use of the technician soldering iron, I soldered on the pins to the microcontrollers. I thought I could make them flat by putting the other side of the pins through the PCB to hold them straight but this didn’t exactly work. I think I would recommend waiting until you finish the board and solder on the socket, then plug in the pins and rest the microcontroller on top (upside down as per instructions) before soldering. I don’t plan on removing the microcontroller and swapping them but accidents happen and having to de-solder 24 pins sounds like hell.

The next week came around and I got access to the technician soldering iron again and decided to go through the current LEDs and check the connectivity. 

![image.jpg](https://prod-files-secure.s3.us-west-2.amazonaws.com/33624021-ca55-475a-b4e1-b3e12ee49381/8b716d69-905e-4197-a528-d47ff9df40a5/image.jpg)

![image.jpg](https://prod-files-secure.s3.us-west-2.amazonaws.com/33624021-ca55-475a-b4e1-b3e12ee49381/c3dd6541-9d10-4ba3-96f1-d65eeeb4de1c/image.jpg)

![image.jpg](https://prod-files-secure.s3.us-west-2.amazonaws.com/33624021-ca55-475a-b4e1-b3e12ee49381/6b53836f-3a7b-4f55-9d18-ab40a0d40c59/image.jpg)

![image.jpg](https://prod-files-secure.s3.us-west-2.amazonaws.com/33624021-ca55-475a-b4e1-b3e12ee49381/6642b3ab-855b-4966-8c2c-364f49e6876a/image.jpg)

![image.jpg](https://prod-files-secure.s3.us-west-2.amazonaws.com/33624021-ca55-475a-b4e1-b3e12ee49381/94a80bae-e45e-436d-bcd8-b10ab2c10811/image.jpg)

![image.jpg](https://prod-files-secure.s3.us-west-2.amazonaws.com/33624021-ca55-475a-b4e1-b3e12ee49381/2a40c257-08e0-44db-9490-4a38a0c18676/image.jpg)

## Construction

Once the whole board was soldered, all switch sockets included

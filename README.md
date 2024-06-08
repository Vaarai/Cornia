<h1 align="center">
 <img src="./images/cornia_banner.png" />
</h1>

# Cornia keyboard

The Cornia keyboard is a split keyboard featuring : 
* 3x6 column strongly staggered keys and 3 thumb keys
* Hotswap sockets (Compatible with Kailh and Gateron)
* All 1u keys
* Same PCB for both hands (revesible)
* No diode to solder (No switch matrix)
* Per key adressable RGB leds (SK6812MINI-E)
* QMK Handedness pin (see [QMK documentation](https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md#setting-handedness))

### Why this name ?

Because it was inspired from the [Corne](https://github.com/foostan/crkbd/tree/main) keyboard, and `Cornia` came in mind.

### Table of contents

<!--ts-->
  * [Hardware](#hardware)
    * [Bill of material](#bill-of-material)
    * [Compatible controllers](#compatible-controllers)
    * [PCB Design](#pcb-design)
  * [Software](#software)
  * [Photos](#photos)
<!--te-->

# Hardware

### Bill of material

| Name | Count | Remarks |
|:-|:-|:-|
| PCB | 2 | |
| OLED cover | 2 sheets | |
| [RP2040 ProMicro](https://keeb.io/products/rp2040-pro-micro-usb-c-controller) | 2 | Alternative: Refer to [Compatible controllers](#compatible-controllers) |
| TRRS 3.5mm jack | 2 | |
| Reset switch | 2 | SMD 4x4mm |
| Hotswap sockets | 42 | Compatible with Kailh and Gateron |
| Key switches | 42 | Only compatible with MX style |
| Keycaps | 42 pieces | 1u 42 pcs |
| TRRS (4 poles) cable | 1 | |
| USB cable | 1 | USB Micro or USB-C depending on the controller, avoid charge-only cables |

### Compatible controllers

| Reference | I²C OLED Screen | Handedness pin | Other features |
|:-|:-:|:-:|:-:|
| [RP2040 Aliexpress](https://fr.aliexpress.com/item/1005005980167753.html) | $${\color{green}✓}$$ | $${\color{green}✓}$$ | $${\color{green}✓}$$ |
| [RP2040 keeb.io](https://keeb.io/products/rp2040-pro-micro-usb-c-controller) | $${\color{green}✓}$$ | $${\color{green}✓}$$ | $${\color{green}✓}$$ |
| [0xCB-Helios](https://github.com/0xCB-dev/0xCB-Helios) | $${\color{green}✓}$$ | $${\color{green}✓}$$ | $${\color{green}✓}$$ |
| [Elite-Pi](https://docs.keeb.io/elite-pi-guide) | $${\color{red}⨯}$$ | $${\color{red}⨯}$$ | $${\color{green}✓}$$ |
| [RP Micro](https://github.com/siderakb/rp-micro) | $${\color{red}⨯}$$ | $${\color{red}⨯}$$ | $${\color{green}✓}$$ |

### PCB Design

[PCB Design and fabrication output](./doc/pcb.md)

# Software

Software will be available soon (based on QMK).

# Photos

![3D Top view](./images/3D_TOP.png)
![3D Bottom view](./images/3D_BOT.png)
![PCB Top view](./images/PCB_TOP.png)
![PCB Bottom view](./images/PCB_BOT.png)
![PCB Schematic](./images/SCH.png)
 
# TODO
  * [Image converter](https://github.com/MakotoKurauchi/helix/tree/master/FontConverter)
  * [QMK](https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md)
  * [Troubleshooting guide](https://github.com/jpconstantineau/ErgoTravel/blob/master/Troubleshooting_steps.md)
  * [Inspirations](https://github.com/diimdeep/awesome-split-keyboards?tab=readme-ov-file)
  * Use [Lily58](https://github.com/kata0510/Lily58) way to reverse OLED connection
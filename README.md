<h1 align="center">
 <img src="./images/Logo/CorniaKey_PurpleBlack.svg" />
</h1>

# Cornia keyboard

<h1 align="center">
 <img src="./images/Cornia_v1.jpg" />
</h1>

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
    * [PCB Design](#pcb-design-and-manufacturing)
    * [Keyboard assembling](#keyboard-assembling)
    * [Troubleshooting](#troubleshooting)
  * [Software](#software)
    * [Cornia not yet integrated in official QMK ?](#cornia-not-yet-integrated-in-official-qmk)
    * [Keymap](#keymap)
  * [Case](#case)
  * [Photos](#photos)
<!--te-->

# Hardware

### Bill of material

| Name | Count | Remarks |
|:-|:-|:-|
| PCB | 2 | [PCB Ordering guide](./doc/pcb_ordering.md) |
| OLED Display | 2 | |
| [RP2040 ProMicro](https://keeb.io/products/rp2040-pro-micro-usb-c-controller) | 2 | Alternative: Refer to [Compatible controllers](#compatible-controllers) |
| TRRS 3.5mm jack | 2 | Ref: PJ-320A |
| Reset switch | 2 | SMD 4x4mm |
| I²C Pull-up resistors | 2 | 0805 form-factor and any value between 2.2kΩ and 4.7kΩ |
| Handedness Pull-up/down resistor | 1 | 0805 form-factor and any value between 2.2kΩ and 4.7kΩ |
| Hotswap sockets | 42 | Compatible with Kailh and Gateron |
| Key switches | 42 | Only compatible with MX style |
| Keycaps | 42 | 1u size |
| TRRS (4 poles) cable | 1 | |
| USB cable | 1 | USB Micro or USB-C depending on the controller, avoid charge-only cables |
| Case top | 2 | |
| Case bottom | 2 | |
| OLED Cover | 2 | |

### Compatible controllers

| Reference | I²C OLED Display | Handedness pin | Other features |
|:-|:-:|:-:|:-:|
| [RP2040 Aliexpress](https://fr.aliexpress.com/item/1005005980167753.html) | $${\color{green}✓}$$ | $${\color{green}✓}$$ | $${\color{green}✓}$$ |
| [RP2040 keeb.io](https://keeb.io/products/rp2040-pro-micro-usb-c-controller) | $${\color{green}✓}$$ | $${\color{green}✓}$$ | $${\color{green}✓}$$ |
| [0xCB-Helios](https://github.com/0xCB-dev/0xCB-Helios) | $${\color{green}✓}$$ | $${\color{green}✓}$$ | $${\color{green}✓}$$ |
| [Elite-Pi](https://docs.keeb.io/elite-pi-guide) | $${\color{red}⨯}$$ | $${\color{red}⨯}$$ | $${\color{green}✓}$$ |
| [RP Micro](https://github.com/siderakb/rp-micro) | $${\color{red}⨯}$$ | $${\color{red}⨯}$$ | $${\color{green}✓}$$ |

### PCB design and manufacturing

Schematic and PCB views are available in `pdf/`:
- [Schematic](pdf/SCH.pdf)
- [PCB Top view](pdf/PCB_TOP.pdf)
- [PCB Bottom view](pdf/PCB_BOT.pdf)

To manufacture the Cornia PCB please follow the [PCB manufacturing guide](./doc/pcb_ordering.md)

In case you want to modify the PCB please take a look at the following:
- KiCad [project description](./PCB/README.md)
- Export bash script to ease the process, it is documented in [Manufacturing files export guide](./doc/manufacturing_files_export.md)

### Keyboard assembling

To solder and assemble the Cornia keyboard please follow the [Cornia assembly guide](./doc/assembly_guide.md)

### Troubleshooting

[Troubleshooting guide](./doc/troubleshooting_pcb.md)

# Software

Cornia keyboard firmware is based on QMK.

### Cornia not yet integrated in official QMK ?

If Cornia keyboard not yet integrated in [qmk_firmware](https://github.com/qmk/qmk_firmware) you can go to [Vaarai QMK fork](https://github.com/Vaarai/qmk_firmware/tree/cornia/keyboards/cornia) on and follow the readme.

### Keymap

- [Default QWERTY layout for Cornia keyboard](https://www.keyboard-layout-editor.com/#/gists/5af136790cefe4b35cdf02ca52c1fccc)
- [Fire layout for Cornia keyboard](https://www.keyboard-layout-editor.com/#/gists/a40345c92e1f3f326426ef890ebf4d1c) (Based on [Fire (Oxey)](https://bit.ly/layout-doc-v2) layout)

# Case

Case for Cornia v1 is available on [Cornia v1 Printables](https://www.printables.com/model/958200-case-for-cornia-v1-including-a-trackpad-version-40) from user Rikiki, optionally including a trackpad version (40mm) available for both halves.

Cornia keyboard is a project initiated by a post from `help-forum` on [QMK Discord](https://discord.gg/qmk).

User Rikiki requested in this post if someone could alter [crkbd](https://github.com/foostan/crkbd) PCB to match his requirements.

I (Vaarai) replied to this post and in 1 months we made 2 iterations of crkbd variant and it diverged from crkbd in a way that we started to make a new keyboard and 5 months later it lead to the Cornia.

Rikiki made all the mechanical parts and I designed the PCB then developed a QMK implementation.

# Photos

![3D Top view](./images/3D_TOP.png)
![3D Bottom view](./images/3D_BOT.png)

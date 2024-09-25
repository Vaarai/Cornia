# Cornia Keyboard

![Cornia]()

A split keyboard with 3x6 column strongly staggered keys and 3 thumb keys

Keyboard Maintainer: [Vaarai](https://github.com/Vaarai) 
Hardware Supported: Cornia PCB, RP2040 / 0xCB-Helios
Hardware Availability: [PCB Data](https://github.com/Vaarai/Cornia)

Make example for this keyboard (after setting up your build environment):
```sh
    make cornia:default
```

Flashing example for this keyboard:
```sh
    make cornia:default:flash
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK ? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

The Cornia PCBs have a reset button on the bottom side near to the TRRS jack.

To enter in to the bootloader you can either:
- Hold reset when plugging in that half of the keyboard.
- Double press reset if firmware was already flashed and if RP2040 is used
- Press NAV+NUM+ESC if firmware was already flashed no matter what controller is used

## Disable RGB Matrix

The Corne Keyboard use the RGB Matrix feature by default. To disable it please make with the following command:
```sh
    make cornia/v1_no_led:default
```

And flash with:
```sh
    make cornia/v1_no_led:default:flash
```

## OLED Display & Cirque Trackpad

The Corne Keyboard also support OLED Display and Cirque Trackpad through I²C, an implementation is available in `fire` keymap.

To use it please make with the following command:
```sh
    make cornia:fire
```

And flash with:
```sh
    make cornia:fire:flash
```
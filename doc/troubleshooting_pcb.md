# PCB troubleshooting guide

## Prerequisites

- Multimeter with continuity tester
- [PCB Schematic](../pdf/SCH.pdf)
- Patience !

## A key is not working

If one or more keys are not working:

```mermaid
flowchart LR
    EXTRACT_SWITCH[Extract concerned switch]
    EXTRACT_SWITCH --> CHECK_PIN{Is switch pin bent}
    CHECK_PIN -- Bent --> FIX_BENT[Fix bent pin]
    CHECK_PIN -- Pin OK --> CHANGE_SWITCH[Change the switch]
    CHANGE_SWITCH --> CHECK_HOTSWAP{"Reflow (re-solder) socket"}
    CHECK_HOTSWAP -- Solved by reflow --> OK[OK]
    CHECK_HOTSWAP -- Still not working --> TICKET[Really ? open an issue]
```

## Multiple keys are registered when a single one is pressed

If two or more keys are registered when a single one is pressed it can be one of the followings:

- Cheap grab bag kecaps. The keycaps have some plastic injection points that protrude under the next keycap. When pressing the key, the small plastic tab is long/big enough to get caught under and force the second key to go down as well. Remove the keycap and cut the protruding plastic tab and re-install.
- A short between two controller pins. Check the soldering on the controller pins and verify that adjacent pins don't have continuity. If this is the case, remove solder from these pins and re-check for a short.

## A led is not working

If one or more leds are not working:

```mermaid
flowchart LR
    ONLY_ONE{Only one led's not working ?}
    ONLY_ONE -- Yes --> REPLACE_FAULTY["Replace the faulty led(s)"]
    ONLY_ONE -- No --> OPEN_SCH[Open the schematic and\nidentify faulty leds numbers]
    OPEN_SCH --> IS_IN_ORDER{What numbers isn't working ?}
    IS_IN_ORDER -- Random --> REPLACE_FAULTY
    IS_IN_ORDER -- From one number up to the last --> REPLACE_FIRST{Replace the lowest numbered faulty led}
    REPLACE_FIRST -- Solved --> OK[OK]
    REPLACE_FIRST -- Still not working --> ONLY_ONE
```


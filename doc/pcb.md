### Export DXF for laser cutted case

Kicad layers `User.8` & `User.9` are respectively used in cornia footprint/pcb to export DXF for a laser cutted case.
Kicad-CLI can be found at `C:\Program Files\KiCad\8.0\bin`

``` bash
mkdir case
kicad-cli pcb export dxf -o case/LaserCut.TOP.dxf -l User.8 --ou mm cornia.kicad_pcb
kicad-cli pcb export dxf -o case/LaserCut.BOT.dxf -l User.9 --ou mm cornia.kicad_pcb
```
For more info about kicad-CLI please read the [documentation](https://docs.kicad.org/8.0/en/cli/cli.html)

### Export Gerber for JLCPCB

``` bash
mkdir gerber
kicad-cli pcb export gerbers -o gerber/ -l F.Cu,B.Cu,F.Paste,B.Paste,F.Silkscreen,B.Silkscreen,F.Mask,B.Mask,Edge.Cuts --exclude-value --no-x2 --no-netlist --subtract-soldermask cornia.kicad_pcb
kicad-cli pcb export drill -o gerber/ --format excellon --excellon-separate-th --generate-map --map-format gerberx2 cornia.kicad_pcb
```

## Fabrication files export
### Export DXF for laser cutted case

PCB layers `User.8` & `User.9` are respectively used in cornia footprint & pcb to export DXF for a laser cutted case using [Kicad-CLI](https://docs.kicad.org/8.0/en/cli/cli.html).

Kicad-CLI executable can be found at `C:\Program Files\KiCad\8.0\bin`.

``` bash
mkdir case
kicad-cli pcb export dxf -o case/LaserCut.TOP.dxf -l User.8 --ou mm cornia.kicad_pcb
kicad-cli pcb export dxf -o case/LaserCut.BOT.dxf -l User.9 --ou mm cornia.kicad_pcb
```

### Export Gerber for JLCPCB

Based on JLCPCB [kicad export](https://jlcpcb.com/help/article/362-how-to-generate-gerber-and-drill-files-in-kicad-8) recommendations & [Kicad-CLI](https://docs.kicad.org/8.0/en/cli/cli.html) the following commands allow to export all gerber files (including Drill/Map files).

``` bash
mkdir gerber
kicad-cli pcb export gerbers -o gerber/ -l F.Cu,B.Cu,F.Paste,B.Paste,F.Silkscreen,B.Silkscreen,F.Mask,B.Mask,Edge.Cuts --exclude-value --no-x2 --no-netlist --subtract-soldermask cornia.kicad_pcb
kicad-cli pcb export drill -o gerber/ --format excellon --excellon-separate-th --generate-map --map-format gerberx2 cornia.kicad_pcb
```

### Full script to be pasted in terminal
``` bash
mkdir -p gerber case && \
kicad-cli pcb export dxf -o case/LaserCut.TOP.dxf -l User.8 --ou mm cornia.kicad_pcb && \
kicad-cli pcb export dxf -o case/LaserCut.BOT.dxf -l User.9 --ou mm cornia.kicad_pcb && \
kicad-cli pcb export gerbers -o gerber/ -l F.Cu,B.Cu,F.Paste,B.Paste,F.Silkscreen,B.Silkscreen,F.Mask,B.Mask,Edge.Cuts --exclude-value --no-x2 --no-netlist --subtract-soldermask cornia.kicad_pcb && \
kicad-cli pcb export drill -o gerber/ --format excellon --excellon-separate-th --generate-map --map-format gerberx2 cornia.kicad_pcb
```
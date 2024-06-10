# Manufacturing files export

To ease the manufacturing files export from Kicad this process is automated using [export_fab_output.sh](../export_fab_output.sh) bash script.

This script perform 5 actions:
- Check PCB DRC (DRC report is saved [here](../PCB/cornia-drc.report))
- Export .dxf files for laser cutted case
- Export .step model of the PCB and assembled components
- Export .pdf of schematic, PCB Top and Bottom views 
- Export gerber, drill & map files for PCB manufacturing

To run this script on Windows it is necessary to have [git-bash](https://www.git-scm.com/download/win).

On Linux this script need to be updated to call the kicad-cli binary instead of the .exe expected on Windows.

It may be necessary to add execution right to the script by running `chmod +x export_fab_output.sh`

> **&#9432;**  Kicad 8 or later is mandatory to use the export in CLI 

## Design Rules Check (DRC)

DRC is a mandatory step before any file exportation to ensure the design rules compliancy

```bash
kicad-cli pcb drc -o cornia-drc.report --all-track-errors --schematic-parity --severity-error --severity-warning --exit-code-violations cornia.kicad_pcb
```

## Export Schematic and PCB top and bottom views 

Schematic and PCB views are useful for the  review process and can be exported using the following command

``` bash
kicad-cli sch export pdf -o pdf/SCH.pdf cornia.kicad_sch && \
kicad-cli pcb export pdf -o pdf/PCB_TOP.pdf -l F.Cu,F.Paste,F.Silkscreen,F.Mask,Edge.Cuts --exclude-value cornia.kicad_pcb && \
kicad-cli pcb export pdf -o pdf/PCB_BOT.pdf -l B.Cu,B.Paste,B.Silkscreen,B.Mask,Edge.Cuts --exclude-value cornia.kicad_pcb
```

## Export DXF for laser cutted case

PCB layers `User.8` & `User.9` are respectively used in cornia footprint & pcb to export DXF for a laser cutted case using the following command

``` bash
kicad-cli pcb export dxf -o case/LaserCut.TOP.dxf -l User.8 --ou mm cornia.kicad_pcb
kicad-cli pcb export dxf -o case/LaserCut.BOT.dxf -l User.9 --ou mm cornia.kicad_pcb
```

## Export `.step` 3D model

PCB and assembled components are 3D modeled and can be exported in step format using the following command

```bash
kicad-cli pcb export step -o case/PCB.step --subst-models cornia.kicad_pcb
```

## Export Gerber for JLCPCB

Based on JLCPCB [kicad export](https://jlcpcb.com/help/article/362-how-to-generate-gerber-and-drill-files-in-kicad-8) recommendations & [Kicad-CLI](https://docs.kicad.org/8.0/en/cli/cli.html) the following commands allow to export all gerber files (including Drill/Map files).

``` bash
kicad-cli pcb export gerbers -o gerber/ -l F.Cu,B.Cu,F.Paste,B.Paste,F.Silkscreen,B.Silkscreen,F.Mask,B.Mask,Edge.Cuts --exclude-value --no-x2 --no-netlist --subtract-soldermask cornia.kicad_pcb
kicad-cli pcb export drill -o gerber/ --format excellon --excellon-separate-th --generate-map --map-format gerberx2 cornia.kicad_pcb
```
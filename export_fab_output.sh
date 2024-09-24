#!/bin/bash

# Copyright 2024 Vaarai
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

FOLDER_PCB=PCB
FOLDER_CASE=case
FOLDER_GERBER=gerber
FOLDER_PDF=pdf

# Check PCB DRC and abort execution in case of DRC failure
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe pcb drc -o $FOLDER_PCB/cornia-drc.report --all-track-errors --schematic-parity --severity-error --severity-warning --exit-code-violations $FOLDER_PCB/cornia.kicad_pcb
if [ $? -eq 5 ]
then
    echo "DRC FAIL : Exit"
    exit 1 
fi

mkdir -p $FOLDER_GERBER $FOLDER_CASE && \

# Export PCB and Schematic view in pdf
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe sch export pdf -o $FOLDER_PDF/SCH.pdf $FOLDER_PCB/cornia.kicad_sch && \
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe pcb export pdf -o $FOLDER_PDF/PCB_TOP.pdf -l F.Cu,F.Paste,F.Silkscreen,F.Mask,Edge.Cuts --exclude-value $FOLDER_PCB/cornia.kicad_pcb && \
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe pcb export pdf -o $FOLDER_PDF/PCB_BOT.pdf -l B.Cu,B.Paste,B.Silkscreen,B.Mask,Edge.Cuts --exclude-value $FOLDER_PCB/cornia.kicad_pcb

# Export laser cutted case dxf
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe pcb export dxf -o $FOLDER_CASE/LaserCut.TOP.dxf -l User.8 --ou mm $FOLDER_PCB/cornia.kicad_pcb && \
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe pcb export dxf -o $FOLDER_CASE/LaserCut.BOT.dxf -l User.9 --ou mm $FOLDER_PCB/cornia.kicad_pcb

# Export .step 3D model
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe pcb export step -o $FOLDER_CASE/PCB.step --subst-models $FOLDER_PCB/cornia.kicad_pcb

# Export gerber folder
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe pcb export gerbers -o $FOLDER_GERBER/ -l F.Cu,B.Cu,F.Paste,B.Paste,F.Silkscreen,B.Silkscreen,F.Mask,B.Mask,Edge.Cuts --exclude-value --no-x2 --no-netlist --subtract-soldermask $FOLDER_PCB/cornia.kicad_pcb && \
C:/Program\ Files/KiCad/8.0/bin/kicad-cli.exe pcb export drill -o $FOLDER_GERBER/ --format excellon --excellon-separate-th --generate-map --map-format gerberx2 $FOLDER_PCB/cornia.kicad_pcb
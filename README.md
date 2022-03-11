# Simple-AI-Simulation
This is a program desgined for a workshop, containing a simple simulation of an AI. 
The program itself is located inside the release folder. 

## How to use
To use this program, make sure to be on a windows version that supports x86, find folder Simulation-vX (X marks a version number, take the highest one). Copy that folder to a location on your computer. Inside that folder will be a file called ai-robot (or ai-robot.exe), run that to start the program. In the same folder will be located a text file called settings (or settings.txt), change text in there to make changes to the program, make sure to save and follow the instruction marked on the top.

## How to modify the code
The program is made with c++ in windows 11 using the IDE visual studio 2022 and the package manager vcpkg. 

If you wanna continue development on this program download the zip folder and open the solution located in the ai-robot folder.
The program uses the SFML library as its graphics API, so that will need to be used. For the current state of development, the
package manager vcpkg has been used.

To use the package manager, install it via: https://vcpkg.io/en/index.html
Follow the installation guide, and afterwards type in:

- vcpkg install sfml
- vcpkg integrate install

Afterwards SFML should be working in visual studio, and you are ready to begin working. 


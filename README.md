# BusInquiry
The course project on Qt about data structure. The goal is to practice how to efficiently use ready-made data structures and algorithms (STL), but it also involves writing one’s own efficient algorithms and estimating their performance.   

## Topic
This project honors the near completion of the Tampere tram project in spring, 2020. The first phase is to create a program which can tell information about bus stops and regions related to them (suburbs, municipalities, price zones, etc.). In the second phase the program will be extended to also include bus routes and allow bus journey searches.

## Terminology
- **Stop**. Every bus stop has a unique integer ID, name (which consists of characters A-Z, a-z, 0-9, space, and dash -) and location (x,y).

- **Region**. Every bus stop can belong to at most one region. Additionally each region can contain an arbitrary number of (sub)subregions, so that every region can belong to at most one “upper” region. Each region has a unique ID ( which consists of characters A-Z, a- z, 0-9) and a name (which consists of characters A-Z, a-z, 0-9, space, and dash -). 

## Files
Short explanation of test files:
- Files named "...-in.txt" are input files containing commands for different tests.
- Files named "...-out.txt" are output files containing expected output of the corresponding input.

Files named "perftest-....txt" are performance tests of various types of operations. They can be run with command read "perftest-....txt".

## Test the program
The easiest way to test the program is to create "data files", which can add a bunch of stops and regions. For example, *example-stops.txt*

add_stop 1 One (1,1)  
add_stop 2 Two (6,2)   
add_stop 3 Three (0,6)   
add_stop 4 Four (7,7)     
add_stop 5 Five (4,4)   
add_stop 6 Six (2,9)

This's a screenshot of the graphical user interface after *example-stops.txt* and *example-regions.txt* have been read in.
![example_stops](/src/prg1_GUI.png)

This's a screenshot of the graphical user interface after *example-stops.txt* and *example-regions.txt* have been read in.
![example_stops](/src/prg2_GUI.png)




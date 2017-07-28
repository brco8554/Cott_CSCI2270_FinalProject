PROJECT SUMMARY:
    This program functions by creating a graph of a country, connecting the 
vertices of the country, then filling each city with its corresponding population.
From there, a main menu is created, which allows the user, (the dictator), to
perform many actions to the country. These actions consist of: 1. Selecting a city
to observe, 2. Viewing all of the available cities, 3. Viewing all of the citizens
in a selected city, 4. Execute a chosen citizen from the selected city, 5. Add a
citizen to the chosen city, 6. Glass a city (execute all citizens in the city),
7. Relocate a citizen from one city to another, and 8. Relocate an entire city
of civilians to another city. The citizens are organized into a red black tree,
so that they can be quicker accessed for easier manipulation.




HOW TO RUN:
This program is extremely simple to run, simply open the terminal, navigate to the
folder that the files are located in, and type "./Dictator". From there, a menu
is displayed that will make running individual choices within the program easy.
Simply enter the number corresponding to the command to be implemented, and then
follow the prompts displayed by the code.

for example, after running, the following was performed. User input is shown
with the trailing "***************":
======Main Menu======
1. Select city
2. List all cities
3. List populace
4. Execute citizen
5. Add citizen
6. Glass city
7. Relocate citizen
8. Relocate population
9. Quit
======Current City======
Cudset | Population: 2
======Adjacent Cities======
Creabury | Population: 20
Phiobrence | Population: 8
2 ***************************************************************************
======All Cities======
Cudset | Population: 2
Heofding | Population: 7
Eajumro | Population: 3
Krada | Population: 6
Crul | Population: 4
Phiobrence | Population: 8
Gugence | Population: 15
Creabury | Population: 20
Izatta | Population: 1
Strago | Population: 5
======Main Menu======
1. Select city
2. List all cities
3. List populace
4. Execute citizen
5. Add citizen
6. Glass city
7. Relocate citizen
8. Relocate population
9. Quit
======Current City======
Cudset | Population: 2
======Adjacent Cities======
Creabury | Population: 20
Phiobrence | Population: 8
1 ***************************************************************************
Enter city name:
Gugence *********************************************************************
======Main Menu======
1. Select city
2. List all cities
3. List populace
4. Execute citizen
5. Add citizen
6. Glass city
7. Relocate citizen
8. Relocate population
9. Quit
======Current City======
Gugence | Population: 15
======Adjacent Cities======
Eajumro | Population: 3
Izatta | Population: 1
Crul | Population: 4
Krada | Population: 6
3 ***************************************************************************
Citizen: Atton Rand | Hair: brown | Eyes: brown
Citizen: Bao-Dur | Hair: none | Eyes: brown
Citizen: Bastila Shan | Hair: brown | Eyes: blue
Citizen: Brianna | Hair: grey | Eyes: blue
Citizen: Canderous Ordo | Hair: grey | Eyes: blue
Citizen: Carth Onasi | Hair: brown | Eyes: brown
Citizen: G0-T0 | Hair: none | Eyes: yellow
Citizen: HK-47 | Hair: none | Eyes: yellow
Citizen: Jolee Bindo | Hair: none | Eyes: brown
Citizen: Kreia | Hair: grey | Eyes: black
Citizen: Mira | Hair: red | Eyes: green
Citizen: Mission Vao | Hair: none | Eyes: blue
Citizen: T3-M4 | Hair: none | Eyes: blue
Citizen: Visas Marr | Hair: black | Eyes: black
Citizen: Zaalbar | Hair: brown | Eyes: brown
======Main Menu======
1. Select city
2. List all cities
3. List populace
4. Execute citizen
5. Add citizen
6. Glass city
7. Relocate citizen
8. Relocate population
9. Quit
======Current City======
Gugence | Population: 15
======Adjacent Cities======
Eajumro | Population: 3
Izatta | Population: 1
Crul | Population: 4
Krada | Population: 6
6 ***************************************************************************
Enter city name:
Creabury ********************************************************************
You fire a nuclear missile at Creabury
Nuclear fallout has killed: Aku Aku from Creabury
Nuclear fallout has killed: Crash Bandicoot from Creabury
Nuclear fallout has killed: Coco Bandicoot from Creabury
Nuclear fallout has killed: Dingodile from Creabury
Nuclear fallout has killed: Koala Kong from Creabury
Nuclear fallout has killed: Madame Amberly from Creabury
Nuclear fallout has killed: Fake Crash from Creabury
Nuclear fallout has killed: N. Gin from Creabury
Nuclear fallout has killed: N. Tropy from Creabury
Nuclear fallout has killed: N. Trance from Creabury
Nuclear fallout has killed: N. Brio from Creabury
Nuclear fallout has killed: Nina Cortex from Creabury
Nuclear fallout has killed: Pinstripe Potoroo from Creabury
Nuclear fallout has killed: Papu Papu from Creabury
Nuclear fallout has killed: Tawna Bandicoot from Creabury
Nuclear fallout has killed: Uka Uka from Creabury
Nuclear fallout has killed: Tiny Tiger from Creabury
Nuclear fallout has killed: Ripper Roo from Creabury
Nuclear fallout has killed: Neo Cortex from Creabury
Nuclear fallout has killed: Crunch Bandicoot from Creabury
======Main Menu======
1. Select city
2. List all cities
3. List populace
4. Execute citizen
5. Add citizen
6. Glass city
7. Relocate citizen
8. Relocate population
9. Quit
======Current City======
Creabury | Population: 0
======Adjacent Cities======
Cudset | Population: 2
Heofding | Population: 7
Strago | Population: 5
Krada | Population: 6





DEPENDENCIES:

This program has no dependencies on any external libraries.




SYSTEM REQUIREMENTS: 

This program will run on Linux, and it shoudl function on Macs, although it has
not been tested on any system other than Linux.




Brandon Cott




OPEN ISSUES / BUGS

Currently, there are some bugs with performing actions on cities that have a
population of zero. It was also planned that cities with a zero population were
to be removed from the graph, and the adjacent cities were to be connected to
each other, but there were too many errors associated with this. There was also
to be a function that could select citizens based on their hair and eye color,
but this idea was scrapped due to a lack of time.
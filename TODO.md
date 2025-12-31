# Version 1 TODO:
[X] Read and convert data from DHT20
[ ] Solder pinheads for the components that were not pre-soldered
[X] Read and convert data from BH1750
[X] Log data to a memory card
[ ] Send data from memory card to csv file 
[ ] Button to start / stop logging data

# Version 2 TODO:
[ ] Display both sensor results on an OLED screen
[ ] Buttons to switch display
[ ] Add power source (battery)
[ ] Activate sleep mode when not in use
[ ] Add lever to turn on and off device
[ ] Switch nucleo board for another MCU
[ ] Add RTC timestamps

# Version 3 TODO;
[ ] Design the enclosure
[ ] Solder everything together (custom PCB)
[ ] CRUD website to also display data (if time permits)


# Consider if possible:
- Way for system to self correct crc check fails
- Display results on graph (csv -> python)
- Implementing RTOS somewhere (only if actually useful)
- Way to change how often data is read
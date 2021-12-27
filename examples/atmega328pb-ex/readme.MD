# Requirements
* Microchip Studio
* Atmega328pb ( with clock of 16MHZ )
* Keypad 4x4
* FTDI

<img src="https://d2vlcm61l7u1fs.cloudfront.net/media%2Fed9%2Fed98eb2a-0297-4171-96a1-8b1710d22608%2Fphp4GlyxC.png" width="75%"> </img>
# Wiring

| keypad 4x4 | pin |
|------|------|
| column 1 | d3 |
| column 2 | d2 |
| column 3 | b1 |
| column 4 | b0 |
| row 1 | d7 |
| row 2 | d6 |
| row 3 | d5 |
| row 4 | d4 |

| FTDI | pin |
|------|------|
| rx | d1 |
| gnd | gnd |

# How to use it
* Make wire connections: FTDI , keypad and atmega328pb
* Connect FTDI to host PC and open serial monitor
* Import project in Microchip Studio
* Build and upload to atmega328pb using a programmer like "ATMEL ICE"
* Check results in serial monitor

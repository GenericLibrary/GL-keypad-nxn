## TEST SUB-DIRECTORY WORKS LIKE ANOTHER PROJECT

# Wiring
| keypad 4x4 | gpio |
|------|------|
| column 1 | 15 |
| column 2 | 23 |
| column 3 | 4 |
| column 4 | 5 |
| row 1 | 18 |
| row 2 | 19 |
| row 3 | 21 |
| row 4 | 22 |

# Requirements
* ESP-IDF: 4.3.1
* ESP32
* Keypad 4x4

# How to use it
* Make steps descripted above
* Open ESP-IDF environment on terminal
* Go to project root directory
* Build: 
```
idf.py build
```
* Flash and monitor: x = port (ex: COM5)
```
idf.py flash monitor -p x
```
* Follow instructions on the monitor to check if the keypad works
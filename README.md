# S3GA
an FPGA board based on the ICE40UP5K and the ESP32S3-Mini (module). 

Allows for wireless functionality (maybe even programming?) using the ESP32S3-M and IO using the iCE

## Why?
- i wasn't able to find any boards that integrated wireless functionality with the ICE40UP5K, so i decided to make one!

# Setup
None as such, apart from assembly

# Usage
- the S3 can be developed for using Arduino / ESP-IDF and programmed with the respective tools
- the iCE can be developed with iCEcube2 and programmed using the Diamond Programmer. To flash use [SPIFFS](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/storage/spiffs.html) to create a file for the generated bitstream, and then use the [flash code](Firmware/mcu-flash)

# Pinout
[Pinout](Images/pinout.png)

[Model](Images/front.png)

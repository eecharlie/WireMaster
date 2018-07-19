# WireMaster
Arduino Wire drop-in replacement wrapper for pfleury's i2cmaster library.


Sometimes the Arduino I2C/SMBus/TwoWire library has strange failures, and this may depend on its use of specialized hardware on the MCU, including an interrupt. For master-mode-only applications, pfluery's minimal i2c master library written in assembly depends on no chip hardware features except the CPU clock. It may be preferable to reduce memory usage to work around odd failures.

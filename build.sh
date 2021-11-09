#!/bin/bash
sdcc main.c -o /tmp/main.ihx
packihx /tmp/main.ihx > /tmp/main.hex
stcflash /tmp/main.hex

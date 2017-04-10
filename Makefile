# Author: Jarid Bredemeier
# Date: Thursday, February 2, 2017
# File: Makefile.mak
# Copyright © 2017 All rights reserved 

CFLAGS = -O2
TARGET = main

all: $(TARGET)
	
debug: CFLAGS += -g
debug: all
	
clean:
	rm *.exe
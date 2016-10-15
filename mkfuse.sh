#!/bin/sh 
sudo umount mnt 

g++ fuse/*.cpp include/*.h src/commands.cpp src/node.cpp src/memory.cpp  -o mifuse  -D_FILE_OFFSET_BITS=64 -lfuse -w

./mifuse mnt 

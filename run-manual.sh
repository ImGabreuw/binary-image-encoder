#!/bin/bash

clear && gcc -o main $(find . -name "*.c") -lm && ./main -m < input.txt
#!/bin/bash

set -xe

gcc main.c -o gen -Wall -Werror -std=c11 -pedantic -ggdb -lm

./gen

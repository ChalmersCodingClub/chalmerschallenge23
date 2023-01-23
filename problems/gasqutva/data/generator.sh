#!/usr/bin/env bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

compile gen.py

sample 1

tc t01 gen N=2
tc t02 gen N=3
tc t03 gen N=4
tc t04 gen N=5
tc t05 gen N=6
tc t06 gen N=100
tc t07 gen N=10000
tc t08 gen N=100000
tc t09 gen N=100000

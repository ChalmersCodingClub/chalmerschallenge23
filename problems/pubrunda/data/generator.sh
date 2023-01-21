#!/usr/bin/env bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

compile gen.py

sample 1

tc t01 gen N=10 maxtk=0
tc t02 gen N=10 maxtk=1
tc t03 gen N=10 maxtk=1000
tc t04 gen N=10 maxtk=10000

tc t05 gen N=1 maxtk=100

tc t06 gen N=100000 maxtk=0
tc t07 gen N=100000 maxtk=3
tc t08 gen N=100000 maxtk=10000

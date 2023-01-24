#!/usr/bin/env bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

compile gen.py

sample 1

tc t01 gen N=2 type=rnd
tc t02 gen N=3 type=rnd
tc t03 gen N=4 type=rnd
tc t04 gen N=5 type=rnd
tc t05 gen N=6 type=rnd
tc t06 gen N=100 type=rnd
tc t07 gen N=10000 type=rnd
tc t08 gen N=100000 type=rnd
tc t09 gen N=100000 type=rnd

tc t10 gen N=100000 type=line
tc t11 gen N=100000 type=line

tc t12 gen N=100000 type=star
tc t13 gen N=100000 type=star

tc t14 gen N=100000 type=starline
tc t15 gen N=100000 type=starline
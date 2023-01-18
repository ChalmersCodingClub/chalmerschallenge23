#!/usr/bin/env bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

use_solution loke.py

compile gen.py

sample 1

tc t01 gen
tc t02 gen
tc t03 gen
tc t04 gen
tc t05 gen
tc t06 gen
tc t07 gen
tc t08 gen
tc t09 gen
tc t10 gen
tc t11 gen
tc t12 gen
tc t13 gen
tc t14 gen
tc t15 gen
tc t16 gen
tc t17 gen
tc t18 gen
tc t19 gen
tc t20 gen
tc t21 gen
tc t22 gen
tc t23 gen

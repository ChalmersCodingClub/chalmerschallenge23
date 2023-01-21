#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

compile gen.py

samplegroup
limits nMax=10 hMax=10
sample 1

group group1 50
limits nMax=100 hMax=1000000000
tc 1
tc g1_1 gen n=5 k=2 hMax=10
tc g1_2 gen n=100 k=2 hMax=10

group group2 50
limits nMax=100 hMax=1000000000
include_group group1
tc g2_1 gen n=5 k=3 hMax=10
tc g2_2 gen n=100 k=30 hMax=10
tc g2_3 gen n=100 k=80 hMax=100

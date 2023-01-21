#include "validator.h"

void run() {
    int n = Int(2, 100000);
    Endl();
    for (int i = 0; i < n; ++i) {
        Int(0, 1000000000);
        Endl();
    }
    for (int i = 0; i < n - 1; ++i) {
        int a = Int(1, n);
        Space();
        int b = Int(1, n);
        Endl();
        if (a == b) die(to_string(a) + " and " + to_string(b) + " are the same person!");
    }
}
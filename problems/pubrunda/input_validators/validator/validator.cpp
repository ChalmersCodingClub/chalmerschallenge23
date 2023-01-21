#include "validator.h"

void run() {
    int n = Int(0, 100000);
    Endl();
    for (int i = 0; i < n; ++i) {
        string pubname;
        cin >> pubname;
        if (pubname.length() > 10) die("Pub name " + pubname + " too long!");
        Space();
        int k = Int(0, 10000);
        Space();
        int t = Int(0, 10000);
        Endl();
    }
}
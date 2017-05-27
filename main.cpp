#include <iostream>
#include <cmath>
#include "hashtable.h"

using namespace std;

using namespace ramon_petgrave_hashtable;

int main() {
    srand(time(0));

    bool b = true;
    while(b) {
        hashtable<int> t;
        int n = 8;
        for (int i = 0; i < 1000; i++) {
            int key = rand() % n;
            int value = rand() % n;
            t.put(key, value);
        }
        //cout << t << endl;
    }
    return 0;
}
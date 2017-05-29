#include <iostream>
#include "hashtable.h"
#include "hash_container.h"

using namespace std;

using namespace ramon_petgrave_hashtable;

int main() {
/*    srand(time(0));

    bool b = true;
    while(b) {
        hashtable<int> t;
        int n = 8;
        for (int i = 0; i < 100; i++) {
            int key = rand() % n;
            int value = rand() % n;
            t.put(key, value);
        }
        //cout << t << endl;
        //b = false;
    }*/

    srand(time(0));
    hashtable<int> t;
    int n = 16;
    for (int i = 0; i < 128; i++) {
        int key = rand() % n;
        int value = rand() % n;
        t.put(key, value);
    }
    cout << t << endl;

    while (t.size() > 0) {
        t.remove(t.top_key());
    }
    cout << endl << t << endl;

    return 0;
}
//
// Created by Ramon Petgrave on 5/28/17.
//

#ifndef HASH_TABLE_HASH_CONTAINER1_H
#define HASH_TABLE_HASH_CONTAINER1_H

#include <cstdlib>

namespace ramon_petgrave_hashtable {
    template <class Item>
    class hash_container {
    protected:
        size_t num_items;
    public:
        hash_container() {
            num_items = 0;
        }
        virtual ~hash_container() {};
        virtual void put(int key, const Item& value) =0;
        virtual Item& get(int key) =0;
        virtual void remove(int key) =0;
        virtual int top_key() =0;
        size_t size() {
            return num_items;
        }
        virtual void print(std::ostream& os) =0;
        friend std::ostream &operator<<(std::ostream &os, hash_container<Item> &container) {
            container.print(os);
            return os;
        }
    };
}

#endif //HASH_TABLE_HASH_CONTAINER1_H

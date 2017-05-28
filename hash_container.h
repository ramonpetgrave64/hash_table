//
// Created by Ramon Petgrave on 5/28/17.
//

#ifndef HASH_TABLE_HASH_CONTAINER_H
#define HASH_TABLE_HASH_CONTAINER_H

#include <cstdio>

namespace ramon_petgrave_hashtable {
    template <class Item>
    class hash_container {
    protected:
        size_t num_items;
    public:
        virtual hash_container() {
            num_items = 0;
        }
        //virtual ~hash_container();
        virtual void put(int key,const Item& value);
        virtual Item& get(int key);
        virtual void remove(int key);
        size_t size() {
            return num_items;
        }
    };
}

#endif //HASH_TABLE_HASH_CONTAINER_H

//
// Created by Ramon Petgrave on 5/20/17.
//

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

#include <cstdlib>
#include <iostream>
#include "hash_bucket.h"

namespace ramon_petgrave_hashtable {
    size_t DEFAULT_SIZE = 20;
    template <class Item>
    class hashtable : public hash_container<Item>{
        private:
            size_t table_size;
            hash_bucket<Item>** buckets;
            size_t used_indexes;
            size_t hash_value(int key); // returns (index = key%size)
            double rehash__threshold = 0.75;
        public:
            hashtable(size_t size = DEFAULT_SIZE); //initial size of the array hashtable
            ~hashtable();
            void put(int key,const Item& value); //index = key%size; put value into the index
            Item& get(int key); // return the value at the key
            int top_key();
            void remove(int key); //remove value at the key,
            void rehash(); //doubles the table_size and reorganizes
            void print(std::ostream& os);
    };
};
#include "hashtable.template"

#endif //HASH_TABLE_HASH_TABLE_H
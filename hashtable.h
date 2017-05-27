//
// Created by Ramon Petgrave on 5/20/17.
//

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

#include <cstdlib>
#include <iostream>
#include "hash_bucket.h"

using std::ostream;

namespace ramon_petgrave_hashtable {
    size_t DEFAULT_SIZE = 20;
    template <class Item>
    class hashtable {
        private:
            size_t table_size;
            hash_bucket<Item>* buckets;
            size_t used_indexes;
            size_t hash_value(int key); // returns (index = key%size)
            size_t num_items;
            double rehash__threshold = 0.75;
        public:
            hashtable(size_t size = DEFAULT_SIZE); //initial size of the array hashtable
            ~hashtable();
            size_t size() const; //returns table_size
            size_t get_used_indexes() const;
            void put(int key,const Item& value); //index = key%size; put value into the index
            Item& get(int key); // return the value at the key
            void remove(int key); //remove value at the key,
            void rehash(); //doubles the table_size and reorganizes
            friend ostream &operator<<(ostream &os, hashtable<Item>& ht) {
                os << "{HT: " << endl;
                if (ht.used_indexes > 0) {
                    size_t count = 0;
                    for (size_t i = 0; (count < ht.used_indexes) && (i < ht.table_size); i++) {
                         if(ht.buckets[i].size() > 0) {
                             os << i << ": " << ht.buckets[i];
                             count++;
                             if (count < ht.used_indexes) {
                                 os << ",";
                             }
                             os << endl;
                         }
                    }
                }
                os << "}";
                return os;
            }
    };
    template<class Item>
    ostream &operator<<(ostream &os, hashtable<Item>& ht);
};
#include "hashtable.template"

#endif //HASH_TABLE_HASH_TABLE_H
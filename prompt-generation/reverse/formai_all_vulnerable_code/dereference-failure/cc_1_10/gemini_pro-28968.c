//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Create a bucket
struct bucket {
    int value;
    struct bucket *next;
};

// Create a hash table
struct hash_table {
    int size;
    struct bucket **table;
};

// Create a new bucket
struct bucket *create_bucket(int value) {
    struct bucket *new_bucket = (struct bucket *)malloc(sizeof(struct bucket));
    new_bucket->value = value;
    new_bucket->next = NULL;
    return new_bucket;
}

// Create a new hash table
struct hash_table *create_hash_table(int size) {
    struct hash_table *new_hash_table = (struct hash_table *)malloc(sizeof(struct hash_table));
    new_hash_table->size = size;
    new_hash_table->table = (struct bucket **)malloc(sizeof(struct bucket *) * size);
    for (int i = 0; i < size; i++) {
        new_hash_table->table[i] = NULL;
    }
    return new_hash_table;
}

// Insert a value into a bucket
void insert_value(struct hash_table *hash_table, int value) {
    int index = value % hash_table->size;
    struct bucket *bucket = hash_table->table[index];

    if (bucket == NULL) {
        hash_table->table[index] = create_bucket(value);
    } else {
        while (bucket->next != NULL) {
            bucket = bucket->next;
        }
        bucket->next = create_bucket(value);
    }
}

// Sort the values in the hash table
void sort_values(struct hash_table *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        struct bucket *bucket = hash_table->table[i];

        while (bucket != NULL) {
            int value = bucket->value;

            // Insert the value into the sorted list
            struct bucket *sorted_list = hash_table->table[0];
            while (sorted_list->next != NULL) {
                if (value < sorted_list->next->value) {
                    break;
                }
                sorted_list = sorted_list->next;
            }

            if (sorted_list->next == NULL) {
                bucket->next = NULL;
                sorted_list->next = bucket;
            } else {
                bucket->next = sorted_list->next;
                sorted_list->next = bucket;
            }

            bucket = bucket->next;
        }
    }
}

// Print the values in the hash table
void print_values(struct hash_table *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        struct bucket *bucket = hash_table->table[i];

        while (bucket != NULL) {
            printf("%d ", bucket->value);
            bucket = bucket->next;
        }
    }
    printf("\n");
}

int main() {
    // Create a hash table
    struct hash_table *hash_table = create_hash_table(10);

    // Insert some values into the hash table
    insert_value(hash_table, 10);
    insert_value(hash_table, 5);
    insert_value(hash_table, 15);
    insert_value(hash_table, 2);
    insert_value(hash_table, 7);
    insert_value(hash_table, 12);
    insert_value(hash_table, 18);
    insert_value(hash_table, 3);
    insert_value(hash_table, 8);
    insert_value(hash_table, 13);

    // Sort the values in the hash table
    sort_values(hash_table);

    // Print the values in the hash table
    print_values(hash_table);

    return 0;
}
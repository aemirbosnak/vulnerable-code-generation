//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_NUM_KEYS 100
#define MAX_NUM_VALUES 1000
#define MAX_NUM_INDEXES 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} record_t;

typedef struct {
    int num_keys;
    int num_values;
    record_t *keys;
    record_t *values;
} index_t;

int main() {
    FILE *fp;
    index_t index;

    // initialize the index
    index.num_keys = 0;
    index.num_values = 0;
    index.keys = (record_t *) malloc(MAX_NUM_KEYS * sizeof(record_t));
    index.values = (record_t *) malloc(MAX_NUM_VALUES * sizeof(record_t));

    // read the input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // read the input file line by line
    char line[MAX_VALUE_LENGTH];
    while (fgets(line, MAX_VALUE_LENGTH, fp)!= NULL) {
        // parse the line into key-value pairs
        char *key = strtok(line, ",");
        char *value = strtok(NULL, ",");

        // check if the key already exists in the index
        int key_index = -1;
        for (int i = 0; i < index.num_keys; i++) {
            if (strcmp(index.keys[i].key, key) == 0) {
                key_index = i;
                break;
            }
        }

        // add a new key-value pair to the index
        if (key_index == -1) {
            if (index.num_keys >= MAX_NUM_KEYS) {
                printf("Error: index is full.\n");
                exit(1);
            }
            strcpy(index.keys[index.num_keys].key, key);
            strcpy(index.values[index.num_values].value, value);
            index.num_keys++;
            index.num_values++;
        } else {
            strcpy(index.values[key_index].value, value);
        }
    }

    // close the input file
    fclose(fp);

    // print the index
    printf("Index:\n");
    for (int i = 0; i < index.num_keys; i++) {
        printf("%s -> %s\n", index.keys[i].key, index.values[i].value);
    }

    return 0;
}
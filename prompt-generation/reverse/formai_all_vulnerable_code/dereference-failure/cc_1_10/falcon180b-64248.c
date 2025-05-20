//Falcon-180B DATASET v1.0 Category: Database querying ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 1024

typedef struct {
    char* key;
    char* value;
} kv_pair;

int compare_key(const void* a, const void* b) {
    kv_pair* kv1 = (kv_pair*)a;
    kv_pair* kv2 = (kv_pair*)b;
    return strcmp(kv1->key, kv2->key);
}

int main() {
    FILE* fp;
    char line[MAX_LINE_SIZE];
    kv_pair kv_pairs[MAX_LINE_SIZE];
    int num_pairs = 0;

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Unable to open input file.\n");
        exit(1);
    }

    // Read input file
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        // Parse line into key-value pairs
        char* token = strtok(line, ":");
        while (token!= NULL) {
            if (num_pairs >= MAX_LINE_SIZE) {
                printf("Number of pairs exceeded maximum limit.\n");
                exit(1);
            }
            kv_pairs[num_pairs].key = strdup(token);
            kv_pairs[num_pairs].value = strdup(strtok(NULL, ":"));
            num_pairs++;
            token = strtok(NULL, ":");
        }
    }

    // Sort key-value pairs alphabetically by key
    qsort(kv_pairs, num_pairs, sizeof(kv_pair), compare_key);

    // Print sorted key-value pairs
    for (int i = 0; i < num_pairs; i++) {
        printf("%s: %s\n", kv_pairs[i].key, kv_pairs[i].value);
    }

    // Close input file
    fclose(fp);

    return 0;
}
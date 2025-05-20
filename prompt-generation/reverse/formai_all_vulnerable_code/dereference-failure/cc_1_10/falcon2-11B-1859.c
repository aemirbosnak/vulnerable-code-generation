//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 100000
#define BUFFER_SIZE 32

typedef struct {
    char buffer[BUFFER_SIZE];
    unsigned long long hash;
} HashEntry;

HashEntry* table[TABLE_SIZE];

unsigned long long hash_function(const char* string) {
    unsigned long long hash = 5381;
    int c;

    while ((c = *string++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

int main() {
    srand(time(NULL));
    char buffer[BUFFER_SIZE];

    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        table[i] = (HashEntry*) malloc(sizeof(HashEntry));
        if (table[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }
        memset(table[i]->buffer, 0, BUFFER_SIZE);
        table[i]->hash = 0;
    }

    while (1) {
        printf("Enter a string to hash:\n");
        fgets(buffer, BUFFER_SIZE, stdin);
        int len = strlen(buffer);
        if (len == 0)
            break;

        unsigned long long hash_value = hash_function(buffer);
        int j;
        for (j = 0; j < TABLE_SIZE; j++) {
            if (table[j]->hash == hash_value) {
                printf("Collision detected!\n");
                break;
            }
        }
        if (j == TABLE_SIZE) {
            table[j] = (HashEntry*) malloc(sizeof(HashEntry));
            if (table[j] == NULL) {
                fprintf(stderr, "Memory allocation failed.\n");
                exit(1);
            }
            memset(table[j]->buffer, 0, BUFFER_SIZE);
            table[j]->hash = hash_value;
            printf("Hash value stored successfully.\n");
        }
    }

    return 0;
}
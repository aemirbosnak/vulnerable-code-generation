//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_SIZE 1024
#define HASH_SIZE 32

typedef struct {
    char key[32];
    char value[MAX_SIZE];
} KeyValuePair;

void hash_string(char* str, char hash[HASH_SIZE]) {
    int i;
    for(i = 0; i < HASH_SIZE; i++) {
        hash[i] = str[i % 32];
    }
}

KeyValuePair* create_hash_table() {
    int i;
    KeyValuePair* hash_table = (KeyValuePair*) mmap(NULL, sizeof(KeyValuePair) * HASH_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if(hash_table == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < HASH_SIZE; i++) {
        hash_table[i].key[0] = '\0';
        hash_table[i].value[0] = '\0';
    }
    return hash_table;
}

int main() {
    int i, j;
    KeyValuePair* hash_table = create_hash_table();
    char key[32], value[MAX_SIZE];
    char hash[HASH_SIZE];

    for(i = 0; i < 10; i++) {
        printf("Enter key: ");
        scanf("%s", key);
        printf("Enter value: ");
        scanf("%s", value);

        hash_string(key, hash);
        for(j = 0; j < HASH_SIZE; j++) {
            if(strcmp(hash_table[j].key, hash) == 0) {
                strcat(hash_table[j].value, value);
                strcat(hash_table[j].value, " ");
                break;
            }
        }

        if(j == HASH_SIZE) {
            strcpy(hash_table[i % HASH_SIZE].key, hash);
            strcpy(hash_table[i % HASH_SIZE].value, value);
        }
    }

    printf("\nHash table:\n");
    for(i = 0; i < HASH_SIZE; i++) {
        printf("Key: %s, Value: %s\n", hash_table[i].key, hash_table[i].value);
    }

    munmap(hash_table, sizeof(KeyValuePair) * HASH_SIZE);

    return 0;
}
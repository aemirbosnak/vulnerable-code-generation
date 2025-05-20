//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 32
#define MAX_KEYS 1000
#define MAX_VALUES 10000

typedef struct {
    char *key;
    int value;
} key_value_t;

key_value_t *keys[MAX_KEYS];
int num_keys = 0;

void *search_thread(void *arg) {
    char *key = (char *) arg;
    int i;

    for (i = 0; i < num_keys; i++) {
        if (strcmp(keys[i]->key, key) == 0) {
            printf("Found key '%s' with value %d\n", key, keys[i]->value);
            return NULL;
        }
    }

    printf("Key '%s' not found\n", key);
    return NULL;
}

int main() {
    int i, num_threads = 0;
    pthread_t threads[MAX_THREADS];
    char keys_str[MAX_KEYS][MAX_KEYS];
    char *token;

    // Read keys from input file
    FILE *fp = fopen("keys.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open keys file\n");
        exit(1);
    }

    while (fgets(keys_str[num_keys], MAX_KEYS, fp)!= NULL) {
        keys[num_keys] = (key_value_t *) malloc(sizeof(key_value_t));
        keys[num_keys]->key = strdup(keys_str[num_keys]);
        keys[num_keys]->value = rand() % MAX_VALUES;
        num_keys++;
    }

    fclose(fp);

    // Launch search threads
    while (num_threads < MAX_THREADS && num_keys > 0) {
        token = strtok(keys_str[--num_keys], " ");
        pthread_create(&threads[num_threads++], NULL, search_thread, token);
    }

    // Join search threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
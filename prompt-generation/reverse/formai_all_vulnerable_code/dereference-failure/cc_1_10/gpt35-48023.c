//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_HASH_SIZE 100

pthread_mutex_t lock; // mutex to synchronize hash table modification

// Hash structure
typedef struct {
    char *key;
    char *value;
} hash_entry;

typedef struct {
    hash_entry *entries[MAX_HASH_SIZE];
} hash_map;

hash_map *hash_table;

// Hash functions
int hash(char *key) {
    int hash = 0;
    int i;

    for (i = 0; key[i] != '\0'; i++) {
        hash += (int) key[i];
    }

    return hash % MAX_HASH_SIZE;
}

hash_map *create_hash_map() {
    hash_map *hm;

    hm = (hash_map *) malloc(sizeof(hash_map));
    memset(hm, 0, sizeof(hash_map));

    return hm;
}

hash_entry *create_hash_entry(char *key, char *value) {
    hash_entry *he;

    he = (hash_entry *) malloc(sizeof(hash_entry));
    he->key = strdup(key);
    he->value = strdup(value);

    return he;
}

void put(hash_map *hm, char *key, char *value) {
    int index;
    hash_entry *he;

    index = hash(key);
    he = create_hash_entry(key, value);

    pthread_mutex_lock(&lock);
    hm->entries[index] = he;
    pthread_mutex_unlock(&lock);
}

char *get(hash_map *hm, char *key) {
    int index;
    char *value;

    index = hash(key);

    pthread_mutex_lock(&lock);
    if (!hm->entries[index]) {
        value = NULL;
    } else {
        value = hm->entries[index]->value;
    }
    pthread_mutex_unlock(&lock);

    return value;
}

// Worker thread function to generate hash for given input string
void *hash_worker(void *data) {
    char *input_str = (char *) data;
    char hash_str[41];

    memset(hash_str, 0, 41);

    int i;
    for (i = 0; input_str[i] != '\0'; i++) {
        sprintf(hash_str, "%s%02x", hash_str, input_str[i] ^ 0xff); // perform XOR operation with 0xff and convert to hexadecimal form
    }

    printf("Hash generated for input: %s -> %s\n", input_str, hash_str);

    put(hash_table, input_str, hash_str);

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int i;
    int num_threads;
    pthread_t threads[MAX_THREADS];
    char *inputs[MAX_THREADS] = {"hello", "world", "foo", "bar", "baz", "123", "abc", "def", "ghi", "jkl"};

    num_threads = argc > 1 ? atoi(argv[1]) : MAX_THREADS;

    if (num_threads > MAX_THREADS) {
        printf("Error: Maximum number of threads is %d\n", MAX_THREADS);
        exit(EXIT_FAILURE);
    }

    hash_table = create_hash_map();

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, hash_worker, (void *) inputs[i])) {
            printf("Error: Unable to create thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Test get() function
    for (i = 0; i < num_threads; i++) {
        char *value = get(hash_table, inputs[i]);
        printf("Value for %s: %s\n", inputs[i], value);
    }

    pthread_mutex_destroy(&lock);
    free(hash_table);

    exit(EXIT_SUCCESS);
}
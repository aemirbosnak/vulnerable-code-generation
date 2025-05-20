//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define HASH_SIZE 100
#define BUFFER_SIZE 100
#define NUM_CLIENTS 10

typedef struct Node {
    char key[BUFFER_SIZE];
    char value[BUFFER_SIZE];
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[HASH_SIZE];
    pthread_mutex_t locks[HASH_SIZE];
} HashTable;

HashTable* createHashTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        ht->table[i] = NULL;
        pthread_mutex_init(&ht->locks[i], NULL);
    }
    return ht;
}

unsigned int hashFunction(const char* key) {
    unsigned long int hash = 0;
    int c;
    while ((c = *key++)) {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash % HASH_SIZE;
}

void htPut(HashTable* ht, const char* key, const char* value) {
    unsigned int index = hashFunction(key);
    pthread_mutex_lock(&ht->locks[index]);

    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;

    pthread_mutex_unlock(&ht->locks[index]);
}

const char* htGet(HashTable* ht, const char* key) {
    unsigned int index = hashFunction(key);
    pthread_mutex_lock(&ht->locks[index]);

    Node* current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            pthread_mutex_unlock(&ht->locks[index]);
            return current->value;
        }
        current = current->next;
    }

    pthread_mutex_unlock(&ht->locks[index]);
    return NULL;
}

void* clientThread(void* arg) {
    HashTable* ht = (HashTable*)arg;

    for (int i = 0; i < NUM_CLIENTS; i++) {
        char key[BUFFER_SIZE];
        char value[BUFFER_SIZE];
        snprintf(key, BUFFER_SIZE, "key%d", i);
        snprintf(value, BUFFER_SIZE, "value%d", i);

        htPut(ht, key, value);
        const char* retrievedValue = htGet(ht, key);
        
        if (retrievedValue != NULL) {
            printf("Thread %lu: Retrieved %s for %s\n", pthread_self(), retrievedValue, key);
        } else {
            printf("Thread %lu: Could not find value for %s\n", pthread_self(), key);
        }
    }
    return NULL;
}

int main() {
    HashTable* ht = createHashTable();
    pthread_t threads[NUM_CLIENTS];

    for (int i = 0; i < NUM_CLIENTS; i++) {
        pthread_create(&threads[i], NULL, clientThread, (void*)ht);
    }

    for (int i = 0; i < NUM_CLIENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        pthread_mutex_destroy(&ht->locks[i]);
    }
    free(ht);

    return 0;
}
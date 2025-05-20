//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>

#define HASH_SIZE 256

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct node {
    char* str;
    uint8_t hash[32];
    struct node* next;
};

struct node* hash_table[HASH_SIZE];

void insert_hash(char* str) {
    pthread_mutex_lock(&mutex);
    uint32_t hash = 5381;
    char* c = str;
    while (*c) {
        hash = ((hash << 5) + hash) + (*c);
        c++;
    }
    uint8_t array_hash[32];
    memcpy(array_hash, &hash, 32);
    int index = hash % HASH_SIZE;
    struct node* head = hash_table[index];
    if (head == NULL) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->str = str;
        memcpy(new_node->hash, array_hash, 32);
        new_node->next = NULL;
        hash_table[index] = new_node;
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            if (strcmp(temp->str, str) == 0) {
                pthread_mutex_unlock(&mutex);
                return;
            }
            temp = temp->next;
        }
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->str = str;
        memcpy(new_node->hash, array_hash, 32);
        new_node->next = head;
        hash_table[index] = new_node;
    }
    pthread_mutex_unlock(&mutex);
}

void* hash_strings(void* arg) {
    char* inputs = (char*)arg;
    char* token;
    while ((token = strsep(&inputs, ","))) {
        char* str = strdup(token);
        insert_hash(str);
    }
    pthread_exit(NULL);
}

int main() {
    char input[1024];
    printf("Enter the strings separated by commas: ");
    fgets(input, 1024, stdin);
    input[strcspn(input, "\n")] = 0;
    
    int NUM_THREADS = 4;
    pthread_t tid[NUM_THREADS];
    char* input_ptrs[NUM_THREADS];
    int len = strlen(input);
    int chunk_size = (len + NUM_THREADS - 1) / NUM_THREADS;
    int i, j;
    for (i = 0, j = 0; i < NUM_THREADS && j < len; i++, j += chunk_size) {
        input_ptrs[i] = &input[j];
        if (j + chunk_size >= len) {
            chunk_size = len - j;
        }
        input_ptrs[i][chunk_size] = 0;
        pthread_create(&tid[i], NULL, hash_strings, input_ptrs[i]);
    }

    void* status;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], &status);
    }

    printf("\nContents of hash table:\n");
    for (i = 0; i < HASH_SIZE; i++) {
        if (hash_table[i] != NULL) {
            struct node* temp = hash_table[i];
            while (temp != NULL) {
                printf("Hash value: ");
                for (j = 0; j < 32; j++) {
                    printf("%02x", temp->hash[j]);
                }
                printf("\tString: %s\n", temp->str);
                temp = temp->next;
            }
        }
    }

    for (i = 0; i < HASH_SIZE; i++) {
        if (hash_table[i] != NULL) {
            struct node* temp = hash_table[i];
            while (temp != NULL) {
                struct node* prev = temp;
                temp = temp->next;
                free(prev->str);
                free(prev);
            }
        }
    }

    return 0;
}
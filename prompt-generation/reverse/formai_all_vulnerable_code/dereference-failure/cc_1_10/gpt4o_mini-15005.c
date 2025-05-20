//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/sha.h>

#define HASH_LENGTH SHA256_DIGEST_LENGTH
#define BUFFER_SIZE 256

typedef struct {
    char *input;
    unsigned char output[HASH_LENGTH];
} HashTask;

void *hash_function(void *arg) {
    HashTask *task = (HashTask *)arg;
    SHA256((unsigned char *)task->input, strlen(task->input), task->output);
    pthread_exit(NULL);
}

void print_hash(unsigned char hash[HASH_LENGTH]) {
    for(int i = 0; i < HASH_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    pthread_t threads[10];
    HashTask tasks[10];
    int i;
    char input[BUFFER_SIZE];
    
    for (i = 0; i < 10; i++) {
        printf("Enter input for task %d: ", i + 1);
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0;  // Remove newline character
        
        tasks[i].input = malloc(strlen(input) + 1);
        strcpy(tasks[i].input, input);
        
        if (pthread_create(&threads[i], NULL, hash_function, (void *)&tasks[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
        printf("Hash of input '%s': ", tasks[i].input);
        print_hash(tasks[i].output);
        free(tasks[i].input);  // Free allocated memory
    }

    return 0;
}
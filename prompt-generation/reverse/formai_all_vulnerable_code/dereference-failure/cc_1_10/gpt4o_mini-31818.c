//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <openssl/sha.h>

#define MAX_CHILDREN 4
#define BUFFER_SIZE 256

void compute_hash(const char *data, unsigned char *hash) {
    SHA256((unsigned char *)data, strlen(data), hash);
}

void print_hash(unsigned char *hash) {
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    size_t input_length = strlen(input);
    size_t segment_size = input_length / MAX_CHILDREN;

    pid_t pids[MAX_CHILDREN];
    unsigned char hash_results[MAX_CHILDREN][SHA256_DIGEST_LENGTH];

    for (int i = 0; i < MAX_CHILDREN; i++) {
        size_t start_index = i * segment_size;
        size_t end_index = (i == MAX_CHILDREN - 1) ? input_length : (i + 1) * segment_size;

        if ((pids[i] = fork()) == 0) {
            // Child process
            char segment[BUFFER_SIZE];
            strncpy(segment, input + start_index, end_index - start_index);
            segment[end_index - start_index] = '\0';  // Null-terminate the segment

            compute_hash(segment, hash_results[i]);
            exit(0);  // Exit child process
        } else if (pids[i] < 0) {
            perror("Fork failed");
            return 2;
        }
    }

    // Parent process
    for (int i = 0; i < MAX_CHILDREN; i++) {
        waitpid(pids[i], NULL, 0);  // Wait for each child to finish
    }

    // Combine results
    unsigned char final_hash[SHA256_DIGEST_LENGTH];
    memset(final_hash, 0, SHA256_DIGEST_LENGTH);

    for (int i = 0; i < MAX_CHILDREN; i++) {
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            final_hash[j] ^= hash_results[i][j];  // Combining hashes (simple XOR)
        }
    }

    printf("Final Hash: ");
    print_hash(final_hash);

    return 0;
}
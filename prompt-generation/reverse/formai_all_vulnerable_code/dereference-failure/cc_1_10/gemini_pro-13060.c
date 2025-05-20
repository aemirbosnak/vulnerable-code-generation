//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <openssl/sha.h>

#define NUM_THREADS 4

typedef struct {
    char *message;
    int message_len;
    unsigned char *digest;
} thread_arg_t;

void *thread_func(void *arg)
{
    thread_arg_t *args = (thread_arg_t *)arg;
    SHA256_CTX ctx;

    SHA256_Init(&ctx);
    SHA256_Update(&ctx, args->message, args->message_len);
    SHA256_Final(args->digest, &ctx);

    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int message_len = strlen(argv[1]);
    char *message = malloc(message_len + 1);
    strcpy(message, argv[1]);

    pthread_t threads[NUM_THREADS];
    thread_arg_t thread_args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].message = message;
        thread_args[i].message_len = message_len;
        thread_args[i].digest = malloc(SHA256_DIGEST_LENGTH);

        if (pthread_create(&threads[i], NULL, thread_func, &thread_args[i]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    printf("SHA256 digest: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", thread_args[0].digest[i]);
    }
    printf("\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        free(thread_args[i].digest);
    }
    free(message);

    return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_URL_LEN 1024

struct thread_args {
    char* url;
    int thread_num;
};

void* sanitize_url(void* arg) {
    struct thread_args* args = (struct thread_args*) arg;
    char sanitized_url[MAX_URL_LEN] = "";
    char* url = args->url;
    int thread_num = args->thread_num;

    // Iterate through each character in the URL
    for (int i = 0; i < strlen(url); i++) {
        char c = url[i];

        // Sanitize the character if necessary
        switch (c) {
            case ' ':
                sanitized_url[strlen(sanitized_url)] = '+';
                break;
            case '%':
                if (i + 2 < strlen(url)) {
                    char hex[3] = { url[i+1], url[i+2], '\0' };
                    int ascii = (int) strtol(hex, NULL, 16);
                    sanitized_url[strlen(sanitized_url)] = (char) ascii;
                    i += 2;
                }
                break;
            default:
                sanitized_url[strlen(sanitized_url)] = c;
                break;
        }
    }

    printf("Thread %d: Original URL: %s\n", thread_num, url);
    printf("Thread %d: Sanitized URL: %s\n", thread_num, sanitized_url);

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please provide one or more URLs to sanitize.\n");
        exit(1);
    }

    pthread_t threads[argc - 1];

    // Create a thread for each URL to sanitize
    for (int i = 1; i < argc; i++) {
        struct thread_args* args = malloc(sizeof(struct thread_args));
        args->url = argv[i];
        args->thread_num = i - 1;
        pthread_create(&threads[i-1], NULL, sanitize_url, (void*) args);
    }

    // Wait for all threads to complete
    for (int i = 1; i < argc; i++) {
        pthread_join(threads[i-1], NULL);
    }

    return 0;
}
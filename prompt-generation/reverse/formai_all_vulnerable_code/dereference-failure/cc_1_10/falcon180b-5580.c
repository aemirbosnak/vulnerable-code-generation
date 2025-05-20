//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_URL_LEN 2048

typedef struct {
    char url[MAX_URL_LEN];
} url_t;

void *sanitize_url(void *arg) {
    url_t *url = (url_t *) arg;
    char *ptr = url->url;
    char *end = ptr + strlen(ptr);

    // Remove leading/trailing spaces
    while (isspace(*ptr)) {
        ptr++;
    }
    while (isspace(*(end-1))) {
        end--;
        *end = '\0';
    }

    // Convert to lowercase
    for (ptr = url->url; *ptr; ptr++) {
        *ptr = tolower(*ptr);
    }

    // Remove invalid characters
    while (ptr < end) {
        if (!isalnum(*ptr) && *ptr!= '.' && *ptr!= '-') {
            *ptr = '_';
        }
        ptr++;
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    char input_buffer[MAX_URL_LEN];
    url_t urls[MAX_THREADS];

    printf("Enter URLs to sanitize (one per line, press enter to finish):\n");
    fgets(input_buffer, MAX_URL_LEN, stdin);

    while (fgets(input_buffer, MAX_URL_LEN, stdin)!= NULL) {
        if (num_threads >= MAX_THREADS) {
            printf("Maximum number of threads reached.\n");
            break;
        }

        char *url_start = strchr(input_buffer, '\n');
        if (url_start!= NULL) {
            *url_start = '\0';
        }

        strcpy(urls[num_threads].url, input_buffer);
        pthread_create(&threads[num_threads], NULL, sanitize_url, &urls[num_threads]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sanitization completed.\n");

    return 0;
}
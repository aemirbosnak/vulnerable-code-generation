//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URL_LENGTH 2048
#define MAX_THREADS 10

typedef struct {
    char *url;
    char *sanitized_url;
} url_data;

void *sanitize_url(void *arg) {
    url_data *data = (url_data *) arg;
    char *sanitized_url = malloc(MAX_URL_LENGTH);
    char *ptr = data->url;
    char *sanitized_ptr = sanitized_url;

    while (*ptr!= '\0') {
        if (isalnum(*ptr) || (*ptr == '.' || *ptr == '-' || *ptr == '_')) {
            *sanitized_ptr = *ptr;
            sanitized_ptr++;
        }
        ptr++;
    }

    *sanitized_ptr = '\0';
    data->sanitized_url = sanitized_url;

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    char *url = argv[1];
    url_data *data = malloc(sizeof(url_data));
    data->url = strdup(url);

    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    for (int i = 0; i < MAX_THREADS && num_threads < 10; i++) {
        pthread_create(&threads[num_threads], NULL, sanitize_url, data);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sanitized URL: %s\n", data->sanitized_url);

    free(data->url);
    free(data->sanitized_url);
    free(data);

    return 0;
}
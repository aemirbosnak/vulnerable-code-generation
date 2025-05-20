//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_URL_LENGTH 255
#define MAX_THREADS 10

struct thread_args {
    char **urls;
    int num_urls;
};

char *sanitize_url(char *url) {
    char *new_url = malloc(MAX_URL_LENGTH * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(url); i++) {
        if (url[i] == '\'') {
            new_url[j++] = '%';
            new_url[j++] = '2';
            new_url[j++] = '7';
        } else if (url[i] == '\"') {
            new_url[j++] = '%';
            new_url[j++] = '2';
            new_url[j++] = '2';
        } else if (url[i] == '<') {
            new_url[j++] = '%';
            new_url[j++] = '3';
            new_url[j++] = 'C';
        } else if (url[i] == '>') {
            new_url[j++] = '%';
            new_url[j++] = '3';
            new_url[j++] = 'E';
        } else if (url[i] == '\\') {
            new_url[j++] = '%';
            new_url[j++] = '5';
            new_url[j++] = 'C';
        } else if (url[i] == '^') {
            new_url[j++] = '%';
            new_url[j++] = '5';
            new_url[j++] = 'E';
        } else if (url[i] == '`') {
            new_url[j++] = '%';
            new_url[j++] = '6';
            new_url[j++] = '`';
        } else {
            new_url[j++] = url[i];
        }
    }
    new_url[j] = '\0';
    return new_url;
}

void *sanitize_urls(void *args) {
    struct thread_args *data = (struct thread_args *) args;
    for (int i = 0; i < data->num_urls; i++) {
        char *old_url = data->urls[i];
        char *new_url = sanitize_url(old_url);
        data->urls[i] = new_url;
        free(old_url);
    }
    pthread_exit(NULL);
}

int main() {
    char *urls[] = {"https://www.example.com/page?id=1&query=test'ing'",
                    "https://www.example.com/page?id=2&query=test\"ing\"",
                    "https://www.example.com/page?id=3&query=<test>",
                    "https://www.example.com/page?id=4&query=>test<",
                    "https://www.example.com/page?id=5&query=esch\\er\\o",
                    "https://www.example.com/page?id=6&query=test^ing^",
                    "https://www.example.com/page?id=7&query=test`ing`",
                    "https://www.example.com/page?id=8",
                    "https://www.example.com/page?id=9",
                    "https://www.example.com/page?id=10"};
    int num_urls = sizeof(urls) / sizeof(char *);

    pthread_t threads[MAX_THREADS];
    struct thread_args args[MAX_THREADS];
    int num_threads = num_urls / 2;
    int urls_per_thread = num_urls / num_threads;

    int remaining_urls = num_urls;
    for (int i = 0; i < num_threads; i++) {
        int num_urls_to_sanitize = urls_per_thread;
        if (remaining_urls < urls_per_thread) {
            num_urls_to_sanitize = remaining_urls;
        }
        args[i].urls = &urls[i * urls_per_thread];
        args[i].num_urls = num_urls_to_sanitize;
        pthread_create(&threads[i], NULL, sanitize_urls, (void *) &args[i]);
        remaining_urls -= urls_per_thread;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_urls; i++) {
        printf("%s\n", urls[i]);
    }

    return 0;
}
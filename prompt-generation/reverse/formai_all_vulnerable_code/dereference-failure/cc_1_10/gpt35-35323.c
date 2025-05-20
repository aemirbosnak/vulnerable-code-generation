//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include <pthread.h>

#define URL "http://www.example.com"
#define INTERVAL 60
#define NUM_THREADS 3

typedef struct {
    int id;
    CURL *curl;
} ThreadArgs;

void *check_website(void *args) {
    ThreadArgs *targs = (ThreadArgs *)args;

    printf("Thread %d started.\n", targs->id);

    while (1) {
        CURLcode res = curl_easy_perform(targs->curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Thread %d: %s is up!\n", targs->id, URL);
        }

        sleep(INTERVAL);
    }

    curl_easy_cleanup(targs->curl);
    free(targs);

    return NULL;
}

int main() {
    CURL *curl;
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Error initializing CURL.\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, URL);

    pthread_t threads[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        ThreadArgs *targs = malloc(sizeof(ThreadArgs));
        targs->id = i;
        targs->curl = curl_easy_duphandle(curl);

        rc = pthread_create(&threads[i], NULL, check_website, (void *)targs);

        if (rc) {
            fprintf(stderr, "Error creating thread.\n");
            return 1;
        }

        printf("Thread %d created.\n", i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    curl_easy_cleanup(curl);

    return 0;
}
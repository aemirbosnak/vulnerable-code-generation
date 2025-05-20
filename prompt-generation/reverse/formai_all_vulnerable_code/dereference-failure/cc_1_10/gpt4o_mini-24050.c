//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <curl/curl.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1024

typedef struct {
    const char *url;
    char *result;
} ThreadData;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    ThreadData *data = (ThreadData *)userp;

    if (data->result == NULL) {
        data->result = malloc(BUFFER_SIZE);
        if (data->result == NULL) return 0;
        data->result[0] = '\0'; // Initialize the string
    }

    if (strlen(data->result) + realsize >= BUFFER_SIZE) {
        data->result = realloc(data->result, strlen(data->result) + realsize + 1);
        if (data->result == NULL) return 0;
    }

    strncat(data->result, contents, realsize);
    return realsize;
}

void *fetch_data(void *threadarg) {
    ThreadData *data = (ThreadData *)threadarg;
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)data);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "C-Browser-Plugin/1.0");
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> <url3> <url4>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].url = argv[i + 1];
        thread_data[i].result = NULL;

        int rc = pthread_create(&threads[i], NULL, fetch_data, (void *)&thread_data[i]);
        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, rc);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Result from %s:\n%s\n\n", thread_data[i].url, thread_data[i].result);
        free(thread_data[i].result);
    }

    return EXIT_SUCCESS;
}
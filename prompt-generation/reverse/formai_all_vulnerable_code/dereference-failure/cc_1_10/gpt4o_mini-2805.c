//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <curl/curl.h>

#define MAX_THREADS 10
#define MAX_URL_LENGTH 256

typedef struct {
    char url[MAX_URL_LENGTH];
    int thread_id;
} ThreadData;

void* fetch_url(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); // Enable verbose for debugging
        printf("Thread %d: Fetching URL: %s\n", data->thread_id, data->url);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "Thread %d: curl_easy_perform() failed: %s\n", data->thread_id, curl_easy_strerror(res));
        } else {
            printf("Thread %d: Successfully fetched %s\n", data->thread_id, data->url);
        }

        curl_easy_cleanup(curl);
    }

    free(data);
    return NULL;
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for(int i = 1; i < argc && thread_count < MAX_THREADS; i++) {
        ThreadData* data = malloc(sizeof(ThreadData));
        if (!data) {
            fprintf(stderr, "Unable to allocate memory for thread data\n");
            exit(EXIT_FAILURE);
        }

        strncpy(data->url, argv[i], MAX_URL_LENGTH);
        data->thread_id = thread_count;

        if(pthread_create(&threads[thread_count], NULL, fetch_url, data) != 0) {
            fprintf(stderr, "Error creating thread for URL: %s\n", argv[i]);
            free(data);
            continue; // Proceed to attempt to create next thread
        }

        thread_count++;
    }

    // Join all threads
    for(int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed fetching URLs.\n");
    return EXIT_SUCCESS;
}
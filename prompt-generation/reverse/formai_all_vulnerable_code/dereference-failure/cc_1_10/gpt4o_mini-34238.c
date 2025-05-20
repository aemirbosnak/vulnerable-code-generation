//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <curl/curl.h>

#define NUM_THREADS 4
#define MAX_URL_LENGTH 256

// Data structure for threads
typedef struct {
    char url[MAX_URL_LENGTH];
    int thread_id;
} thread_data;

// Function to perform a web request
void* fetch_url(void* arg) {
    thread_data* data = (thread_data*)arg;
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the request and check for errors
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "Thread %d: curl_easy_perform() failed: %s\n", data->thread_id, curl_easy_strerror(res));
        } else {
            printf("Thread %d: Successfully fetched: %s\n", data->thread_id, data->url);
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    pthread_exit(NULL);
}

// Function to start threads for fetching URLs
void start_threads(const char* urls[], int num_urls) {
    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];

    // Create threads to fetch URLs
    for (int i = 0; i < num_urls; i++) {
        strncpy(data[i % NUM_THREADS].url, urls[i], MAX_URL_LENGTH);
        data[i % NUM_THREADS].thread_id = i % NUM_THREADS;

        if (pthread_create(&threads[i % NUM_THREADS], NULL, fetch_url, (void*)&data[i % NUM_THREADS])) {
            fprintf(stderr, "Error creating thread for URL: %s\n", urls[i]);
            exit(EXIT_FAILURE);
        }

        // Join the thread if we've reached the thread limit
        if (i % NUM_THREADS == (NUM_THREADS - 1) || i == num_urls - 1) {
            for (int j = 0; j < NUM_THREADS && j <= i; j++) {
                pthread_join(threads[j], NULL);
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Start fetching the provided URLs
    start_threads((const char**)&argv[1], argc - 1);

    // Cleanup CURL
    curl_global_cleanup();
    return EXIT_SUCCESS;
}
//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define BUFFER_SIZE 4096

typedef struct {
    char url[BUFFER_SIZE];
    int thread_id;
} thread_data;

void* fetch_url(void* data) {
    thread_data *t_data = (thread_data*)data;
    CURL *curl;
    CURLcode res;

    printf("Thread %d: Fetching URL: %s\n", t_data->thread_id, t_data->url);
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, t_data->url);
        // Follow redirects
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors and print response
        if(res != CURLE_OK) {
            fprintf(stderr, "Thread %d: curl_easy_perform() failed: %s\n", t_data->thread_id, curl_easy_strerror(res));
        } else {
            printf("Thread %d: Successfully fetched %s\n", t_data->thread_id, t_data->url);
        }

        // Always cleanup
        curl_easy_cleanup(curl);
    }

    free(t_data);
    return NULL;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_URLS];
    int num_urls = argc - 1;
    if(num_urls > MAX_URLS) {
        num_urls = MAX_URLS;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);

    for(int i = 0; i < num_urls; ++i) {
        thread_data *t_data = (thread_data*)malloc(sizeof(thread_data));
        if(t_data == NULL) {
            fprintf(stderr, "Failed to allocate memory for thread data\n");
            return EXIT_FAILURE;
        }

        strcpy(t_data->url, argv[i + 1]);
        t_data->thread_id = i;

        if(pthread_create(&threads[i], NULL, fetch_url, (void*)t_data) != 0) {
            fprintf(stderr, "Failed to create thread for URL: %s\n", t_data->url);
            free(t_data);
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for(int i = 0; i < num_urls; ++i) {
        pthread_join(threads[i], NULL);
    }

    curl_global_cleanup();
    return EXIT_SUCCESS;
}
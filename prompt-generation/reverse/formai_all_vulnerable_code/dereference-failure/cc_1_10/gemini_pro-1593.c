//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <pthread.h>

#define NUM_THREADS 10

struct thread_data {
    char *url;
    int *status_code;
};

void *check_website(void *threadarg) {
    struct thread_data *data = (struct thread_data *)threadarg;

    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing cURL\n");
        return NULL;
    }

    curl_easy_setopt(curl, CURLOPT_URL, data->url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

    CURLcode res = curl_easy_perform(curl);
    *data->status_code = res;

    curl_easy_cleanup(curl);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> [url2] ...\n", argv[0]);
        return 1;
    }

    int num_urls = argc - 1;

    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data[NUM_THREADS];

    int i;
    for (i = 0; i < num_urls; i++) {
        if (i < NUM_THREADS) {
            thread_data[i].url = argv[i + 1];
            thread_data[i].status_code = malloc(sizeof(int));
            pthread_create(&threads[i], NULL, check_website, &thread_data[i]);
        } else {
            sleep(1);
            thread_data[i].url = argv[i + 1];
            thread_data[i].status_code = malloc(sizeof(int));
            pthread_create(&threads[i], NULL, check_website, &thread_data[i]);
            pthread_join(threads[i - NUM_THREADS], NULL);
            free(thread_data[i - NUM_THREADS].status_code);
        }
    }

    for (i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
        printf("%s: %d\n", thread_data[i].url, *thread_data[i].status_code);
        free(thread_data[i].status_code);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Function to write the data received from the server to a file
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    FILE *file = (FILE *)userp;
    return fwrite(contents, size, nmemb, file);
}

// Function to display the progress of the download
int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    int id = *((int *)clientp);
    printf("Thread %d: Download progress: %ld/%ld\n", id, dlnow, dltotal);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <URL> <output file> <thread count>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    FILE *file;
    int thread_count = atoi(argv[3]);
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, argv[2]);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &thread_count);

        int max_threads = thread_count;
        int active_threads = 0;
        pthread_t thread_id[max_threads];

        while (active_threads < max_threads) {
            int id = active_threads;
            pthread_create(&thread_id[id], NULL, (void *)curl_multi_perform, (void *)&curl);
            active_threads++;
        }

        while (active_threads > 0) {
            pthread_join(thread_id[--active_threads], NULL);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
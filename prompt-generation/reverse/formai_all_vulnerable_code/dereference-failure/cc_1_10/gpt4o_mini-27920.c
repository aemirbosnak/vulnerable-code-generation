//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048
#define BUFFER_SIZE 4096

typedef struct {
    char url[MAX_URL_LENGTH];
    char buffer[BUFFER_SIZE];
} FetchData;

void *fetch_url(void *arg) {
    FetchData *data = (FetchData *)arg;
    CURL *curl;
    CURLcode res;
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)data->buffer);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Fetched URL: %s\n", data->buffer);
        }
        
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
    return NULL;
}

void signal_handler(int sig) {
    if(sig == SIGINT) {
        printf("\nReceived interrupt signal. Exiting gracefully.\n");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = signal_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    
    if (sigaction(SIGINT, &sigIntHandler, NULL) < 0) {
        perror("Failed to set signal handler");
        return EXIT_FAILURE;
    }

    FetchData data;
    strncpy(data.url, argv[1], MAX_URL_LENGTH - 1);
    data.url[MAX_URL_LENGTH - 1] = '\0'; // Ensure null termination

    pthread_t fetch_thread;

    if (pthread_create(&fetch_thread, NULL, fetch_url, (void *)&data) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    pthread_join(fetch_thread, NULL);
    printf("Thread finished execution.\n");

    return EXIT_SUCCESS;
}
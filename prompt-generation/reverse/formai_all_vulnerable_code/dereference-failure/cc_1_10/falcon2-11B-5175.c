//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUF_SIZE 4096

typedef struct {
    char url[1024];
    char buf[BUF_SIZE];
    char response[BUF_SIZE];
} request_t;

void *request_handler(void *ptr) {
    request_t *request = (request_t*)ptr;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, request->url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, request->buf);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == CURLE_OK) {
            strcpy(request->response, request->buf);
        }
        printf("Response: %s\n", request->response);
        free(request->buf);
        free(request);
    }

    curl_global_cleanup();
    return NULL;
}

int main(int argc, char *argv[]) {
    request_t *requests;
    size_t num_requests;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num_requests>\n", argv[0]);
        return 1;
    }

    num_requests = atoi(argv[1]);

    requests = (request_t*)malloc(num_requests * sizeof(request_t));
    if (!requests) {
        fprintf(stderr, "Failed to allocate memory for requests\n");
        return 1;
    }

    for (size_t i = 0; i < num_requests; i++) {
        sprintf(requests[i].url, "https://www.example.com/");
        requests[i].url[strlen(requests[i].url) - 1] = '\0'; // Remove trailing slash
    }

    pthread_t threads[num_requests];
    for (size_t i = 0; i < num_requests; i++) {
        request_t *request = &requests[i];
        pthread_create(&threads[i], NULL, request_handler, (void*)request);
    }

    for (size_t i = 0; i < num_requests; i++) {
        pthread_join(threads[i], NULL);
    }

    free(requests);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024
#define MAX_REDIRECTS 10

typedef struct {
    char *buffer;
    size_t size;
} buffer_t;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    buffer_t *buffer = (buffer_t *) userp;
    size_t new_size = buffer->size + size * nmemb;
    char *new_buffer = realloc(buffer->buffer, new_size);

    if (new_buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        exit(EXIT_FAILURE);
    }

    buffer->buffer = new_buffer;
    buffer->size = new_size;
    strncat(buffer->buffer, (char *) ptr, size * nmemb);

    return nmemb;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    CURL *curl;
    CURLcode res;
    buffer_t response;
    response.buffer = malloc(BUFFER_SIZE);
    response.size = 0;

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, MAX_REDIRECTS);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "Failed to download %s: %s\n", argv[1], curl_easy_strerror(res));
            exit(EXIT_FAILURE);
        }

        curl_easy_cleanup(curl);
        printf("Response:\n%s", response.buffer);
        free(response.buffer);
    }

    return 0;
}
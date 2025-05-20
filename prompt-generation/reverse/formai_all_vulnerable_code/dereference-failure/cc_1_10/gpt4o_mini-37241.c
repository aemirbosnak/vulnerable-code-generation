//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *data;
    size_t size;
} ResponseData;

void init_response_data(ResponseData *res) {
    res->data = malloc(1);
    res->data[0] = '\0';
    res->size = 0;
}

size_t write_callback(char *ptr, size_t size, size_t nmemb, ResponseData *res) {
    size_t total_size = size * nmemb;
    res->data = realloc(res->data, res->size + total_size + 1);
    if (res->data == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 0;
    }
    
    memcpy(&(res->data[res->size]), ptr, total_size);
    res->size += total_size;
    res->data[res->size] = '\0';

    return total_size;
}

void cleanup_response_data(ResponseData *res) {
    free(res->data);
    res->data = NULL;
    res->size = 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <URL> <Method>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];
    char *method = argv[2];
    CURL *curl;
    CURLcode res;
    ResponseData response;

    init_response_data(&response);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);

        if (strcmp(method, "GET") == 0) {
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        } else if (strcmp(method, "POST") == 0) {
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
        } else {
            fprintf(stderr, "Invalid HTTP method. Use GET or POST.\n");
            curl_easy_cleanup(curl);
            cleanup_response_data(&response);
            exit(EXIT_FAILURE);
        }

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response data:\n%s\n", response.data);
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }

    cleanup_response_data(&response);

    return 0;
}
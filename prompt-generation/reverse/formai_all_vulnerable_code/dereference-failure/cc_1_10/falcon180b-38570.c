//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} StringBuffer;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    StringBuffer *buffer = (StringBuffer*) userp;
    size_t new_size = buffer->size + size * nmemb;
    char *new_data = realloc(buffer->data, new_size);
    if (new_data == NULL) {
        fprintf(stderr, "Out of memory\n");
        return 0;
    }
    buffer->data = new_data;
    buffer->size = new_size;
    memcpy(buffer->data + buffer->size - size * nmemb, contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    StringBuffer response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        response.data = malloc(1);
        response.size = 0;

        curl_easy_setopt(curl, CURLOPT_URL, "https://httpbin.org/get");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", response.data);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}
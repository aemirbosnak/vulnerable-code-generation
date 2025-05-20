//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write received data into memory
static size_t writeMemoryCallback(void *ptr, size_t size, size_t nmemb, void *data) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)data;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Failed to reallocate memory\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

int main(int argc, char *argv[]) {
    CURLcode res;
    CURL *curl;
    char *url;
    int timeout = 10; // Timeout in seconds
    long httpCode;
    struct MemoryStruct chunk;
    curl = curl_easy_init();
    url = argv[1];

    if (curl) {
        chunk.memory = malloc(1);
        chunk.size = 0;

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return 1;
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

        if (httpCode == 200) {
            printf("Website is up and running!\n");
        } else {
            printf("Error: HTTP response code is %ld\n", httpCode);
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);
    } else {
        printf("Failed to initialize curl\n");
        return 1;
    }

    return 0;
}
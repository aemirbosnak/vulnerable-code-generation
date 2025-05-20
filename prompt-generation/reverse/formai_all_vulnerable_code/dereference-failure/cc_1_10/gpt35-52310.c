//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>

#define URL "http://www.example.com"

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t real_size = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + real_size + 1);
    if(ptr == NULL) {
        printf("ERROR: Failed to reallocate memory for website content!");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, real_size);
    mem->size += real_size;
    mem->memory[mem->size] = '\0';

    return real_size;
}

int main() {
    CURL *curl_handle;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, URL);
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl_handle);

        if(res == CURLE_OK) {
            printf("Website is UP! HTTP status code: %d\n", res);
        } else {
            printf("ERROR: Website is DOWN! HTTP status code: %d\n", res);
        }

        free(chunk.memory);
        curl_easy_cleanup(curl_handle);
    }

    curl_global_cleanup();

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

struct MemoryStruct {
    char *memory;
    size_t size;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    if(mem->size < realsize) {
        mem->memory = realloc(mem->memory, mem->size + realsize);
        if(!mem->memory) {
            fprintf(stderr, "Not enough memory\n");
            exit(1);
        }
        mem->size += realsize;
    }

    memcpy(&(mem->memory[mem->size - realsize]), contents, realsize);
    mem->memory[mem->size - realsize] = 0;

    return realsize;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(!curl) {
        fprintf(stderr, "Failed to initialize curl\n");
        return 1;
    }

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);

    res = curl_easy_perform(curl);
    if(res!= CURLE_OK) {
        fprintf(stderr, "Failed to perform curl: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return 1;
    }

    printf("Received data:\n%s\n", chunk.memory);

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}
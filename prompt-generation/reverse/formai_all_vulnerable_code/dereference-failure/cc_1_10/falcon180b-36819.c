//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 2048
#define MAX_HEADER_SIZE 8192

struct MemoryStruct {
    char *memory;
    size_t size;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;
    mem->memory = realloc(mem->memory, mem->size + size * nmemb);
    if (mem->memory == NULL) {
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, size * nmemb);
    mem->size += size * nmemb;
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    char url[MAX_URL_SIZE];
    struct MemoryStruct chunk;

    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        chunk.memory = malloc(1);
        chunk.size = 0;

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", chunk.memory);
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);
    }

    curl_global_cleanup();

    return 0;
}
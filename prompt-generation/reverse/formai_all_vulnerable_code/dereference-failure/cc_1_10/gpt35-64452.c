//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("ERROR: Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

int main(int argc, char **argv)
{
    CURL *curl = NULL;
    int i = 0, num_urls = argc - 1;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;

    if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK) {
        printf("ERROR: Failed to initialize libcurl!\n");
        exit(EXIT_FAILURE);
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        for (i = 0; i < num_urls; ++i) {
            char *url = argv[i+1];
            if (strlen(url) > MAX_URL_LENGTH) {
                printf("ERROR: URL %s is too long!\n", url);
                continue;
            }

            curl_easy_setopt(curl, CURLOPT_URL, url);

            long http_code = 0;
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                printf("ERROR: libcurl failed to fetch URL %s: %s\n", url, curl_easy_strerror(res));
                continue;
            }

            res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if ((res == CURLE_OK) && (http_code == 200)) {
                printf("SUCCESS: URL %s is UP!\n", url);
            } else {
                printf("WARNING: URL %s returned HTTP code %ld\n", url, http_code);
            }

            chunk.size = 0;
            free(chunk.memory);
            chunk.memory = malloc(1);
        }

        curl_easy_cleanup(curl);
    } else {
        printf("ERROR: Failed to initialize libcurl!\n");
        exit(EXIT_FAILURE);
    }

     curl_global_cleanup();
     return 0;
}
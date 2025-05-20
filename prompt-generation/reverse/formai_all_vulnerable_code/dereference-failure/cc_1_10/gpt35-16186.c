//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define TIMEOUT 10L

struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if(mem->memory == NULL) {
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }

  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s [URL]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    CURL *curl_handle;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();
    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl_handle);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            exit(EXIT_FAILURE);
        }
        else {
            if (strstr(chunk.memory, "DOCTYPE html")) {
                printf("Website is up and running!\n");
                exit(EXIT_SUCCESS);
            }
            else {
                printf("Website is not working as expected!\n");
                exit(EXIT_FAILURE);
            }
        }

        curl_easy_cleanup(curl_handle);

        free(chunk.memory);

        curl_global_cleanup();

        return 0;
    }
    else {
        fprintf(stderr, "Failed to initialize CURL.\n");
        exit(EXIT_FAILURE);
    }
}
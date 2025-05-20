//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 1024
#define BUFFER_SIZE 1024 * 10

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char *url = NULL;
    struct MemoryStruct chunk;
    char *response = NULL;
    long response_code;
    double speed;

    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    url = argv[1];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    response = chunk.memory;
    response_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, NULL);

    if (response_code == 200) {
        speed = (double)chunk.size / curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, NULL);
        printf("Download speed: %.2f bytes/sec\n", speed);
    } else {
        printf("Failed to download URL: %s\n", url);
    }

    free(response);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}
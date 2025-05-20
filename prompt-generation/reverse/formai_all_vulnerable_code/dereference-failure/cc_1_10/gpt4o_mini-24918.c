//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to hold response data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Write callback function to capture the response from the server
size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, struct MemoryStruct *data) {
    size_t realsize = size * nmemb;
    data->memory = realloc(data->memory, data->size + realsize + 1);
    if (data->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(data->memory[data->size]), ptr, realsize);
    data->size += realsize;
    data->memory[data->size] = 0;
    return realsize;
}

// Will perform a GET request
void perform_get_request(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    // Initialize the memory structure
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        
        printf("Performing GET request to: %s\n", url);
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "GET request failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", chunk.memory);
        }

        // Clean up
        curl_easy_cleanup(curl);
        free(chunk.memory);
    }

    curl_global_cleanup();
}

// Will perform a POST request
void perform_post_request(const char *url, const char *data) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        printf("Performing POST request to: %s\n", url);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "POST request failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("POST request sent with data: %s\n", data);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <url> <get/post> [data]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    const char *method = argv[2];

    if (strcasecmp(method, "get") == 0) {
        perform_get_request(url);
    } else if (strcasecmp(method, "post") == 0 && argc == 4) {
        perform_post_request(url, argv[3]);
    } else {
        printf("Invalid method or missing data for POST request.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
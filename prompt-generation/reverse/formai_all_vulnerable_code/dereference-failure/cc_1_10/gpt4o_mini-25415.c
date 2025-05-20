//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to hold the response data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write data into the memory structure
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *mem) {
    size_t realsize = size * nmemb;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        // Out of memory
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0; // Null-terminate
    return realsize;
}

// Function to perform the HTTP GET request
void http_get(const char *url) {
    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  // Initial memory allocation
    chunk.size = 0;            // No data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        // Perform the request and get the response code
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("%s\n", chunk.memory); // Print the response
        }

        // Clean up
        curl_easy_cleanup(curl);
        free(chunk.memory);
    } else {
        fprintf(stderr, "Could not initialize curl.\n");
    }

    curl_global_cleanup();
}

// Main function to get the URL from the user and initiate the HTTP GET request
int main(void) {
    char url[256];

    printf("Enter the URL to request (e.g. http://example.com): ");
    if (fgets(url, sizeof(url), stdin) != NULL) {
        // Remove newline character if present
        url[strcspn(url, "\n")] = 0;

        http_get(url);
    } else {
        fprintf(stderr, "Error reading URL input.\n");
    }

    return 0;
}
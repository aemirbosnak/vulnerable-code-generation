//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Struct to hold the response data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write response data into a struct
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if(userp->memory == NULL) {
        printf("Not enough memory!\n");
        return 0; // Out of memory!
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // Null-terminate the string
    return realsize;
}

// Function to perform the HTTP GET request
void perform_http_get(const char *url) {
    CURL *curl_handle;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);  // Initial allocation
    chunk.size = 0;            // No data at this point

    curl_global_init(CURL_GLOBAL_ALL);
    
    // Initialize a curl session
    curl_handle = curl_easy_init();
    
    if(curl_handle) {
        // Set the URL for the GET request
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        
        // Set the write callback function
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        
        // Set the user pointer to our custom data
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
        
        // Perform the request, res will get the return code
        res = curl_easy_perform(curl_handle);
        
        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Output the response data
            printf("%s\n", chunk.memory);
        }
        
        // Cleanup
        curl_easy_cleanup(curl_handle);
        free(chunk.memory);
    }
    
    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];
    perform_http_get(url);
    return 0;
}
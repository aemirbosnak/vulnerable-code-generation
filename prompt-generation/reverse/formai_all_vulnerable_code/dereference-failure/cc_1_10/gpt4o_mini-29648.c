//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

// Function to handle the incoming data
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    
    if (userp->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }
    
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // Null-terminate the string

    return realsize;
}

// Fun main function with a warm welcome
int main(void) {
    printf("🎉 Welcome to the Cheerful HTTP Client! 🎉\n");
    printf("Please provide a URL to fetch its content: ");

    char url[256]; // To hold the URL input
    scanf("%255s", url); // Get the URL input from user

    CURL *curl_handle;
    CURLcode res;
    
    // Initialize curl and the memory structure
    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    
    MemoryStruct chunk;
    chunk.memory = malloc(1);  // Initial memory allocation
    chunk.size = 0;             // No data at this moment

    if (curl_handle) {
        // Setting the URL to fetch
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        
        // Pass the function to write data to
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        
        // Pass the structure with memory to write
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
        
        // Perform the request, res will get the return code
        res = curl_easy_perform(curl_handle);
        
        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("🎊 Here’s the content we've fetched: 🎊\n");
            printf("%s\n", chunk.memory);
        }
        
        // Clean up
        curl_easy_cleanup(curl_handle);
        free(chunk.memory);
    } else {
        printf("😢 Failed to initialize curl! Please check your installation.\n");
    }

    curl_global_cleanup();
    printf("Thank you for using our Cheerful HTTP Client! Goodbye! 🌈\n");
    
    return 0;
}
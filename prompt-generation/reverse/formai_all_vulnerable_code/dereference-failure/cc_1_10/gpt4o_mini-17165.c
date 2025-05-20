//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

// Structure to hold downloaded data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write the data received
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;
    return realsize;
}

// Function to perform the speed test
void speedTest(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    
    // Initialize the memory structure
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    // Initialize a curl session
    curl = curl_easy_init();
    if(curl) {
        // Set URL
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only want the speed, not the body

        // Perform the request
        printf("Starting speed test...\n");
        clock_t start = clock(); // Start measuring time
        res = curl_easy_perform(curl);
        clock_t end = clock(); // End measuring time

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Calculate time taken in seconds
            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

            // Get download speed in bytes per second
            double speed;
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);

            printf("Download speed: %.2f bytes/sec\n", speed);
            printf("Time taken: %.2f seconds\n", time_taken);
            printf("Total data received: %zu bytes\n", chunk.size);
        }

        // Cleanup
        free(chunk.memory);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main(void) {
    const char *testUrl = "http://speed.hetzner.de/100MB.bin"; // URL for a sample file
    speedTest(testUrl);
    return 0;
}
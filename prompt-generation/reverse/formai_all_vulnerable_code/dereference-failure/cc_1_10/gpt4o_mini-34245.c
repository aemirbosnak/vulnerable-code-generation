//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 4096

struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write data to memory
size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, struct MemoryStruct *data) {
    size_t realsize = size * nmemb;
    data->memory = realloc(data->memory, data->size + realsize + 1);
    if (data->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(data->memory[data->size]), ptr, realsize);
    data->size += realsize;
    data->memory[data->size] = 0; // null-terminate the string
    return realsize;
}

// Function to perform the speed test
void speedTest(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);  // initial allocation
    chunk.size = 0;            // no data at this point

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); // We want progress for the test
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);  // Set timeout

        clock_t start = clock(); // Start the clock
        res = curl_easy_perform(curl); // Perform the request
        clock_t end = clock(); // End the clock
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            double speed = chunk.size / (1024 * seconds); // speed in KB/s
            
            printf("Downloaded %lu bytes in %.2f seconds.\n", chunk.size, seconds);
            printf("Speed: %.2f KB/s\n", speed);
        }

        // Cleanup
        curl_easy_cleanup(curl);
        free(chunk.memory);
    }
    curl_global_cleanup();
}

int main() {
    char *url = "http://ipv4.download.thinkbroadband.com/10MB.zip"; // Change to appropriate URL

    printf("Starting Internet Speed Test...\n\n");
    speedTest(url);

    return 0;
}
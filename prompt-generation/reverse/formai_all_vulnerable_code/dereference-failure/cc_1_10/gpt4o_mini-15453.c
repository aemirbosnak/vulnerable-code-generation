//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

#define URL "http://www.google.com" // You can change this URL to test specific sites
#define BUFFER_SIZE 1024 * 1024 // 1 MB buffer

// Structure to hold the downloaded data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write data into MemoryStruct
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *pMem) {
    size_t realsize = size * nmemb;
    pMem->memory = realloc(pMem->memory, pMem->size + realsize + 1);
    if(pMem->memory == NULL) {
        printf("Not enough memory for allocation\n");
        return 0; // Out of memory
    }
    memcpy(&(pMem->memory[pMem->size]), contents, realsize);
    pMem->size += realsize;
    pMem->memory[pMem->size] = 0; // Null-terminate
    return realsize;
}

// Function to perform speed test
void speed_test() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    struct timeval start, end;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

        gettimeofday(&start, NULL); // Start time

        res = curl_easy_perform(curl); // Perform the request

        gettimeofday(&end, NULL); // End time

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
            double speed = (chunk.size / (1024.0 * 1024.0)) / elapsed_time; // Convert to MB/s
            printf("Download speed: %.2f MB/s\n", speed);
        }

        free(chunk.memory);
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
}

int main() {
    printf("Starting Internet Speed Test...\n");
    speed_test();
    return 0;
}
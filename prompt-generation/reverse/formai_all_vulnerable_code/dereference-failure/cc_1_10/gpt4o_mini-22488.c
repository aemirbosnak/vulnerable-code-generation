//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <curl/curl.h>

#define BUFFER_SIZE 8192
#define DOWNLOAD_URL "http://example.com/testfile" // Replace with a valid test file URL
#define UPLOAD_URL "http://example.com/upload" // Replace with a valid upload URL

// Struct to hold the file content
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Write callback function to store downloaded data
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Failed to allocate memory!\n");
        return 0;
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // Null-terminate
    return realsize;
}

// Function to measure download speed
double measure_download_speed() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  // Initial allocation
    chunk.size = 0;            // No data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        
        // Start timer
        clock_t start_time = clock();
        
        res = curl_easy_perform(curl);
        
        // End timer
        clock_t end_time = clock();
        
        // Calculate time taken in seconds
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        
        // Calculate download speed in MB/s
        double speed = (chunk.size / (1024.0 * 1024.0)) / time_taken; // Megabytes per second
        
        printf("Download speed: %.2f MB/s\n", speed);
        
        // Cleanup
        curl_easy_cleanup(curl);
        free(chunk.memory);
    }

    curl_global_cleanup();
    return 0;
}

// Function to measure upload speed
double measure_upload_speed() {
    CURL *curl;
    CURLcode res;
    const char *data = "This is a test upload"; // Example data
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Expect:");
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(data));
        
        // Start timer
        clock_t start_time = clock();
        
        res = curl_easy_perform(curl);
        
        // End timer
        clock_t end_time = clock();
        
        // Calculate time taken in seconds
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        
        // Calculate upload speed in MB/s
        double speed = (strlen(data) / (1024.0 * 1024.0)) / time_taken; // Megabytes per second

        printf("Upload speed: %.2f MB/s\n", speed);

        // Cleanup
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
    return 0;
}

// Main function
int main() {
    printf("=== Internet Speed Test ===\n");
    measure_download_speed();
    measure_upload_speed();
    return 0;
}
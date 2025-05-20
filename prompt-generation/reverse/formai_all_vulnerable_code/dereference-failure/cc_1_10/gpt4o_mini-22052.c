//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>
#include <stdbool.h>

#define TEST_FILE "https://speed.hetzner.de/100MB.bin" // URL to test download speed
#define UPLOAD_URL "http://www.example.com/upload" // Placeholder URL for upload speed
#define BUFFER_SIZE 8192

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

// Function to write the downloaded data into memory
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        fprintf(stderr, "Not enough memory to allocate!\n");
        return 0; // Out of memory!
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // Null-terminate
    return realsize;
}

// Function to test download speed
double test_download_speed() {
    CURL *curl;
    CURLcode res;
    MemoryStruct chunk;
    
    chunk.memory = malloc(1);  // Initial allocation
    chunk.size = 0;            // No data at this point

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, TEST_FILE);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        
        // Measure time taken to download
        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        double duration = (double)(end - start) / CLOCKS_PER_SEC;
        double speed = (double)chunk.size / duration / 1024; // KB/s
        
        curl_easy_cleanup(curl);
        free(chunk.memory);
        
        return speed;
    }
    
    return -1.0; // Indicate failure
}

// Function to test upload speed
double test_upload_speed() {
    CURL *curl;
    CURLcode res;
    char *data = malloc(BUFFER_SIZE);
    
    // Fill data with random values
    for (int i = 0; i < BUFFER_SIZE; i++) {
        data[i] = 'A' + (rand() % 26); // Random uppercase letter
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        
        // Measure time taken to upload
        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        double duration = (double)(end - start) / CLOCKS_PER_SEC;
        double speed = (double)BUFFER_SIZE / duration / 1024; // KB/s
        
        curl_easy_cleanup(curl);
        free(data);

        return speed;
    }
    
    free(data);
    return -1.0; // Indicate failure
}

int main() {
    double download_speed, upload_speed;

    printf("Testing Internet Speed...\n");
    
    download_speed = test_download_speed();
    if (download_speed < 0) {
        printf("Download speed test failed.\n");
        return EXIT_FAILURE;
    } else {
        printf("Download Speed: %.2f KB/s\n", download_speed);
    }
    
    upload_speed = test_upload_speed();
    if (upload_speed < 0) {
        printf("Upload speed test failed.\n");
        return EXIT_FAILURE;
    } else {
        printf("Upload Speed: %.2f KB/s\n", upload_speed);
    }

    printf("Test completed successfully.\n");
    return EXIT_SUCCESS;
}
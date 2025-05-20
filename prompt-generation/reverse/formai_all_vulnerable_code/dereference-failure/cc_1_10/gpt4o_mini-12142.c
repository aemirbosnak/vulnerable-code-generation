//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define BUFFER_SIZE 1024

struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write data into memory
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t totalSize = size * nmemb;
    char *ptr = realloc(userp->memory, userp->size + totalSize + 1);
    
    if(ptr == NULL) {
        printf("Not enough memory!\n");
        return 0; // Out of memory
    }
    
    userp->memory = ptr;
    memcpy(&(userp->memory[userp->size]), contents, totalSize);
    userp->size += totalSize;
    userp->memory[userp->size] = 0;

    return totalSize;
}

// Function to perform the speed test
double perform_speed_test(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct data;
    data.memory = malloc(1); // Initial allocation
    data.size = 0; // No data yet

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Don't need body for speed test

        time_t start_time = time(NULL);
        res = curl_easy_perform(curl);
        time_t end_time = time(NULL);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        double total_time = difftime(end_time, start_time);
        double download_speed = (data.size / (1024.0 * 1024.0)) / total_time; // MBps

        // Convert to Mbps
        download_speed *= 8.0; // Convert to Mbps

        printf("Download Speed: %.2f Mbps\n", download_speed);

        curl_easy_cleanup(curl);
        free(data.memory);
        return download_speed;
    }
    return 0.0;
}

int main(void) {
    const char *test_url = "http://ipv4.download.thinkbroadband.com/5MB.zip"; // Test file URL
    printf("Starting internet speed test...\n");
    double speed = perform_speed_test(test_url);

    if(speed > 0) {
        printf("Speed test completed successfully.\n");
    } else {
        printf("Speed test encountered an error.\n");
    }
    
    return 0;
}
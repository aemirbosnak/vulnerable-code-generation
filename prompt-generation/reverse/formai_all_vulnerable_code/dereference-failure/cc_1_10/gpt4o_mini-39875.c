//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Structure to hold downloaded data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function for writing data received from CURL
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

// Function to perform a speed test by downloading a file
double performSpeedTest(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    
    chunk.memory = malloc(1);  // initial empty memory
    chunk.size = 0;            // no data at this point

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); // Disable progress indicator

        time_t start = time(NULL);
        res = curl_easy_perform(curl);
        time_t end = time(NULL);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double total_time = difftime(end, start);
            printf("Downloaded %lu bytes in %f seconds.\n", chunk.size, total_time);
            
            if (total_time > 0) {
                double speed = (chunk.size / 1024.0 / total_time); // in KB/s
                printf("Speed: %.2f KB/s\n", speed);
            }
        }

        // Cleanup
        free(chunk.memory);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}

// Main function
int main(void) {
    const char *test_url = "http://ipv4.download.thinkbroadband.com/1MB.zip"; // A test file URL
    
    printf("====================================\n");
    printf("        Internet Speed Test         \n");
    printf("====================================\n");
    printf("Testing from URL: %s\n", test_url);
    
    performSpeedTest(test_url);
    
    printf("====================================\n");
    printf("             Test Complete         \n");
    printf("====================================\n");

    return 0;
}
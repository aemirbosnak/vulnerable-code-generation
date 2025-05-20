//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 8192

// Structure to hold downloaded data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function for curl
static size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, struct MemoryStruct *data) {
    size_t realsize = size * nmemb;
    data->memory = realloc(data->memory, data->size + realsize + 1);
    if (data->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }
    memcpy(&(data->memory[data->size]), ptr, realsize);
    data->size += realsize;
    data->memory[data->size] = 0;

    return realsize;
}

// Function to test download speed
double test_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct data;
    data.memory = malloc(1);  // Initial allocation
    data.size = 0;            // No data yet

    curl = curl_easy_init();
    if(curl) {
        struct timeval start, end;

        // Start the timer
        gettimeofday(&start, NULL);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // End the timer
        gettimeofday(&end, NULL);

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0;      // seconds to milliseconds
        elapsed_time += (end.tv_usec - start.tv_usec) / 1000.0;          // us to ms

        double speed_mbps = (data.size * 8) / (elapsed_time * 1000); // bits per millisecond to Mbps
        free(data.memory);
        curl_easy_cleanup(curl);

        return speed_mbps;
    }
    return 0.0; // Return 0 if curl initialization fails
}

int main() {
    const char *url = "http://www.example.com"; // URL for testing
    printf("Thank you for using the Internet Speed Test Application!\n");
    printf("Testing download speed, please wait...\n");
    
    double speed = test_download_speed(url);
    
    if (speed > 0) {
        printf("Download Speed: %.2f Mbps\n", speed);
    } else {
        printf("An error occurred while testing the speed.\n");
    }
    
    printf("Your connection speed is very valuable; thank you for testing!\n");
    return 0;
}
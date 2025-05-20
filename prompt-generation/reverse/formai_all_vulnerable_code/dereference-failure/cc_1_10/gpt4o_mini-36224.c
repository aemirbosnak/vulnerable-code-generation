//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <curl/curl.h>

// Structure to hold the downloaded data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function writes data to the MemoryStruct
size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, struct MemoryStruct *data) {
    size_t realsize = size * nmemb;
    data->memory = realloc(data->memory, data->size + realsize + 1);
    if(data->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;  // Out of memory!
    }
    memcpy(&(data->memory[data->size]), ptr, realsize);
    data->size += realsize;
    data->memory[data->size] = 0;  // Null-terminate
    return realsize;
}

// Function to perform an internet speed test
void performSpeedTest(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct data;

    data.memory = malloc(1);  // Initial allocation
    data.size = 0;            // No data at this point

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        struct timeval start, end;
        gettimeofday(&start, NULL);

        res = curl_easy_perform(curl);
        gettimeofday(&end, NULL);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
            double speed = (data.size / 1024.0) / elapsed; // KBytes per second
            printf("Downloaded %zu bytes in %f seconds\n", data.size, elapsed);
            printf("Speed: %.2f KBytes/s\n", speed);
        }

        // Cleanup
        curl_easy_cleanup(curl);
        free(data.memory);
    }
}

int main(void) {
    const char *url = "http://speed.hetzner.de/100MB.bin"; // A sample URL from which to download
    printf("Starting Internet Speed Test...\n");
    performSpeedTest(url);
    printf("Test completed.\n");
    return 0;
}
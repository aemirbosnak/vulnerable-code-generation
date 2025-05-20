//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "http://ipv4.download.thinkbroadband.com/10MB.zip" // A file to download
#define BUFFER_SIZE (1024 * 1024) // 1MB buffer size
#define MAX_ITERATIONS 5

// Struct for managing download progress
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function for write operation
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
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

// Function to measure download speed
void test_download_speed() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    
    chunk.memory = malloc(1);  // initial allocation
    chunk.size = 0;            // no data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Starts timing
        double start, end;
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &start);
        
        res = curl_easy_perform(curl);

        // End timing
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &end);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double speed = (chunk.size / 1024.0) / end; // in KB/s
            printf("Downloaded %zu bytes in %.2f seconds (Speed: %.2f KB/s)\n", 
                    chunk.size, end, speed);
        }
        
        // Cleanup
        free(chunk.memory);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    printf("Welcome to the Internet Speed Test Application!\n");

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        printf("Starting test #%d...\n", i + 1);
        test_download_speed();
        sleep(2); // Wait 2 seconds before next test
    }

    printf("Speed tests complete. Thank you for using our service!\n");
    
    return 0;
}
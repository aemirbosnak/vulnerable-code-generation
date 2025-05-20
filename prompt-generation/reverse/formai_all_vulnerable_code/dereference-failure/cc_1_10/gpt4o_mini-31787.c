//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

#define URL "http://www.google.com"
#define BUFFER_SIZE 1024

// Structure to hold download data
struct download_data {
    char *buffer;
    size_t size;
};

// Function to write received data
size_t write_callback(void *ptr, size_t size, size_t nmemb, struct download_data *data) {
    size_t total_size = size * nmemb;
    char *ptr_new = realloc(data->buffer, data->size + total_size + 1);
    if (ptr_new == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    data->buffer = ptr_new;
    memcpy(data->buffer + data->size, ptr, total_size);
    data->size += total_size;
    data->buffer[data->size] = '\0';
    return total_size;
}

// Function to test internet speed
void test_internet_speed() {
    CURL *curl;
    CURLcode res;
    struct download_data data;

    // Initialize the download data structure
    data.buffer = malloc(1);  // initial allocation
    data.buffer[0] = '\0';     // null-terminate the string
    data.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); // Disable progress meter

        struct timeval start, end;
        gettimeofday(&start, NULL); // Start time

        res = curl_easy_perform(curl);
        
        gettimeofday(&end, NULL); // End time
        long seconds = end.tv_sec - start.tv_sec;
        long micros = end.tv_usec - start.tv_usec;
        double elapsed = seconds + micros * 1e-6;

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Downloaded %zu bytes in %.2f seconds\n", data.size, elapsed);
            double speed = (data.size / 1024.0) / elapsed; // Convert size to KB
            printf("Your speed is: %.2f KB/s\n", speed);
        }

        free(data.buffer); // Free allocated buffer
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// Main function
int main(int argc, char *argv[]) {
    printf("Welcome to the Internet Speed Test!\n");
    printf("Hold your breath and let's begin...\n");

    // Wait few seconds to build suspense
    for(int i = 3; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }

    printf("Testing your internet speed, please wait...\n\n");

    test_internet_speed();

    printf("\nThank you for using the Internet Speed Test application!\n");
    printf("Remember, speed may vary based on various factors...\n");
    
    return 0;
}
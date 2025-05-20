//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define CHUNK_SIZE 256

// Struct to hold the response data for download
struct MemoryChunk {
    char *memory;
    size_t size;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, struct MemoryChunk *chunk) {
    size_t realsize = size * nmemb;
    chunk->memory = realloc(chunk->memory, chunk->size + realsize + 1);
    if (chunk->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;  // Out of memory
    }
    memcpy(&(chunk->memory[chunk->size]), ptr, realsize);
    chunk->size += realsize;
    chunk->memory[chunk->size] = 0; // Null-terminate the string
    return realsize;
}

// Function to download a file and measure download speed
double measure_download_speed(const char *url, size_t data_size) {
    CURL *curl;
    CURLcode res;
    struct MemoryChunk chunk = {0};
    double time_taken;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // Configure curl options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

        // Start measuring time
        clock_t start_time = clock();

        // Perform the download
        res = curl_easy_perform(curl);

        // Stop measuring time
        clock_t end_time = clock();
        time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            free(chunk.memory);
            curl_easy_cleanup(curl);
            return -1;
        }

        // Calculate download speed (bytes per second)
        double download_speed = (chunk.size / 1024.0) / time_taken; // KB/s

        free(chunk.memory);
        curl_easy_cleanup(curl);
        curl_global_cleanup();

        return download_speed;
    }
    return -1;
}

// Function to upload data and measure upload speed
double measure_upload_speed(const char *url, size_t data_size) {
    CURL *curl;
    CURLcode res;
    char *data = malloc(data_size);
    double time_taken;

    if (data == NULL) {
        fprintf(stderr, "Failed to allocate memory for upload data\n");
        return -1;
    }

    // Fill data with dummy content
    memset(data, 'A', data_size);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // Configure curl options for upload
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data_size);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

        // Start measuring time
        clock_t start_time = clock();

        // Perform the upload
        res = curl_easy_perform(curl);

        // Stop measuring time
        clock_t end_time = clock();
        time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            free(data);
            curl_easy_cleanup(curl);
            return -1;
        }

        // Calculate upload speed (bytes per second)
        double upload_speed = (data_size / 1024.0) / time_taken; // KB/s

        free(data);
        curl_easy_cleanup(curl);
        curl_global_cleanup();

        return upload_speed;
    }
    free(data);
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <url> <data_size_kb>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    size_t data_size_kb = atoi(argv[2]);
    size_t data_size = data_size_kb * 1024;  // Convert to bytes

    // Measure download speed
    double download_speed = measure_download_speed(url, data_size);
    if (download_speed >= 0) {
        printf("Download Speed: %.2f KB/s\n", download_speed);
    } else {
        fprintf(stderr, "Download speed test failed.\n");
    }

    // Measure upload speed
    double upload_speed = measure_upload_speed(url, data_size);
    if (upload_speed >= 0) {
        printf("Upload Speed: %.2f KB/s\n", upload_speed);
    } else {
        fprintf(stderr, "Upload speed test failed.\n");
    }

    return EXIT_SUCCESS;
}
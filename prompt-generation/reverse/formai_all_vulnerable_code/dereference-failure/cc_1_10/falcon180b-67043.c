//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024 * 1024 // 1 MB buffer

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_address> <file_size_in_mb>\n", argv[0]);
        return 1;
    }

    char server_address[1024];
    strcpy(server_address, argv[1]);

    int file_size_in_mb = atoi(argv[2]);

    // Create a unique file name for the download
    char file_name[1024];
    sprintf(file_name, "speed_test_%d.bin", rand());

    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error: could not create file %s\n", file_name);
        return 1;
    }

    // Initialize curl
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error: could not initialize curl\n");
        return 1;
    }

    // Set the server address
    curl_easy_setopt(curl, CURLOPT_URL, server_address);

    // Set the file name for the download
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // Set the buffer size
    curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, BUFFER_SIZE);

    // Set the file size
    curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)file_size_in_mb * 1024 * 1024);

    // Perform the download
    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Error: %s\n", curl_easy_strerror(res));
        return 1;
    }

    // Close the file and curl
    fclose(fp);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    printf("Download completed successfully\n");
    return 0;
}
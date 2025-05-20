//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function for receiving data from the server
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char *)userp)[size * nmemb - 1] = '\0'; // Add null terminator
    return size * nmemb; // Return number of bytes written
}

// Callback function for handling progress updates
int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    int id = *((int *)clientp); // Get the ID associated with this transfer
    printf("Transfer %d: %ld bytes downloaded, %ld bytes uploaded\n", id, dlnow, ulnow);
    return 0;
}

// Function for making a GET request to a specified URL
void MakeGetRequest(const char *url, int id) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT); // Initialize the libcurl library
    curl = curl_easy_init(); // Initialize a new CURL handle
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url); // Set the URL to request
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); // Set the callback function for receiving data
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &id); // Set the user data for the callback function
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L); // Disable progress updates
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback); // Set the callback function for progress updates
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &id); // Set the user data for the progress callback function
        res = curl_easy_perform(curl); // Perform the request
        if (res!= CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res)); // Handle any errors that occur
        }
        curl_easy_cleanup(curl); // Clean up the CURL handle
        curl_global_cleanup(); // Clean up the libcurl library
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s URL [ID]\n", argv[0]);
        return 1;
    }
    const char *url = argv[1];
    int id = 0;
    if (argc > 2) {
        id = atoi(argv[2]);
    }
    MakeGetRequest(url, id);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024 * 1024

// Structure to store HTTP response
typedef struct {
    char *url;
    char *response;
    long response_code;
} HTTPResponse;

// Function to free the memory allocated for the HTTP response
void free_http_response(HTTPResponse *response) {
    free(response->url);
    free(response->response);
    free(response);
}

// Function to send an HTTP GET request and store the response
HTTPResponse *send_http_get_request(const char *url) {
    CURL *curl;
    CURLcode res;
    HTTPResponse *response = malloc(sizeof(HTTPResponse));

    // Initialize the curl session
    curl = curl_easy_init();

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the maximum allowed response size
    curl_easy_setopt(curl, CURLOPT_MAXFILESIZE, MAX_RESPONSE_LENGTH);

    // Create a buffer to store the response
    response->response = malloc(MAX_RESPONSE_LENGTH);

    // Set the callback function to write the response to the buffer
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response->response);

    // Perform the HTTP request
    res = curl_easy_perform(curl);

    // Get the response code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response->response_code);

    // Clean up the curl session
    curl_easy_cleanup(curl);

    // Store the requested URL
    response->url = strdup(url);

    // Return the HTTP response
    return response;
}

// Function to print the HTTP response
void print_http_response(HTTPResponse *response) {
    printf("URL: %s\n", response->url);
    printf("Response code: %ld\n", response->response_code);
    printf("Response: %s\n", response->response);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    // Send the HTTP GET request
    HTTPResponse *response = send_http_get_request(argv[1]);

    // Print the HTTP response
    print_http_response(response);

    // Free the memory allocated for the HTTP response
    free_http_response(response);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 4096
#define FUNNY_URL "http://api.chucknorris.io/jokes/random"

// Structure to hold the response data
struct Response {
    char *memory;
    size_t size;
};

// Callback function to write response data into the response structure
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct Response *response) {
    size_t realsize = size * nmemb;
    response->memory = realloc(response->memory, response->size + realsize + 1);
    
    if (response->memory == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        return 0; // Out of memory, stop the operation
    }
    
    memcpy(&(response->memory[response->size]), contents, realsize);
    response->size += realsize;
    response->memory[response->size] = '\0'; // Null-terminate the string

    return realsize;
}

// Function to perform the silly HTTP request
void silly_http_request() {
    CURL *curl;
    CURLcode res;
    struct Response response;

    // Initialize response data
    response.memory = malloc(1); // Cannot be NULL
    response.memory[0] = '\0';
    response.size = 0;

    // Set up the CURL (curl for silly HTTP requests)
    curl = curl_easy_init();
    if (curl) {
        // Set the URL that we're going to mock
        curl_easy_setopt(curl, CURLOPT_URL, FUNNY_URL);
        
        // Use our callback function to handle the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
        
        // Enable verbose output
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // Perform the HTTP request
        res = curl_easy_perform(curl);
        
        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Output the retrieved joke
            printf("Here's a funny joke for you: %s\n", response.memory);
        }

        // Clean up CURL resources
        curl_easy_cleanup(curl);
    }

    // Free response memory
    free(response.memory);
}

// Main function to run the silly client
int main(void) {
    printf("Welcome to SillyHTTPClient! Ready to send hilarious requests.\n");
    printf("Let's see if Chuck Norris is in a joking mood...\n");
    silly_http_request();
    printf("Goodbye from SillyHTTPClient! Remember, laughter is the best medicine. Unless you need actual medicine!\n");
    
    return 0;
}
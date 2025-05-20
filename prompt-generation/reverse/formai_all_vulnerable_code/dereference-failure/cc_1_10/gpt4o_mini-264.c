//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// This structure will hold the data we receive from the server
struct Memory {
    char *response;
    size_t size;
};

// Callback function to write the response into our Memory structure
static size_t write_callback(void *ptr, size_t size, size_t nmemb, struct Memory *mem) {
    size_t realsize = size * nmemb;
    char *ptr_realloc = realloc(mem->response, mem->size + realsize + 1);
    if (ptr_realloc == NULL) {
        printf("Not enough memory to allocate buffer.\n");
        return 0; // Out of memory
    }

    mem->response = ptr_realloc;
    memcpy(&(mem->response[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->response[mem->size] = '\0'; // Null-terminate the string

    return realsize;
}

// Function to perform an HTTP GET request
void http_get(const char *url) {
    CURL *curl;
    CURLcode res;
    struct Memory chunk = {.response = malloc(1), .size = 0}; // Initialize Memory structure

    if (chunk.response == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return;
    }

    curl = curl_easy_init(); // Initialize a CURL easy session
    if(curl) {
        // Set CURL options
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Output the received data
            printf("Response:\n%s\n", chunk.response);
        }

        // Clean up
        curl_easy_cleanup(curl);
        free(chunk.response); // Free the allocated buffer
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize library (optional but recommended for thread-safety)
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    // Perform the HTTP GET request
    http_get(argv[1]);
    
    // Cleanup global CURL settings
    curl_global_cleanup();

    return EXIT_SUCCESS;
}
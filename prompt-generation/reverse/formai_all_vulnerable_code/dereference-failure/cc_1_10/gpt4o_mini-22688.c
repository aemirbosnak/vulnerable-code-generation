//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 2048

// Structure to hold the response data
struct memory {
    char *response;
    size_t size;
};

// Callback function to write the response data into memory
size_t write_callback(void *ptr, size_t size, size_t nmemb, struct memory *mem) {
    size_t realsize = size * nmemb;
    char *ptr_realloc = realloc(mem->response, mem->size + realsize + 1);
    
    if(ptr_realloc == NULL) {
        // Out of memory!
        printf("Not enough memory to realloc\n");
        return 0;
    }
    
    mem->response = ptr_realloc;
    memcpy(&(mem->response[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;  // Null-terminate the string

    return realsize;
}

// Function to initialize the memory structure
struct memory *init_memory() {
    struct memory *mem = malloc(sizeof(struct memory));
    if(mem == NULL) {
        perror("Failed to allocate memory for response structure");
        exit(EXIT_FAILURE);
    }
    mem->response = malloc(1); // Initialize to an empty string
    mem->response[0] = '\0';
    mem->size = 0;
    return mem;
}

// Function to perform a GET request
void perform_get_request(const char *url) {
    CURL *curl;
    CURLcode res;
    struct memory *chunk = init_memory();

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("%s\n", chunk->response);
        }

        curl_easy_cleanup(curl);
    }

    free(chunk->response);
    free(chunk);
    curl_global_cleanup();
}

// Main function
int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char url[MAX_URL_LENGTH];
    strncpy(url, argv[1], MAX_URL_LENGTH);
    url[MAX_URL_LENGTH - 1] = '\0'; // Ensure null termination

    // Perform the GET request
    perform_get_request(url);

    return EXIT_SUCCESS;
}
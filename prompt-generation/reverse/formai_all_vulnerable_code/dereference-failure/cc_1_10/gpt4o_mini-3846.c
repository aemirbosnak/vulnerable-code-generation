//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LEN 2048
#define MAX_RESPONSE_LEN 8192

// Struct for holding the response data
struct MemoryStruct {
    char *memory; // Pointer to the response data
    size_t size;  // Size of the memory used
};

// Callback function to handle the data received from the HTTP response
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *mem) {
    size_t realsize = size * nmemb; // calculate the real size of the incoming data
    mem->memory = realloc(mem->memory, mem->size + realsize + 1); // allocating more memory
    if (mem->memory == NULL) {
        printf("Not enough memory!\n");
        return 0; // out of memory!
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize); // copy contents into memory
    mem->size += realsize; // update the overall size
    mem->memory[mem->size] = 0; // null-terminate the string

    return realsize;
}

// Function to perform GET request
void perform_get_request(const char *url) {
    CURL *curl; // Curl instance pointer
    CURLcode res; // Curl return code
    struct MemoryStruct chunk; // Memory structure to hold response data

    chunk.memory = malloc(1); // initial allocation of 1 byte for the response holder
    chunk.size = 0; // initial size of response is 0

    curl_global_init(CURL_GLOBAL_ALL); // initializing global environment for curl
    curl = curl_easy_init(); // initialize curl

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url); // setting the URL
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback); // setting the callback function
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk); // setting the data to be passed to the callback
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0"); // setting a user agent
        
        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for CURL errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Print the resulting data
            printf("%lu bytes retrieved:\n", (unsigned long)chunk.size);
            printf("%s\n", chunk.memory);
        }

        // Clean up
        curl_easy_cleanup(curl);
        free(chunk.memory); // free the response data
    }

    curl_global_cleanup(); // clean up global curl environment
}

int main(int argc, char *argv[]) {
    char url[MAX_URL_LEN]; // buffer to store URL

    // Prompt for URL input from the user
    printf("Enter a URL to perform a GET request (max %d characters): ", MAX_URL_LEN - 1);
    fgets(url, sizeof(url), stdin); // read the input
    url[strcspn(url, "\n")] = '\0'; // remove trailing newline character

    // Validate the URL length
    if (strlen(url) <= 0 || strlen(url) > MAX_URL_LEN) {
        fprintf(stderr, "Invalid URL length\n");
        return EXIT_FAILURE; // exit with error
    }

    // Perform GET request
    perform_get_request(url);

    return EXIT_SUCCESS; // successful execution
}
//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define our callback function (called for every chunk of data received)
static size_t write_callback(char *buffer, size_t size, size_t nmemb, void *userp)
{
    char **response_ptr = userp;  // Pointer to the response string we want to build

    size_t real_size = size * nmemb;  // Calculate the real size of the chunk (in bytes)
    
    // Allocate memory to hold the received data (plus one byte for the terminating null character)
    *response_ptr = realloc(*response_ptr, strlen(*response_ptr) + real_size + 1);
    
    // Copy the chunk of data into our response string
    memcpy(*response_ptr + strlen(*response_ptr), buffer, real_size);
    
    // Null terminate the response string
    (*response_ptr)[strlen(*response_ptr) + real_size] = '\0';
    
    return real_size;  // Return the size of the chunk (in bytes)
}

int main()
{
    CURL *curl;  // Define a curl object
    
    // Initialize curl
    if ((curl = curl_easy_init()) == NULL)
    {
        printf("Failed to initialize curl\n");
        return EXIT_FAILURE;
    }
    
    char *url = "http://www.example.com";  // Define the URL we want to request
    
    // Set the URL to request
    curl_easy_setopt(curl, CURLOPT_URL, url);
    
    // Set the callback function to handle the data received
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    
    char *response = malloc(1);  // Allocate memory for our response string
    response[0] = '\0';  // Initialize the response string as an empty string
    
    // Set the userpointer for the callback function to our response string
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    
    CURLcode res;  // Define a variable to hold the result of the curl operation
    
    // Perform the curl operation
    if ((res = curl_easy_perform(curl)) != CURLE_OK)
    {
        printf("Failed to perform curl operation: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }
    
    // Print the received data
    printf("Received data:\n%s\n", response);
    
    // Cleanup curl and the response string
    curl_easy_cleanup(curl);
    free(response);
    
    return EXIT_SUCCESS;
}
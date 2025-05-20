//Gemma-7B DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL "localhost:8080/api/users"

int main()
{
    CURL *curl;
    CURLcode res;
    struct curl_easy *easy;
    char *data;

    // Allocate memory for the data
    data = malloc(10);
    if (data == NULL)
    {
        return EXIT_FAILURE;
    }

    // Initialize the curl library
    curl = curl_easy_init();
    if (curl == NULL)
    {
        return EXIT_FAILURE;
    }

    // Create an easy handle
    easy = curl_easy_init();
    curl_easy_setopt(easy, CURLOPT_URL, URL);
    curl_easy_setopt(easy, CURLOPT_POST, 1);
    curl_easy_setopt(easy, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(easy, CURLOPT_FOLLOWLOCATION, 1);

    // Perform the request
    res = curl_easy_perform(easy);

    // Check for errors
    if (res != CURLE_OK)
    {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }

    // Free the allocated memory
    free(data);

    // Close the easy handle and curl library
    curl_easy_cleanup(easy);
    curl_easy_cleanup(curl);

    return EXIT_SUCCESS;
}
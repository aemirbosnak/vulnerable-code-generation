//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

// Function to sanitize a URL
char *sanitize_url(const char *url)
{
    // Allocate memory for the sanitized URL
    char *sanitized_url = malloc(strlen(url) + 1);
    if (!sanitized_url)
        return NULL;

    // Copy the original URL into the sanitized version
    strcpy(sanitized_url, url);

    // Remove any leading or trailing whitespace
    while (*sanitized_url && isspace(*sanitized_url))
        sanitized_url++;
    while (*sanitized_url && isspace(sanitized_url[strlen(sanitized_url) - 1]))
        sanitized_url[strlen(sanitized_url) - 1] = '\0';

    // Replace any non-alphanumeric characters with underscores
    for (char *c = sanitized_url; *c; c++)
        if (!isalnum(*c))
            *c = '_';

    // Return the sanitized URL
    return sanitized_url;
}

// Function to make a GET request to a URL
CURLcode make_get_request(const char *url, char **response)
{
    // Initialize the Curl instance
    CURL *curl = curl_easy_init();
    if (!curl)
        return CURLE_FAILED_INIT;

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the response buffer
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

    // Perform the GET request
    CURLcode res = curl_easy_perform(curl);

    // Cleanup the Curl instance
    curl_easy_cleanup(curl);

    // Return the result
    return res;
}

int main(int argc, char **argv)
{
    // Check if the user has provided a URL
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Sanitize the URL
    char *sanitized_url = sanitize_url(argv[1]);
    if (!sanitized_url)
    {
        fprintf(stderr, "Failed to sanitize URL\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the response
    char *response = malloc(1024);
    if (!response)
    {
        fprintf(stderr, "Failed to allocate memory for response\n");
        free(sanitized_url);
        return EXIT_FAILURE;
    }

    // Make the GET request
    CURLcode res = make_get_request(sanitized_url, &response);
    if (res != CURLE_OK)
    {
        fprintf(stderr, "Failed to make GET request: %s\n", curl_easy_strerror(res));
        free(sanitized_url);
        free(response);
        return EXIT_FAILURE;
    }

    // Print the response
    printf("%s", response);

    // Cleanup
    free(sanitized_url);
    free(response);

    return EXIT_SUCCESS;
}
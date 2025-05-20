//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Custom error handler
void error_handler(CURLcode code, const char *url)
{
    fprintf(stderr, "CURL error (%d): %s\n", code, curl_easy_strerror(code));
    fprintf(stderr, "URL: %s\n", url);
    exit(EXIT_FAILURE);
}

// Custom write function to validate and sanitize incoming data
size_t write_and_sanitize(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    char *data = (char *)ptr;
    size_t data_size = size * nmemb;

    // Check for invalid characters
    for (size_t i = 0; i < data_size; i++)
    {
        if (!isalnum(data[i]) && data[i] != '_' && data[i] != '-' && data[i] != '.')
        {
            fprintf(stderr, "Invalid character detected: %c\n", data[i]);
            exit(EXIT_FAILURE);
        }
    }

    // Allow only specific protocols
    char *protocol_start = strstr(data, "://");
    if (protocol_start == NULL)
    {
        fprintf(stderr, "No protocol specified\n");
        exit(EXIT_FAILURE);
    }
    char *protocol_end = strchr(protocol_start + 3, '/');
    if (protocol_end == NULL)
    {
        fprintf(stderr, "Invalid protocol format\n");
        exit(EXIT_FAILURE);
    }
    char *protocol = strndup(protocol_start + 3, protocol_end - protocol_start - 3);
    if (strcmp(protocol, "http") != 0 && strcmp(protocol, "https") != 0)
    {
        fprintf(stderr, "Only HTTP and HTTPS protocols are allowed\n");
        exit(EXIT_FAILURE);
    }
    free(protocol);

    // Append the sanitized data to the userdata buffer
    char **sanitized_data = (char **)userdata;
    *sanitized_data = realloc(*sanitized_data, strlen(*sanitized_data) + data_size + 1);
    strcat(*sanitized_data, data);

    return data_size;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s [URL]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize libcurl
    curl = curl_easy_init();
    if (curl == NULL)
    {
        error_handler(res, argv[1]);
    }

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Set the error handler
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_handler);

    // Set the write function to sanitize incoming data
    char *sanitized_data = malloc(1);
    *sanitized_data = '\0';
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_and_sanitize);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sanitized_data);

    // Perform the request
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        error_handler(res, argv[1]);
    }

    // Print the sanitized data
    printf("%s\n", sanitized_data);

    // Cleanup
    free(sanitized_data);
    curl_easy_cleanup(curl);

    return EXIT_SUCCESS;
}
//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

/*
 * Structure to hold the response data from the HTTP request
 */
struct ResponseData {
    char *data;
    size_t size;
};

/*
 * Callback function to handle data received from curl
 */
size_t WriteCallback(void *ptr, size_t size, size_t nmemb, struct ResponseData *data) {
    size_t totalSize = size * nmemb;

    // Grow the memory for the response data buffer
    char *tmp = realloc(data->data, data->size + totalSize + 1);
    if (tmp == NULL) {
        printf("Error reallocating memory!\n");
        return 0; // Out of memory
    }

    data->data = tmp;

    // Copy the received data to our buffer
    memcpy(&(data->data[data->size]), ptr, totalSize);
    data->size += totalSize;
    data->data[data->size] = '\0'; // Null terminate the string

    return totalSize;
}

/*
 * Function to extract hyperlinks from the received HTML data
 */
void extractLinks(const char *html) {
    const char *anchorPattern = "<a href=\"";
    const char *endQuotePattern = "\"";

    const char *start = html;
    const char *end;
    
    printf("Extracted Links:\n");
    while ((start = strstr(start, anchorPattern)) != NULL) {
        start += strlen(anchorPattern); // Move the pointer to the start of the URL
        end = strstr(start, endQuotePattern); // Find the closing quote
        
        if (end) {
            // Extract the URL
            size_t urlLength = end - start;
            char *url = (char *)malloc(urlLength + 1);
            strncpy(url, start, urlLength);
            url[urlLength] = '\0'; // Null terminate the URL string
            printf("%s\n", url);
            free(url); // Free allocated memory for URL
            start = end + 1; // Move to the character after the closing quote
        } else {
            break; // No more closing quotes
        }
    }
}

/*
 * The main function of the plugin
 */
int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    
    // Initialize CURL
    CURL *curl;
    CURLcode res;

    struct ResponseData responseData;
    responseData.data = malloc(1); // Initial allocation for the response buffer
    responseData.data[0] = '\0';    // Null terminate the initial buffer
    responseData.size = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the HTTP GET request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // On success, extract hyperlinks from the HTML
            extractLinks(responseData.data);
        }

        // Cleanup
        curl_easy_cleanup(curl);
        free(responseData.data);
    } else {
        fprintf(stderr, "Could not initialize curl.\n");
        free(responseData.data);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
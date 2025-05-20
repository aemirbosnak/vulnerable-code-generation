//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <curl/curl.h>

#define PLUGIN_NAME "ShockWave"
#define PLUGIN_VERSION "1.0"

// Shocked response strings
const char *responses[] = {
    "Oh wow! Did that just happen?",
    "No way! This is unbelievable!",
    "I'm utterly astonished.",
    "What did I just witness?",
    "This is beyond comprehension!"
};

// Simple structure to hold response details
typedef struct {
    const char *url;
    char *response;
    size_t size;
} ResponseData;

// Callback function to handle CURL data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, ResponseData *userdata) {
    size_t realSize = size * nmemb;
    userdata->response = realloc(userdata->response, userdata->size + realSize + 1);
    if (userdata->response == NULL) {
        fprintf(stderr, "Failed to allocate memory for response.\n");
        return 0;
    }
    
    memcpy(&(userdata->response[userdata->size]), contents, realSize);
    userdata->size += realSize;
    userdata->response[userdata->size] = 0; // Null-terminate the string
    return realSize;
}

// Function to fetch URL and respond in shock
void fetch_url(const char *url) {
    CURL *curl;
    CURLcode res;

    ResponseData responseData;
    responseData.url = url;
    responseData.response = malloc(1); // Initial allocation
    responseData.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&responseData);
        
        printf("Fetching data from %s\n", url);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            size_t random_index = rand() % (sizeof(responses) / sizeof(responses[0]));
            printf("%s\nResponse from server:\n%s\n", responses[random_index], responseData.response);
        }
        
        // Cleanup
        curl_easy_cleanup(curl);
        free(responseData.response);
    } else {
        fprintf(stderr, "Failed to initialize CURL.\n");
    }
    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Seed random number generator
    srand((unsigned int)time(NULL));
    
    printf("Welcome to the %s Plugin Version: %s\n", PLUGIN_NAME, PLUGIN_VERSION);
    fetch_url(argv[1]);
    
    printf("Thank you for using the ShockWave Plugin!\n");
    return EXIT_SUCCESS;
}
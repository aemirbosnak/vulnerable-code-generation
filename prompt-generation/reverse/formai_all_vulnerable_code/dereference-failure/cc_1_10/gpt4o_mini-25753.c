//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_URLS 10
#define URL_BUFFER 256
#define CHECK_INTERVAL 5

typedef struct {
    char url[URL_BUFFER];
    int status_code;
} Website;

Website websites[MAX_URLS];
int website_count = 0;

// Function to check the website status using libcurl
void* check_website(void* arg) {
    Website *website = (Website *)arg;
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);  // No body in the response
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);  // Timeout after 10 seconds

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            website->status_code = -1; // Error occurred
        } else {
            long response_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            website->status_code = response_code;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    return NULL;
}

// Function to display the results
void display_results() {
    printf("\nWebsite Status Report:\n");
    for(int i = 0; i < website_count; i++) {
        if(websites[i].status_code == -1) {
            printf("Website: %s is Unreachable\n", websites[i].url);
        } else {
            printf("Website: %s returned status code: %d\n", websites[i].url, websites[i].status_code);
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize the websites array
    for(int i = 1; i < argc && i < MAX_URLS; i++) {
        strncpy(websites[website_count++].url, argv[i], URL_BUFFER - 1);
        websites[website_count - 1].url[URL_BUFFER - 1] = '\0'; // Null-terminate
    }

    while(1) {
        pthread_t threads[MAX_URLS];
        for(int i = 0; i < website_count; i++) {
            pthread_create(&threads[i], NULL, check_website, (void *)&websites[i]);
        }

        // Join threads to ensure they have completed
        for(int i = 0; i < website_count; i++) {
            pthread_join(threads[i], NULL);
        }

        display_results();

        // Wait for the next check
        sleep(CHECK_INTERVAL);
    }

    return EXIT_SUCCESS;
}
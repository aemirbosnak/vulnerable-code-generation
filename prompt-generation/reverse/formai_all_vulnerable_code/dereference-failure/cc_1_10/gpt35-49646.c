//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

/* Define website URLs to monitor */
#define NUM_URLS 3
char *urls[NUM_URLS] = {"https://www.google.com", "https://www.facebook.com", "https://www.twitter.com"};

/* Callback function for cURL */
int curl_callback(CURL *curl, curl_infotype type, char *data, size_t size, void *userData) {
    /* Ignore all data received from the URLs */
    return 0;
}

int main() {
    CURLM *multiHandle = NULL;
    CURL *easyHandle[NUM_URLS];
    int stillRunning = 0;
    int i;
    
    curl_global_init(CURL_GLOBAL_ALL); /* Initialize cURL */
    
    /* Create cURL easy handles for each URL */
    for (i=0; i<NUM_URLS; i++) {
        easyHandle[i] = curl_easy_init();
        curl_easy_setopt(easyHandle[i], CURLOPT_URL, urls[i]);
        curl_easy_setopt(easyHandle[i], CURLOPT_WRITEFUNCTION, curl_callback);
        curl_easy_setopt(easyHandle[i], CURLOPT_TIMEOUT, 5L); /* Set timeout to 5 seconds */
    }
    
    /* Create a multi-handle to perform multiple requests in parallel */
    multiHandle = curl_multi_init();
    
    /* Add all easy handles to the multi-handle */
    for (i=0; i<NUM_URLS; i++) {
        curl_multi_add_handle(multiHandle, easyHandle[i]);
    }
    
    while (1) {
        curl_multi_perform(multiHandle, &stillRunning);
        
        /* Check for completed requests and report status */
        CURLMsg *message;
        int pending;
        while ((message = curl_multi_info_read(multiHandle, &pending))) {
            if (message->msg == CURLMSG_DONE) {
                CURL *handle = message->easy_handle;
                CURLcode result = message->data.result;
                long responseCode = 0;
                curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &responseCode);
                
                if (result != CURLE_OK || responseCode != 200) {
                    const char *url;
                    curl_easy_getinfo(handle, CURLINFO_EFFECTIVE_URL, &url);
                    printf("Error: %s returned status code %ld\n", url, responseCode);
                }
            }
        }
        
        if (!stillRunning) { /* All URLs have been checked */
            break;
        }
    }
    
    /* Cleanup */
    for (i=0; i<NUM_URLS; i++) {
        curl_multi_remove_handle(multiHandle, easyHandle[i]);
        curl_easy_cleanup(easyHandle[i]);
    }
    curl_multi_cleanup(multiHandle);
    curl_global_cleanup();
    
    return 0;
}
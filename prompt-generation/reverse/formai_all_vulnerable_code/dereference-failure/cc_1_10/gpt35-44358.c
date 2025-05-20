//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// A struct to hold the parameters for the check website function
struct website_params{
    char url[50];
    int timeout;
};

// Function to check website status
int check_website(struct website_params *params){
    CURL *curl_handle;
    CURLcode res;
    int status_code = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();
    if(curl_handle) {
        // Set the URL
        curl_easy_setopt(curl_handle, CURLOPT_URL, params->url);
        // Set the timeout
        curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, params->timeout);
        // Set the range to get only the header information
        curl_easy_setopt(curl_handle, CURLOPT_RANGE, "0-1");
        // Perform the request, res will get the return code
        res = curl_easy_perform(curl_handle);
        // Check for errors
        if(res != CURLE_OK){
            printf("Error while checking website %s - %s\n", params->url, curl_easy_strerror(res));
            status_code = -1;
        }
        // Get the HTTP status code
        long code;
        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &code);
        // Check if the server is up (code 200-299)
        if(code >= 200 && code < 300){
            printf("Website %s is UP!\n", params->url);
            status_code = 1;
        }
        else{
            printf("Website %s is DOWN! Status code %ld\n", params->url, code);
            status_code = 0;
        }
        // Cleanup
        curl_easy_cleanup(curl_handle);
    }
    else{
        printf("Error initializing CURL handle\n");
        status_code = -1;
    }
    // Cleanup global state
    curl_global_cleanup();
    return status_code;
}

// Main function
int main(){
    int interval = 30; // Check interval in seconds
    struct website_params *params = malloc(sizeof(*params)); // Allocate memory for website params
    strcpy(params->url, "https://www.example.com"); // Set website URL
    params->timeout = 10; // Set request timeout

    // Infinite loop to check website status every interval seconds
    while(1){
        printf("Checking website status...\n");
        int status_code = check_website(params);
        if(status_code == -1){
            printf("Exiting program...\n");
            return -1;
        }
        sleep(interval);
    }

    // Cleanup
    free(params);
    return 0;
}
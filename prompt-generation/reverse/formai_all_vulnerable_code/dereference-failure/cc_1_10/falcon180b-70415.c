//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024
#define CHECK_INTERVAL 60 // seconds

// Function to print error message and exit program
void die(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

// Function to send GET request and receive response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    char* response = (char*)malloc(size * nmemb);
    if (response == NULL) {
        die("Failed to allocate memory for response");
    }
    memcpy(response, contents, size * nmemb);
    *(char**)userp = response;
    return size * nmemb;
}

// Function to check if website is up
int CheckWebsite(const char* url) {
    CURL* curl;
    CURLcode res;
    char* response = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl == NULL) {
        die("Failed to initialize curl");
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        die("Failed to perform GET request");
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    if (strstr(response, "200 OK") == NULL) {
        printf("Website is down\n");
        return 0;
    } else {
        printf("Website is up\n");
        return 1;
    }
}

// Function to run loop and check website periodically
void MonitorWebsite(const char* url) {
    while (1) {
        time_t now = time(NULL);
        struct tm* tm = localtime(&now);

        if (tm->tm_min % CHECK_INTERVAL == 0) {
            int is_up = CheckWebsite(url);

            if (is_up == 0) {
                printf("Website went down at %s\n", asctime(tm));
            }
        }

        sleep(60); // wait for 1 minute
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        die("Usage:./website_monitor <URL>");
    }

    MonitorWebsite(argv[1]);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <pthread.h>

// Website uptime monitor configuration
#define MAX_URLS 100  // Maximum number of websites to monitor
#define INTERVAL 600  // Monitoring interval in seconds
#define TIMEOUT 10    // Website response timeout in seconds
#define MAX_RETRIES 3 // Number of retries before marking a website as down

// Website information
typedef struct {
    char *url;
    int status;
    time_t last_checked;
    int retries;
} website_info;

// Global variables
website_info websites[MAX_URLS];
int num_websites = 0;
pthread_mutex_t lock;

// Function to check the website uptime
void *check_website(void *arg) {
    pthread_mutex_lock(&lock);
    website_info *website = (website_info *)arg;
    pthread_mutex_unlock(&lock);

    CURL *curl;
    CURLcode res;

    // Initialize CURL
    curl = curl_easy_init();
    if (!curl) {
        return NULL;
    }

    // Set CURL options
    curl_easy_setopt(curl, CURLOPT_URL, website->url);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

    // Perform HTTP request
    res = curl_easy_perform(curl);

    // Check HTTP response code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    if (res != CURLE_OK || response_code >= 400) {
        pthread_mutex_lock(&lock);
        website->status = 0;
        website->retries++;
        pthread_mutex_unlock(&lock);
    }
    else {
        pthread_mutex_lock(&lock);
        website->status = 1;
        website->retries = 0;
        pthread_mutex_unlock(&lock);
    }

    // Cleanup CURL
    curl_easy_cleanup(curl);

    return NULL;
}

// Function to add a website to the monitoring list
void add_website(char *url) {
    pthread_mutex_lock(&lock);
    if (num_websites < MAX_URLS) {
        websites[num_websites].url = strdup(url);
        websites[num_websites].status = 1;
        websites[num_websites].last_checked = time(NULL);
        websites[num_websites].retries = 0;
        num_websites++;
    }
    pthread_mutex_unlock(&lock);
}

// Function to remove a website from the monitoring list
void remove_website(char *url) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_websites; i++) {
        if (strcmp(websites[i].url, url) == 0) {
            free(websites[i].url);
            for (int j = i; j < num_websites - 1; j++) {
                websites[j] = websites[j + 1];
            }
            num_websites--;
            break;
        }
    }
    pthread_mutex_unlock(&lock);
}

// Function to print the website uptime status
void print_status() {
    pthread_mutex_lock(&lock);
    printf("Website Uptime Status:\n");
    for (int i = 0; i < num_websites; i++) {
        printf("%s: %s\n", websites[i].url, websites[i].status ? "Up" : "Down");
    }
    pthread_mutex_unlock(&lock);
}

// Main function
int main(int argc, char **argv) {
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        add_website(argv[i]);
    }

    // Create threads to check websites
    pthread_t threads[num_websites];
    for (int i = 0; i < num_websites; i++) {
        pthread_create(&threads[i], NULL, check_website, &websites[i]);
    }

    // Join threads
    for (int i = 0; i < num_websites; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print website uptime status
    print_status();

    // Cleanup
    for (int i = 0; i < num_websites; i++) {
        free(websites[i].url);
    }

    return 0;
}
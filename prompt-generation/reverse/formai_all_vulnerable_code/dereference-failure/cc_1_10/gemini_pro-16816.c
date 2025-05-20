//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <pthread.h>

// Global variables
pthread_mutex_t lock;
int num_threads = 0;
int num_active_threads = 0;
int num_failed_requests = 0;
int num_successful_requests = 0;

// Thread-safe function to update global variables
void update_global_variables(int success) {
    pthread_mutex_lock(&lock);
    if (success) {
        num_successful_requests++;
    } else {
        num_failed_requests++;
    }
    pthread_mutex_unlock(&lock);
}

// Thread function to send a request to a URL
void *send_request(void *arg) {
    // Increment the number of active threads
    pthread_mutex_lock(&lock);
    num_active_threads++;
    pthread_mutex_unlock(&lock);

    // Prepare the URL
    char *url = (char *)arg;

    // Initialize the CURL session
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize CURL\n");
        pthread_exit(NULL);
    }

    // Set the URL for the request
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the timeout for the request
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Set the user agent for the request
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Website Uptime Monitor");

    // Set the callback function to handle the response
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

    // Send the request
    CURLcode res = curl_easy_perform(curl);

    // Check the response code
    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Update the global variables
    if (res == CURLE_OK && response_code == 200) {
        update_global_variables(1);
    } else {
        update_global_variables(0);
    }

    // Decrement the number of active threads
    pthread_mutex_lock(&lock);
    num_active_threads--;
    pthread_mutex_unlock(&lock);

    // Cleanup the CURL session
    curl_easy_cleanup(curl);

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <num_threads> <url>\n", argv[0]);
        return 1;
    }

    // Get the number of threads and the URL
    num_threads = atoi(argv[1]);
    char *url = argv[2];

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create the threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, send_request, (void *)url);
    }

    // Wait for all the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    printf("Number of successful requests: %d\n", num_successful_requests);
    printf("Number of failed requests: %d\n", num_failed_requests);

    return 0;
}
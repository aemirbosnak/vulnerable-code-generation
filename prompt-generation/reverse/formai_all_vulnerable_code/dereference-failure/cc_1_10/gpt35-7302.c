//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_URLS 10 // Maximum number of URLs to monitor
#define TIMEOUT 5 // Timeout period in seconds

void* check_url(void* url);

int main(int argc, char** argv) {
    char* urls[MAX_URLS]; // Array to hold URLs
    int num_urls = 0; // Number of URLs provided
    pthread_t threads[MAX_URLS]; // Array to hold thread IDs
    int i, rc;

    if (argc < 2) {
        printf("Usage: %s url1 url2 ... url10\n", argv[0]);
        return 1;
    }

    // Copy URLs from command line arguments into array
    for (i = 1; i < argc; i++) {
        if (num_urls >= MAX_URLS) {
            printf("Maximum number of URLs exceeded\n");
            break;
        }
        urls[num_urls] = strdup(argv[i]);
        num_urls++;
    }

    // Create all threads to check URLs
    for (i = 0; i < num_urls; i++) {
        rc = pthread_create(&threads[i], NULL, check_url, urls[i]);
        if (rc) {
            printf("Error creating thread\n");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void* check_url(void* url) {
    char* url_str = (char*)url;
    bool success = false;
    int num_attempts = 0;

    while (!success && num_attempts < 3) {
        num_attempts++;

        // Use system command to check if URL is up
        char command[100];
        sprintf(command, "curl -m %d %s > /dev/null 2>&1", TIMEOUT, url_str);

        // Execute command and check return value
        int result = system(command);
        if (result == 0) {
            success = true;
        } else {
            printf("Attempt %d: %s is down\n", num_attempts, url_str);
            sleep(5); // Wait 5 seconds before trying again
        }
    }

    // Print status message
    if (success) {
        printf("%s is up!\n", url_str);
    } else {
        printf("%s is still down after %d attempts\n", url_str, num_attempts);
    }

    return NULL;
}
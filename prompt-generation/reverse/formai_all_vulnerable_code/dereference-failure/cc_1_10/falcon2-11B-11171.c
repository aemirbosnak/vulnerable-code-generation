//Falcon2-11B DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_URL_LENGTH 1000

// Function to sanitize a URL
void sanitize_url(char *url) {
    char *temp = malloc(MAX_URL_LENGTH * sizeof(char));
    int i = 0;
    int j = 0;

    // Loop through the URL string
    while (url[i]!= '\0') {
        // Check for special characters
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '_') {
            temp[j++] = url[i++];
        }
        else {
            // Replace special characters with '%' followed by their ASCII values
            temp[j++] = '%';
            temp[j++] = (url[i] & 0xFF);
            i++;
        }
    }

    // Replace the original URL with the sanitized URL
    strcpy(url, temp);
    free(temp);
}

// Function to create a new thread
void *create_thread(void *arg) {
    char *url = (char *)arg;
    printf("Thread %d: %s\n", pthread_self(), url);
    sanitize_url(url);
    pthread_exit(NULL);
}

// Main function
int main() {
    pthread_t threads[5];
    char url[MAX_URL_LENGTH];
    int i;

    printf("Enter a URL: ");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Sanitize the URL
    sanitize_url(url);

    // Create 5 threads
    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, create_thread, (void *)url);
    }

    // Wait for all threads to finish
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("URL sanitized: %s\n", url);

    return 0;
}
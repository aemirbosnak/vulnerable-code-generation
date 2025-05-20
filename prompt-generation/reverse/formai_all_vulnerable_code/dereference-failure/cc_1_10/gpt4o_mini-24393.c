//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_BUFFER_SIZE 1024

// A cheerful helper structure to hold received data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// A delightful function to handle the data received from the IMAP server
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    
    if (userp->memory == NULL) {
        printf("Oops! Not enough memory!\n");
        return 0; // Out of memory
    }

    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // Null terminate the string

    return realsize;
}

// A cheerful function to list mailboxes
void listMailboxes(const char *url, const char *username, const char *password) {
    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1); 
    chunk.size = 0;    

    // Let's get started on our IMAP journey!
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERPWD, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "LIST");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        // Execute the lovely curl command
        res = curl_easy_perform(curl);

        // Check for life’s little mishaps
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Yay! We've retrieved the mailboxes:\n");
            printf("%s\n", chunk.memory);
        }

        // Clean up our resources with a happy heart
        curl_easy_cleanup(curl);
        free(chunk.memory);
    } else {
        printf("Oh no! CURL initialization failed!\n");
    }

    curl_global_cleanup();
}

// Main function to start our cheer-filled program!
int main(void) {
    const char* imap_url = "imaps://imap.example.com/"; // Replace with your favorite IMAP server!
    const char* username = "username@example.com";       // Your delightful username!
    const char* password = "yourpassword";                // And your super secure password!

    // Time to spread joy by listing mailboxes!
    listMailboxes(imap_url, username, password);

    printf("Thanks for using our cheerful IMAP client! Have a fabulous day!\n");
    return 0;
}
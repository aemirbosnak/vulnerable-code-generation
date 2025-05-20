//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 1024

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if(userp->memory == NULL) {
        fprintf(stderr, "Not enough memory (reallocated to %zu bytes)\n", userp->size + realsize + 1);
        return 0;
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;
    return realsize;
}

void free_memory(MemoryStruct *mem) {
    free(mem->memory);
    mem->memory = NULL;
    mem->size = 0;
}

void fetch_url(const char* url) {
    CURL *curl;
    CURLcode res;
    MemoryStruct chunk = { .memory = malloc(1), .size = 0 }; // Initial empty memory

    if(chunk.memory == NULL) {
        perror("Failed to allocate memory");
        return;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.68.0"); // Simulating a browser agent

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        printf("Received Data:\n%s\n", chunk.memory);
        printf("Data size: %zu bytes\n", chunk.size);
        
        // Extracting title from HTML
        char *title_start = strstr(chunk.memory, "<title>");
        char *title_end = strstr(chunk.memory, "</title>");
        if (title_start && title_end) {
            title_start += strlen("<title>");
            size_t title_length = title_end - title_start;
            char title[MAX_RESPONSE_LENGTH];
            strncpy(title, title_start, title_length);
            title[title_length] = '\0';
            printf("Webpage Title: %s\n", title);
        } else {
            printf("Title not found in the response.\n");
        }
    }

    free_memory(&chunk);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Welcome to the Web Fetcher Plugin!\n");
    printf("Please enter a URL (http/https): ");
    fgets(url, sizeof(url), stdin);
    
    // Remove newline at the end if exists
    url[strcspn(url, "\n")] = 0;

    if(strlen(url) > 0) {
        fetch_url(url);
    } else {
        printf("No URL entered, exiting...\n");
    }

    return 0;
}
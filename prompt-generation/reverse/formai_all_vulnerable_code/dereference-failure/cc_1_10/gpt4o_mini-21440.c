//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// A structure to hold the response data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write received data into the MemoryStruct
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t new_size = userp->size + size * nmemb;
    userp->memory = realloc(userp->memory, new_size + 1);
    
    if(userp->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    
    memcpy(&(userp->memory[userp->size]), contents, size * nmemb);
    userp->size = new_size;
    userp->memory[new_size] = '\0'; 
    
    return size * nmemb;
}

// Function to perform the GET request
void performGetRequest(const char *url) {
    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1); 
    chunk.size = 0;   

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk); 
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
        
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", chunk.memory);
        }
        
        curl_easy_cleanup(curl);
        free(chunk.memory);
    } 
    
    curl_global_cleanup();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("🎉 Happy HTTP Client 🌍\n");
    printf("Fetching data from: %s\n", argv[1]);

    performGetRequest(argv[1]);
    
    printf("Yay! Request completed! 🎊\n");
    return EXIT_SUCCESS;
}
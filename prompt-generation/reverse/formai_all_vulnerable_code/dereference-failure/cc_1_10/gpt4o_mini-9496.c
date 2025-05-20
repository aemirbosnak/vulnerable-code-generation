//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://speed.hetzner.de/100MB.bin"
#define CHUNK_SIZE 1024

struct MemoryStruct {
    char *memory;
    size_t size;
};

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0; // out of memory
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

double get_download_speed(struct MemoryStruct *mem, double duration) {
    double speed = (mem->size * 8) / (duration * 1000000); // speed in Mbps
    return speed;
}

void start_speed_test() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        
        time_t start = time(NULL);
        printf("Starting download of 100MB test file...\n");

        res = curl_easy_perform(curl);
        time_t end = time(NULL);
        double duration = difftime(end, start);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Download complete. Size: %zu bytes\n", chunk.size);
            double speed = get_download_speed(&chunk, duration);
            printf("Download speed: %.2f Mbps\n", speed);
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);
    } else {
        fprintf(stderr, "Could not initialize curl\n");
    }
    
    curl_global_cleanup();
}

int main(void) {
    printf("=== Internet Speed Test Application ===\n");
    char choice;
    do {
        start_speed_test();
        printf("\nWould you like to test the speed again? (y/n): ");
        scanf(" %c", &choice);
        choice = tolower(choice);
    } while (choice == 'y');

    printf("Thank you for using the Internet Speed Test Application!\n");
    return 0;
}
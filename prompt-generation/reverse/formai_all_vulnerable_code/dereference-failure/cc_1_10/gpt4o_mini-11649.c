//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if(userp->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0; 
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; 
    return realsize;
}

void display_speed(float speed) {
    printf("Download speed: %.2f KB/s\n", speed / 1024);
    int barLength = (int)(speed / 1024);
    for (int i = 0; i < barLength; i++) {
        if (i % 5 == 0) {
            printf("+");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

void shape_shifting_output(float speed) {
    printf("\n");
    if (speed < 500000) {
        printf("Your internet speed is like a turtle 🐢  \n");
    } else if (speed < 5000000) {
        printf("Your internet speed is like a rabbit 🐇  \n");
    } else {
        printf("Your internet speed is like a cheetah 🐆  \n");
    }
    printf("\n");
}

int main(void) {
    CURL *curl;
    CURLcode res;
    MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://speed.hetzner.de/100MB.bin");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        double speed;
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
        display_speed(speed);
        shape_shifting_output(speed);

        curl_easy_cleanup(curl);
        free(chunk.memory);
    }
    curl_global_cleanup();
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://example.com"
#define INTERVAL 10

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if(userp->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = '\0';
    return realsize;
}

void check_uptime(const char *url) {
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
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code); 
            if (response_code >= 200 && response_code < 300) {
                printf("The phantoms of %s linger and the site is alive – HTTP code: %ld\n", url, response_code);
            } else {
                printf("In the abyss of numbers, the site falters – HTTP code: %ld\n", response_code);
            }
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);
    }
    curl_global_cleanup();
}

int main() {
    printf("As the clock unwinds, we shall plunge into the depths of the digital sea...\n");
    while(1) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("Current enchanted time: %02d:%02d:%02d\n",
               tm.tm_hour, tm.tm_min, tm.tm_sec);
        
        check_uptime(URL);
        printf("The echo of the check resonates back to the void...\n");
        sleep(INTERVAL);
    }
    return 0;
}
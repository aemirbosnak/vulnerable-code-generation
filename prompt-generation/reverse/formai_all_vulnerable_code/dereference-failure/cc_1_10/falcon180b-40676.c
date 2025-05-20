//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_URLS 100
#define CHECK_INTERVAL 60 // in seconds

typedef struct {
    char *url;
    int status;
} url_t;

url_t urls[MAX_URLS];
int num_urls = 0;

void *check_url_thread(void *arg) {
    char *url = (char *) arg;
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    long response_code;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "HEAD");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            printf("Failed to check URL '%s'\n", url);
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code >= 200 && response_code < 400) {
                urls[num_urls].url = strdup(url);
                urls[num_urls].status = response_code;
                num_urls++;
            } else {
                printf("URL '%s' returned response code %ld\n", url, response_code);
            }
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    curl_global_cleanup();
    return NULL;
}

int main() {
    int i, max_threads = 10;
    pthread_t threads[MAX_URLS];

    printf("Enter URLs to monitor (one per line, press enter to finish):\n");
    while(fgets(urls[num_urls].url, sizeof(urls[num_urls].url), stdin)!= NULL) {
        urls[num_urls].status = 0;
        num_urls++;
        if(num_urls >= MAX_URLS) {
            break;
        }
    }

    for(i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, check_url_thread, (void *) urls[i].url);
    }

    for(i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    while(1) {
        sleep(CHECK_INTERVAL);
        printf("Checking URLs...\n");
        for(i = 0; i < num_urls; i++) {
            if(urls[i].status == 0) {
                pthread_create(&threads[i], NULL, check_url_thread, (void *) urls[i].url);
            }
        }
        for(i = 0; i < num_urls; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    return 0;
}
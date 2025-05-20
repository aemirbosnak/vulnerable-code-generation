//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<curl/curl.h>

// This function sends the GET request to the URL and checks its response
// If the response is received successfully (i.e., HTTP status code 200), then it returns 1
// Else, it returns 0
int ping(char url[]){
    CURL *curl_handle;
    CURLcode res;
    long http_code = 0;
    int ret = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    if(curl_handle){
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl_handle);

        if(res != CURLE_OK){
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            ret = 0;
        }
        else{
            curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &http_code);

            if(http_code == 200)
                ret = 1;
        }

        curl_easy_cleanup(curl_handle);
    }

    curl_global_cleanup();
    return ret;
}

int main(int argc, char *argv[]) {
    char url[128] = ""; // assuming maximum URL length is 128 characters
    int i;

    printf("Website Uptime Monitor\n");
    printf("----------------------\n");

    // take URL(s) as command line argument(s)
    if(argc > 1){
        for(i=1; i<argc; i++){
            strcpy(url, argv[i]);
            printf("Checking %s\n", url);

            if(ping(url) == 1)
                printf("%s is up\n", url);
            else
                printf("%s is down\n", url);
        }
    }
    else{
        printf("Usage: %s <url(s)>\n", argv[0]);
    }

    return 0;
}
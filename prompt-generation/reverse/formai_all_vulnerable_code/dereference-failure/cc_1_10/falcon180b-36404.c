//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <math.h>
#include <time.h>

#define TEST_SERVER "speedtest.net"
#define TEST_PORT "8080"
#define TEST_PATH "/api/v3/speedtest"
#define TEST_USER_AGENT "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3"

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *data = (char*)contents;
    printf("%s", data);
    return realsize;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    char *url;
    double dl_speed, ul_speed;
    struct timeval start, end;
    double elapsed_time;
    char readBuffer[1024];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        url = malloc(strlen(TEST_SERVER) + strlen(TEST_PORT) + strlen(TEST_PATH) + 1);
        sprintf(url, "http://%s:%s%s", TEST_SERVER, TEST_PORT, TEST_PATH);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, TEST_USER_AGENT);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Speed test completed.\n");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}
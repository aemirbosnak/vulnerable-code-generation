//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <math.h>

typedef struct {
    char *url;
    double speed;
} speedtest_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char*)malloc(size*nmemb);
    memcpy(buffer, contents, size*nmemb);
    printf("%s", buffer);
    free(buffer);
    return size*nmemb;
}

double CalculateSpeed(long long start, long long end, double duration) {
    double speed = (double)((end - start) / duration) / 1024;
    return speed;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *fp;
    char readBuffer[1024];
    speedtest_t *speedtests = (speedtest_t*)malloc(5 * sizeof(speedtest_t));
    int i = 0;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        for(i=0; i<5; i++) {
            sprintf(readBuffer, "https://speedtest.net/speedtest/%d.txt", i+1);
            speedtests[i].url = strdup(readBuffer);
            curl_easy_setopt(curl, CURLOPT_URL, speedtests[i].url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
    }
    curl_global_cleanup();
    for(i=0; i<5; i++) {
        fp = fopen(speedtests[i].url, "r");
        fseek(fp, 0, SEEK_END);
        long long fileSize = ftell(fp);
        fclose(fp);
        free(speedtests[i].url);
        speedtests[i].speed = CalculateSpeed(0, fileSize, 10.0);
        printf("Test %d: %.2f KB/s\n", i+1, speedtests[i].speed);
    }
    return 0;
}
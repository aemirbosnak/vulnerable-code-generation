//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define BUFFER_SIZE 4096

struct SpeedTest {
    char *url;
    CURL *curl;
    double speed;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char *)userp)[((size_t) 0) + strlen((char *)userp)] = 0;
    return size * nmemb;
}

double CalculateSpeed(struct SpeedTest *speedTest) {
    double totalBytes = 0;
    double elapsedTime = 0;

    curl_easy_getinfo(speedTest->curl, CURLINFO_TOTAL_TIME, &elapsedTime);
    curl_easy_getinfo(speedTest->curl, CURLINFO_SIZE_UPLOAD, &totalBytes);

    speedTest->speed = totalBytes / elapsedTime;

    return speedTest->speed;
}

void PerformSpeedTest(struct SpeedTest *speedTest) {
    curl_easy_setopt(speedTest->curl, CURLOPT_URL, speedTest->url);
    curl_easy_setopt(speedTest->curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(speedTest->curl, CURLOPT_WRITEDATA, speedTest->url);

    curl_easy_perform(speedTest->curl);
    curl_easy_cleanup(speedTest->curl);
}

int main() {
    CURL *curl;
    CURLcode res;
    struct SpeedTest speedTest;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        speedTest.url = malloc(MAX_URL_LEN);
        speedTest.curl = curl;

        printf("Enter the URL to test: ");
        fgets(speedTest.url, MAX_URL_LEN, stdin);

        res = curl_easy_setopt(curl, CURLOPT_URL, speedTest.url);
        if (res!= CURLE_OK) {
            fprintf(stderr, "Failed to set URL: %s\n",
                    curl_easy_strerror(res));
            exit(1);
        }

        PerformSpeedTest(&speedTest);

        printf("Speed test result: %.2lf bytes/sec\n", CalculateSpeed(&speedTest));

        free(speedTest.url);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}
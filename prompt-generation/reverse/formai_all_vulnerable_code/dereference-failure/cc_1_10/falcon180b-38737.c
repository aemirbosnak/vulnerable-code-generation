//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

typedef struct {
    char *url;
    char *host;
    double ping;
    double download_speed;
    double upload_speed;
} speedtest_result;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    return size * nmemb;
}

speedtest_result *speedtest(char *server_url) {
    CURL *curl;
    CURLcode res;
    speedtest_result *result = (speedtest_result *)malloc(sizeof(speedtest_result));

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, server_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, result);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return result;
}

void print_speedtest_result(speedtest_result *result) {
    printf("Ping: %.2f ms\n", result->ping);
    printf("Download speed: %.2f Mbps\n", result->download_speed);
    printf("Upload speed: %.2f Mbps\n", result->upload_speed);
}

int main(int argc, char **argv) {
    speedtest_result *result = speedtest("https://speedtest.net/speedtest.php");

    if(result) {
        print_speedtest_result(result);
    } else {
        printf("Speedtest failed.\n");
    }

    return 0;
}
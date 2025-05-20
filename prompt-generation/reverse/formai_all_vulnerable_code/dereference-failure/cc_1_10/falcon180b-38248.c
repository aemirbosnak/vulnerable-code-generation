//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <curl/curl.h>

#define SERVER_URL "http://speedtest.net/speedtest.php?test=1"
#define BUFFER_SIZE 1024

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *data = (char*)contents;
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    long int start_time, end_time;
    double elapsed_time;
    char readBuffer[BUFFER_SIZE];
    size_t numBytes;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        fp = fopen("result.txt", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, SERVER_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        else {
            fclose(fp);
            start_time = clock();
            fp = fopen("result.txt", "rb");
            while((numBytes = fread(readBuffer, 1, BUFFER_SIZE, fp)) > 0) {
                printf("%s", readBuffer);
            }
            end_time = clock();
            elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("\nElapsed Time: %.2f seconds\n", elapsed_time);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}
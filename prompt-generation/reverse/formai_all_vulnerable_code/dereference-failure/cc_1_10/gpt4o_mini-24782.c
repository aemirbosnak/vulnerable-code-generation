//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

#define DOWNLOAD_URL "http://ipv4.download.thinkbroadband.com/1MB.zip" // Url for downloading test
#define UPLOAD_URL "http://httpbin.org/post" // Url for uploading test
#define DATA_SIZE (1 * 1024 * 1024) // 1 MB data for upload
#define BUFFER_SIZE (2 * 1024 * 1024) // 2 MB buffer size

static size_t download_callback(void *ptr, size_t size, size_t nmemb, void *stream) {
    return size * nmemb; // Ignoring the download content
}

typedef struct {
    double speed;
    char type[10];
} SpeedResult;

void* download_speed_test(void* arg) {
    CURL *curl;
    CURLcode res;
    long total_time;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, download_callback);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        
        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();
        
        if (res != CURLE_OK) {
            fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &total_time);
        
        SpeedResult *result = malloc(sizeof(SpeedResult));
        result->speed = (double)BUFFER_SIZE / (total_time / 1000000.0); // speed in bytes/sec
        strcpy(result->type, "Download");
        
        curl_easy_cleanup(curl);
        return result;
    }
    return NULL;
}

void* upload_speed_test(void* arg) {
    CURL *curl;
    CURLcode res;
    char data[DATA_SIZE];
    
    memset(data, 'a', DATA_SIZE); // Fill data with 'a's
    long total_time;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, DATA_SIZE);
        
        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        if (res != CURLE_OK) {
            fprintf(stderr, "Upload failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &total_time);
        
        SpeedResult *result = malloc(sizeof(SpeedResult));
        result->speed = (double)DATA_SIZE / (total_time / 1000000.0); // speed in bytes/sec
        strcpy(result->type, "Upload");
        
        curl_easy_cleanup(curl);
        return result;
    }
    return NULL;
}

void display_result(SpeedResult *result) {
    printf("%s Speed: %.2f Bytes/sec\n", result->type, result->speed);
    free(result);
}

int main() {
    pthread_t download_thread, upload_thread;
    
    printf("Starting internet speed test...\n");
    
    pthread_create(&download_thread, NULL, download_speed_test, NULL);
    pthread_create(&upload_thread, NULL, upload_speed_test, NULL);
    
    SpeedResult *download_result, *upload_result;
    
    pthread_join(download_thread, (void**)&download_result);
    pthread_join(upload_thread, (void**)&upload_result);

    display_result(download_result);
    display_result(upload_result);
    
    return 0;
}
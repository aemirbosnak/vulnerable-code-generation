//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    // Simply ignore the incoming data to measure speed
    return size * nmemb;
}

double measure_download_speed(const char *url, int data_size) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1;
        }

        double elapsed_time_in_sec = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        double speed = (data_size / 1024.0) / elapsed_time_in_sec; // Speed in KB/s
        curl_easy_cleanup(curl);
        return speed;
    }
    return -1;
}

double measure_upload_speed(const char *url, const char *data) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, data);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        
        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1;
        }

        double elapsed_time_in_sec = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        double uploaded_size = strlen(data); // Size in bytes
        double speed = (uploaded_size / 1024.0) / elapsed_time_in_sec; // Speed in KB/s
        curl_easy_cleanup(curl);
        return speed;
    }
    return -1;
}

int main() {
    const char *download_url = "http://ipv4.download.thinkbroadband.com/5MB.zip";
    const char *upload_url = "http://your-upload-server.com/upload"; // Replace with a valid upload URL
    char *upload_data = malloc(1024); // Data to upload
    memset(upload_data, 'A', 1024); // Fill with data
    
    printf("Starting Internet Speed Test...\n");

    // Measure Download Speed
    printf("Measuring Download Speed...\n");
    double download_speed = measure_download_speed(download_url, 5 * 1024 * 1024); // 5 MB
    if (download_speed >= 0) {
        printf("Download Speed: %.2f KB/s\n", download_speed);
    } else {
        printf("Failed to measure download speed.\n");
    }

    // Measure Upload Speed
    printf("Measuring Upload Speed...\n");
    double upload_speed = measure_upload_speed(upload_url, upload_data);
    if (upload_speed >= 0) {
        printf("Upload Speed: %.2f KB/s\n", upload_speed);
    } else {
        printf("Failed to measure upload speed.\n");
    }

    free(upload_data); // Clean up
    return 0;
}
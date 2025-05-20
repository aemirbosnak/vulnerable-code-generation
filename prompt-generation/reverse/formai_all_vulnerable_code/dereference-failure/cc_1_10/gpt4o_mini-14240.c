//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

double measure_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    double speed;

    // Open file to save the downloaded data
    fp = fopen("temp_file", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return -1;
    }

    // Initialize CURL
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        
        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            fclose(fp);
            curl_easy_cleanup(curl);
            return -1;
        }
        
        // Get the download speed (bytes per second)
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
        
        // Cleanup
        fclose(fp);
        curl_easy_cleanup(curl);
    }
    
    return speed;
}

void display_results(double speed) {
    if (speed < 0) {
        printf("Failed to measure download speed.\n");
    } else {
        printf("Download Speed: %.2f bytes/sec (%.2f KB/sec)\n", speed, speed / 1024);
    }
}

int main() {
    const char *url = "http://speed.hetzner.de/100MB.bin"; // URL for testing
    double speed;

    printf("Starting internet speed test...\n");
    
    speed = measure_download_speed(url);
    
    display_results(speed);
    
    // Clean up and remove the temporary file
    remove("temp_file");

    return 0;
}
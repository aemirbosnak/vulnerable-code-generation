//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((char*)userp)[((size_t)size) * nmemb] = '\0';
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    char* url = "https://www.speedtest.net/speedtest.php";
    char* data = NULL;
    long response_code;
    double download_speed, upload_speed;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            response_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, NULL);
            if (response_code == 200) {
                char* speed_start = strstr(data, "Your Internet speed is:");
                if (speed_start) {
                    char* speed_end = strstr(speed_start, "Mbps");
                    if (speed_end) {
                        download_speed = atof(speed_start) / 8;
                        upload_speed = atof(speed_end + 6) / 8;
                        printf("Download speed: %.2f Mbps\n", download_speed);
                        printf("Upload speed: %.2f Mbps\n", upload_speed);
                    }
                }
            }
        }

        curl_easy_cleanup(curl);
        free(data);
    }

    curl_global_cleanup();
    return 0;
}
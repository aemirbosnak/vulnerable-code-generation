//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <math.h>

#define SPEED_TEST_URL "https://www.speedtest.net/speedtest.php"

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((char*)userp)[(size_t)0] = '\0';
    return size * nmemb;
}

double calculate_speed(double bytes, double duration) {
    double bits = bytes * 8;
    double speed = bits / duration;
    return speed;
}

int main(int argc, char** argv) {
    if(argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    CURL* curl = curl_easy_init();
    if(curl) {
        char* server_ip = argv[1];
        char url[strlen(SPEED_TEST_URL) + strlen(server_ip) + 1];
        strcpy(url, SPEED_TEST_URL);
        strcat(url, server_ip);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &url);

        CURLcode res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if(response_code!= 200) {
                printf("Server returned response code: %ld\n", response_code);
            } else {
                char* speed_str = strstr(url, "speed=</b>");
                if(speed_str) {
                    speed_str += 8;
                    double speed = atof(speed_str);
                    printf("Internet speed: %.2f Mbps\n", speed);
                } else {
                    printf("Failed to find speed in response\n");
                }
            }
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}
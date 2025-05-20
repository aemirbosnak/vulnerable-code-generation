//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to handle received data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char*)userp)[size*nmemb] = '\0';
    return size * nmemb;
}

// Function to perform the speed test and display results
int SpeedTest(char* server, int port)
{
    CURL* curl;
    CURLcode res;
    char url[50];
    double speed = 0.0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        sprintf(url, "http://%s:%d/speedtest.php", server, port);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &speed);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "Speed test failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Download speed: %.2f Mbps\n", speed / (1024 * 1024));
            printf("Upload speed: %.2f Mbps\n", speed / (1024 * 1024));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}

int main(int argc, char* argv[])
{
    if(argc!= 4) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    SpeedTest(argv[1], atoi(argv[2]));
    return 0;
}
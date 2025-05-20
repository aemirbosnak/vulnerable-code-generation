//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SPEEDTEST_URL "http://speedtest.net/speedtest.php"
#define USER_AGENT "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:25.0) Gecko/20100101 Firefox/25.0"
#define DOWNLOAD_TIMEOUT 60
#define UPLOAD_TIMEOUT 60

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb;
}

int main() {
    CURL* curl;
    FILE* fp;
    char readBuffer[1024];
    double downloadSpeed, uploadSpeed;
    long responseCode;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        fp = fopen("speedtest.html", "wb");

        if (fp) {
            curl_easy_setopt(curl, CURLOPT_URL, SPEEDTEST_URL);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_USERAGENT, USER_AGENT);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, DOWNLOAD_TIMEOUT);

            curl_easy_perform(curl);

            fclose(fp);

            curl_easy_cleanup(curl);

            curl = curl_easy_init();

            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, SPEEDTEST_URL);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
                curl_easy_setopt(curl, CURLOPT_USERAGENT, USER_AGENT);
                curl_easy_setopt(curl, CURLOPT_TIMEOUT, UPLOAD_TIMEOUT);

                curl_easy_perform(curl);

                fclose(fp);

                curl_easy_cleanup(curl);

                curl_global_cleanup();

                system("speedtest.html");
            }
        }
    }

    return 0;
}
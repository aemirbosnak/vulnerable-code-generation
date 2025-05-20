//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*10

int write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

size_t read_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fread(ptr, size, nmemb, stream);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <url> <interval_sec>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LEN] = {0};
    strncpy(url, argv[1], MAX_URL_LEN - 1);

    int interval = atoi(argv[2]);

    CURL *curl;
    FILE *fp;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        fp = fopen("response.html", "w");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_data);
        curl_easy_setopt(curl, CURLOPT_READDATA, fp);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }

    while (1) {
        sleep(interval);
        system("ping -c 1 www.example.com > /dev/null");
        if (system("grep -q '100% packet loss' response.html") == 0) {
            printf("Website is down\n");
        } else {
            printf("Website is up\n");
        }
    }

    return 0;
}
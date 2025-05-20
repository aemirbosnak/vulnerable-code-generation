//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    struct curl_slist *headers = NULL;
    char url[100];
    char user_agent[100];
    int timeout = 5;
    long response_code;
    double response_time;
    struct timeval start_time, end_time;
    double elapsed_time;

    sprintf(url, "http://www.example.com");
    sprintf(user_agent, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        headers = curl_slist_append(headers, user_agent);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        response_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, NULL);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    if (fp) {
        fclose(fp);
    }

    if (response_code == 200) {
        printf("Website is up and running!\n");
    } else {
        printf("Website is down with response code %ld\n", response_code);
    }

    return 0;
}
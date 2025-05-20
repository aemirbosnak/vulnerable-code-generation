//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *url;
    char *status;
} website_t;

website_t *website_create(char *url) {
    website_t *website = malloc(sizeof(website_t));
    if (!website) {
        printf("Error: Unable to allocate memory for website.\n");
        exit(1);
    }
    website->url = strdup(url);
    website->status = "unknown";
    return website;
}

void website_destroy(website_t *website) {
    free(website->url);
    free(website);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    return fwrite(ptr, size, nmemb, (FILE*)stream);
}

static int progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    return 0;
}

int website_check(website_t *website) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    if (res == CURLE_OK) {
        website->status = "online";
    } else {
        website->status = "offline";
    }
    return res;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        exit(1);
    }
    website_t *website = website_create(argv[1]);
    int res = website_check(website);
    if (res == CURLE_OK) {
        printf("Website %s is %s.\n", website->url, website->status);
    } else {
        printf("Error checking website status: %s\n", curl_easy_strerror(res));
    }
    website_destroy(website);
    return 0;
}
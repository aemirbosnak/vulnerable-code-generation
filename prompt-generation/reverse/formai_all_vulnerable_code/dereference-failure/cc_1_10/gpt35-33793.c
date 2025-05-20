//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define MAX_ERROR_LENGTH 512
#define MAX_RETRIES 3

struct url_data {
    size_t size;
    char* data;
};

size_t write_data(void* ptr, size_t size, size_t nmemb, struct url_data* data) {
    size_t index = data->size;
    size_t n = (size * nmemb);
    char* tmp;

    data->size += (size * nmemb);

    tmp = realloc(data->data, data->size + 1);

    if (tmp) {
        data->data = tmp;
    } else {
        if (data->data) {
            free(data->data);
        }
        fprintf(stderr, "Failed to allocate memory!\n");
        return 0;
    }

    memcpy((data->data + index), ptr, n);
    data->data[data->size] = '\0';

    return size * nmemb;
}

int check_url(const char* url) {
    CURL* curl_handle;
    CURLcode res;
    int retries = 0;
    int success = 0;
    char error_buffer[MAX_ERROR_LENGTH];
    struct url_data data;

    data.data = malloc(1);
    data.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    if (curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, url);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 5L);
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);

        while (retries < MAX_RETRIES && !success) {
            res = curl_easy_perform(curl_handle);
            if (res != CURLE_OK) {
                sprintf(error_buffer, "curl_easy_perform() failed %s\n", curl_easy_strerror(res));
                retries++;
                continue;
            } else {
                success = 1;
            }
        }

        if (!success) {
            fprintf(stderr, "Failed to connect to %s after %d retries.\n", url, retries);
            curl_easy_cleanup(curl_handle);
            free(data.data);
            return -1;
        } else {
            long response_code;
            curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);
            printf("%s returned response code %ld.\n", url, response_code);
            curl_easy_cleanup(curl_handle);
            free(data.data);
            return 0;
        }
    } else {
        fprintf(stderr, "Failed to create curl handle for %s.\n", url);
        free(data.data);
        return -1;
    }
}

int main(int argc, char* argv[]) {
    char url[MAX_URL_LENGTH];
    int i = 1;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> [<url2> <url3> ...]\n", argv[0]);
        return 1;
    }

    while (i < argc) {
        strncpy(url, argv[i], MAX_URL_LENGTH);
        if (check_url(url)) {
            fprintf(stderr, "Failed to connect to %s.\n", url);
        }
        i++;
    }

    return 0;
}
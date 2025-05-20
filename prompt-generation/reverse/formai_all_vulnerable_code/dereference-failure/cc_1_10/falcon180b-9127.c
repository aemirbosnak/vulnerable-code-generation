//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    if (written!= nmemb) {
        fprintf(stderr, "Failed to write data\n");
        exit(EXIT_FAILURE);
    }
}

size_t read_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t read = fread(ptr, size, nmemb, stream);
    if (read!= nmemb) {
        fprintf(stderr, "Failed to read data\n");
        exit(EXIT_FAILURE);
    }
    return read;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <server_url>\n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char url[100];
        strcpy(url, argv[1]);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_data);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Internet speed test completed successfully\n");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}
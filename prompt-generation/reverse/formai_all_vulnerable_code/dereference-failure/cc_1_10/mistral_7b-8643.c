//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <curl/curl.h>

#define TRUE    1
#define FALSE   0

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    if (fwrite(contents, size, realsize, stdout) < realsize) {
        fprintf(stderr, "Failed to write to file\n");
        return 0;
    }
    return realsize;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <URL> <OUTPUT_FILE>\n", argv[0]);
        return 1;
    }

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *headers = NULL;
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        if(strstr(argv[1], ".html") || strstr(argv[1], ".htm")) {
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, TRUE);
        }

        // Set custom request header
        headers = curl_slist_append(headers, "User-Agent: MyClient/1.0");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Always cleanup
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    if (argc > 3) {
        FILE *fp = fopen(argv[3], "wb");
        if (fp) {
            res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            if (res != CURLE_OK) {
                fprintf(stderr, "Failed to open output file: %s\n", curl_easy_strerror(res));
            } else {
                res = curl_easy_perform(curl);
                if (res != CURLE_OK) {
                    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                }
                fclose(fp);
            }
            curl_easy_cleanup(curl);
        }
    }

    return 0;
}
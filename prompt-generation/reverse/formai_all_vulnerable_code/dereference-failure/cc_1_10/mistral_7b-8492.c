//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char *url, *filename;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <URL> <filename>\n", argv[0]);
        return 1;
    }

    url = strdup(argv[1]);
    filename = strdup(argv[2]);

    curl = curl_easy_init();
    if(curl) {
        fp = fopen(filename, "wb");

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            fclose(fp);
            curl_easy_cleanup(curl);
            free(url);
            free(filename);
            return 1;
        }

        printf("Data has been downloaded successfully from %s to %s\n",
               url, filename);

        fclose(fp);
        curl_easy_cleanup(curl);
        free(url);
        free(filename);
    } else {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 1;
    }

    return 0;
}
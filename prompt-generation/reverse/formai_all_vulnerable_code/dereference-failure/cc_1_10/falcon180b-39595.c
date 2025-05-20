//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ctype.h>
#include <curl/curl.h>

size_t WriteCallback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char url[100];

    if (argc < 3) {
        printf("Usage: %s <ftp_server> <file_to_download>\n", argv[0]);
        return 1;
    }

    strcpy(url, "ftp://");
    strcat(url, argv[1]);
    strcat(url, "/");
    strcat(url, argv[2]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        fp = fopen("output.txt", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            printf("File downloaded successfully!\n");
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
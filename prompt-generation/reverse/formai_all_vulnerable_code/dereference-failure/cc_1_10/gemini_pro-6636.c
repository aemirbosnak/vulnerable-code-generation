//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(int argc, char **argv) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char *url;
    char *filename;

    if (argc < 3) {
        printf("Usage: %s <URL> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    url = argv[1];
    filename = argv[2];

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: could not initialize curl.\n");
        return EXIT_FAILURE;
    }

    fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s.\n", filename);
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: could not perform curl request.\n");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    curl_easy_cleanup(curl);
    fclose(fp);

    printf("File downloaded successfully to %s.\n", filename);

    return EXIT_SUCCESS;
}
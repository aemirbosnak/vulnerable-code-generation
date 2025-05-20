//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_URL_LENGTH 1024
#define MAX_LOG_FILE_SIZE 1000000
#define MAX_LOG_ENTRY_LENGTH 1024

static FILE *log_file = NULL;
static char log_entry[MAX_LOG_ENTRY_LENGTH];

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <URL> <log_file>\n", argv[0]);
        return 1;
    }

    char url[MAX_URL_LENGTH] = {0};
    strncpy(url, argv[1], MAX_URL_LENGTH-1);

    log_file = fopen(argv[2], "a");
    if (log_file == NULL) {
        printf("Error opening log file: %s\n", strerror(errno));
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);

    CURL *curl;
    curl = curl_easy_init();

    if (curl) {
        struct stat st;
        if (stat(argv[2], &st) == 0 && st.st_size >= MAX_LOG_FILE_SIZE) {
            printf("Log file size limit reached. Exiting.\n");
            curl_easy_cleanup(curl);
            fclose(log_file);
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, log_file);

        CURLcode res;
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Website is up and running.\n");
        }

        curl_easy_cleanup(curl);
        fclose(log_file);
    }

    curl_global_cleanup();

    return 0;
}
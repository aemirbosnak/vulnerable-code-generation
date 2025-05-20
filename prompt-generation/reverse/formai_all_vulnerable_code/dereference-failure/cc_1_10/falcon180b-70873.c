//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <curl/curl.h>

/*
 * Function to print error message and exit program.
 */
void die(const char *msg) {
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(1);
}

/*
 * Function to write data to a file.
 */
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

/*
 * Function to handle HTTP response data.
 */
size_t handle_response(void *ptr, size_t size, size_t nmemb, void *userp) {
    FILE *file = (FILE *)userp;
    return fwrite(ptr, size, nmemb, file);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        die("Usage:./http_client <method> <url> <output_file>");
    }

    CURL *curl;
    FILE *file;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[2]);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            die(curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        fclose(file);
    } else {
        die("Failed to initialize curl");
    }

    curl_global_cleanup();
    return 0;
}
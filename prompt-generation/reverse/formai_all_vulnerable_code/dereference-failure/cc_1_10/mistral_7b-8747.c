//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct string {
    char *ptr;
    size_t len;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct string *s = (struct string *)userp;

    s->len += realsize;
    s->ptr = (char *)realloc(s->ptr, s->len + 1);
    memcpy(s->ptr + s->len - 1, contents, realsize);
    s->ptr[s->len] = '\0';

    return realsize;
}

int main(void) {
    CURL *curl;
    CURLcode res;
    struct string s;
    s.len = 0;
    s.ptr = malloc(64);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Received %ld bytes:\n%s\n", (long)s.len, s.ptr);
        }

        curl_easy_cleanup(curl);
        free(s.ptr);
    }

    curl_global_cleanup();

    return EXIT_SUCCESS;
}
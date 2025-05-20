//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct curl_string {
    char *ptr;
    size_t len;
};

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
    struct curl_string *str = (struct curl_string *)userp;
    size_t new_len = str->len + (size * nmemb);
    str->ptr = realloc(str->ptr, new_len + 1);
    if (str->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(str->ptr + str->len, contents, size * nmemb);
    str->len = new_len;
    str->ptr[str->len] = '\0';
    return size * nmemb;
}

char *http_get(const char *url)
{
    CURL *curl;
    CURLcode res;
    struct curl_string s;
    s.len = 0;
    s.ptr = malloc(1);
    s.ptr[0] = '\0';

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return s.ptr;
}

int main(void)
{
    char *html = http_get("https://example.com");
    if (html) {
        printf("%s\n", html);
        free(html);
    }
    return 0;
}
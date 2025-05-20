//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

typedef struct {
    char *data;
    size_t size;
} StringBuffer;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    StringBuffer *buffer = (StringBuffer *)userp;
    size_t newSize = buffer->size + size * nmemb;
    char *newData = realloc(buffer->data, newSize + 1);
    if (newData == NULL) {
        return 0;
    }
    buffer->data = newData;
    buffer->size = newSize;
    memcpy(buffer->data + buffer->size - size * nmemb, contents, size * nmemb);
    buffer->data[buffer->size - 1] = '\0';
    return size * nmemb;
}

static int DebugCallback(CURL *curl, curl_infotype type, char *data, size_t size, void *userp) {
    if (type == CURLINFO_TEXT) {
        fprintf(stderr, "%.*s\n", (int)size, data);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    StringBuffer response;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, DebugCallback);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            fprintf(stdout, "Response:\n%s\n", response.data);
        }
        curl_easy_cleanup(curl);
        free(response.data);
    }
    curl_global_cleanup();
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <openssl/ssl.h>

// Callback function to handle incoming data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    FILE* file = (FILE*)userp;
    return fwrite(contents, size, nmemb, file);
}

// Callback function to handle SSL verification
int VerifyCallback(int preverify_ok, X509_STORE_CTX* ctx) {
    if (!preverify_ok) {
        char* err = X509_verify_cert_error_string(X509_STORE_CTX_get_error(ctx));
        printf("SSL verification failed: %s\n", err);
        return 0;
    }
    return 1;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <HTTP method> <URL> [data]\n", argv[0]);
        return 1;
    }

    CURL* curl;
    FILE* file;
    char* method = argv[1];
    char* url = argv[2];
    char* data = NULL;
    if (argc > 3) {
        data = argv[3];
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

    if (data) {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(data));
    }

    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_CTX_FUNCTION, VerifyCallback);
    curl_easy_setopt(curl, CURLOPT_SSL_CTX_DATA, NULL);

    CURLcode res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        char* err = curl_easy_strerror(res);
        fprintf(stderr, "curl_easy_perform() failed: %s\n", err);
        return 1;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}
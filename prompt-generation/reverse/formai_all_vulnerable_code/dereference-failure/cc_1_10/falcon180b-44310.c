//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <curl/curl.h>

#define SERVER_ADDRESS "imap.gmail.com"
#define SERVER_PORT 993
#define USERNAME "your_email_address"
#define PASSWORD "your_password"

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    char* data = (char*) contents;

    printf("%s", data);

    return realsize;
}

int main() {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        struct curl_slist* headers = NULL;
        char* auth_string = NULL;

        headers = curl_slist_append(headers, "Content-Type: text/plain; charset=UTF-8");
        auth_string = curl_easy_escape(curl, USERNAME, strlen(USERNAME));
        auth_string = curl_easy_escape(curl, PASSWORD, strlen(PASSWORD));

        char* encoded_auth = curl_easy_escape(curl, auth_string, strlen(auth_string));
        curl_slist_free_all(headers);

        char* url = "imaps://" SERVER_ADDRESS "/";

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
        curl_easy_setopt(curl, CURLOPT_USERPWD, encoded_auth);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 2048

typedef struct {
    char *url;
    char *username;
    char *password;
    char *command;
} ftp_client_t;

size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *userp) {
    char *buffer = (char *)ptr;
    size_t buffer_size = size * nmemb;
    ftp_client_t *client = (ftp_client_t *)userp;

    if (client->command) {
        strcat(client->command, buffer);
    } else {
        client->command = strdup(buffer);
    }

    return buffer_size;
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <server> <username> <password> <command>\n", argv[0]);
        return 1;
    }

    ftp_client_t client;
    memset(&client, 0, sizeof(ftp_client_t));

    client.url = strdup(argv[1]);
    client.username = strdup(argv[2]);
    client.password = strdup(argv[3]);
    client.command = strdup("");

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char ftp_url[MAX_URL_LEN];
        snprintf(ftp_url, MAX_URL_LEN, "ftp://%s:%s@%s", client.username, client.password, client.url);

        curl_easy_setopt(curl, CURLOPT_URL, ftp_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &client);

        printf("Sending command: %s\n", client.command);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("FTP command failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("FTP command succeeded\n");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}
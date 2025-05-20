//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

struct http_client {
    CURL *curl;
    char *url;
    char *method;
    struct curl_slist *headers;
    char *post_data;
    size_t post_data_len;
};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *buffer = (char*)malloc(size * nmemb);
    memcpy(buffer, contents, size * nmemb);
    printf("%s", buffer);
    free(buffer);
    return size * nmemb;
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    fprintf(stderr, "Download progress: %lu bytes received out of %lu\n", dlnow, dltotal);
    return 0;
}

void http_client_init(struct http_client *client)
{
    client->curl = curl_easy_init();
    if (!client->curl) {
        fprintf(stderr, "Failed to initialize curl\n");
        exit(1);
    }
}

void http_client_cleanup(struct http_client *client)
{
    curl_easy_cleanup(client->curl);
}

void http_client_set_url(struct http_client *client, const char *url)
{
    client->url = strdup(url);
}

void http_client_set_method(struct http_client *client, const char *method)
{
    client->method = strdup(method);
}

void http_client_add_header(struct http_client *client, const char *header)
{
    client->headers = curl_slist_append(client->headers, header);
}

void http_client_set_post_data(struct http_client *client, const char *data, size_t len)
{
    client->post_data = strndup(data, len);
    client->post_data_len = len;
}

int http_client_perform(struct http_client *client)
{
    CURLcode res;
    curl_easy_setopt(client->curl, CURLOPT_URL, client->url);
    curl_easy_setopt(client->curl, CURLOPT_CUSTOMREQUEST, client->method);
    curl_easy_setopt(client->curl, CURLOPT_POSTFIELDS, client->post_data);
    curl_easy_setopt(client->curl, CURLOPT_POSTFIELDSIZE, client->post_data_len);
    curl_easy_setopt(client->curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(client->curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
    curl_easy_setopt(client->curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(client->curl, CURLOPT_HTTPHEADER, client->headers);
    res = curl_easy_perform(client->curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 1;
    }
    return 0;
}

int main()
{
    struct http_client client;
    http_client_init(&client);
    http_client_set_url(&client, "https://jsonplaceholder.typicode.com/posts/1");
    http_client_set_method(&client, "GET");
    http_client_perform(&client);
    http_client_cleanup(&client);
    return 0;
}
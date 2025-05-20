//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

struct Buffer {
    char *data;
    size_t size;
};

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    struct Buffer *buffer = (struct Buffer*) stream;
    size_t total_size = size * nmemb;
    
    buffer->data = realloc(buffer->data, buffer->size + total_size + 1);
    if (!buffer->data) {
        fprintf(stderr, "Memory error");
        return 0;
    }
    
    memcpy(&(buffer->data[buffer->size]), ptr, total_size);
    buffer->size += total_size;
    buffer->data[buffer->size] = '\0';
    
    return total_size;
}

int main(int argc, char *argv[]) {
    CURL *curl = NULL;
    CURLcode res;
    struct curl_slist *headers = NULL;
    struct Buffer buffer = { .data=NULL, .size=0 };
    char *user = NULL, *pass = NULL, *host = NULL, *port = NULL, *folder = NULL;
    char *url = NULL, *fullurl = NULL;
    
    if (argc < 6) {
        printf("Usage: %s <user> <pass> <host> <port> <folder>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    user = argv[1];
    pass = argv[2];
    host = argv[3];
    port = argv[4];
    folder = argv[5];
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if (curl) {
        url = "imap://%s:%s@%s:%s/%s";
        fullurl = malloc(strlen(url) + strlen(user) + strlen(pass) + strlen(host) + strlen(port) + strlen(folder) + 1);
        sprintf(fullurl, url, user, pass, host, port, folder);
        
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "FETCH 1:* (FLAGS ENVELOPE BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)])");
        curl_easy_setopt(curl, CURLOPT_USERNAME, user);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, pass);
        curl_easy_setopt(curl, CURLOPT_URL, fullurl);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*) &buffer);
        
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("DATA:\n%s\n", buffer.data);
        }
        
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    
    free(fullurl);
    curl_global_cleanup();
    
    return EXIT_SUCCESS;
}
//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <curl/curl.h>

#define MAX_REQUESTS 10
#define PORT "8080"
#define IP_ADDRESS "192.168.1.2"

struct Request {
    char *method;
    char *path;
    char *version;
};

void *handle_request(void *ptr) {
    struct Request *request = (struct Request *)ptr;
    char url[100];
    CURL *curl;
    CURLcode res;

    sprintf(url, "http://%s:%s/%s HTTP/1.1", IP_ADDRESS, PORT, request->path);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request->method);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, request->version);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    free(request);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_REQUESTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        struct Request *request = (struct Request *)malloc(sizeof(struct Request));
        request->method = strdup("GET");
        request->path = strdup("/lights");
        request->version = strdup("HTTP/1.1");

        if (pthread_create(&thread_id, NULL, handle_request, request)) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        close(new_socket);
    }

    return 0;
}
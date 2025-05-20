//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFSIZE 1024

struct thread_data {
    int sock;
    char *url;
};

void *thread_main(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    int sock = data->sock;
    char *url = data->url;

    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "curl_easy_init() failed\n");
        return NULL;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, sock);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    close(sock);
    free(data);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind() failed");
        close(sock);
        return EXIT_FAILURE;
    }

    if (listen(sock, 5) == -1) {
        perror("listen() failed");
        close(sock);
        return EXIT_FAILURE;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept() failed");
            continue;
        }

        char buf[BUFSIZE];
        int n = recv(client_sock, buf, BUFSIZE - 1, 0);
        if (n == -1) {
            perror("recv() failed");
            close(client_sock);
            continue;
        }
        buf[n] = '\0';

        char *url = malloc(strlen(buf) + 2);
        strcpy(url, "https://");
        strcat(url, buf);

        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->sock = client_sock;
        data->url = url;

        pthread_t thread;
        if (pthread_create(&thread, NULL, thread_main, data) != 0) {
            perror("pthread_create() failed");
            close(client_sock);
            free(data);
            continue;
        }
    }

    close(sock);
    return EXIT_SUCCESS;
}
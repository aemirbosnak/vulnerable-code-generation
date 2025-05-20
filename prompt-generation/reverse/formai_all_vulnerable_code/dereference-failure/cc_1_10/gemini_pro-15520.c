//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <assert.h>
#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 100
#define MAX_REQUEST_SIZE 1024

struct connection {
    int fd;
    CURL *curl;
    char request[MAX_REQUEST_SIZE];
    size_t request_len;
    char response[MAX_REQUEST_SIZE];
    size_t response_len;
};

struct thread_args {
    int fd;
    struct connection *connection;
};

void *thread_main(void *args) {
    struct thread_args *thread_args = (struct thread_args *)args;
    int fd = thread_args->fd;
    struct connection *connection = thread_args->connection;

    // Receive the request from the client.
    int n = recv(fd, connection->request, MAX_REQUEST_SIZE, 0);
    if (n < 0) {
        perror("recv");
        goto cleanup;
    }
    connection->request_len = n;

    // Sanitize the request.
    char *sanitized_request = curl_escape(connection->request, connection->request_len);
    if (!sanitized_request) {
        fprintf(stderr, "curl_escape failed\n");
        goto cleanup;
    }

    // Send the sanitized request to the server.
    CURLcode res = curl_easy_setopt(connection->curl, CURLOPT_URL, sanitized_request);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_setopt failed: %s\n", curl_easy_strerror(res));
        goto cleanup;
    }

    // Receive the response from the server.
    res = curl_easy_perform(connection->curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform failed: %s\n", curl_easy_strerror(res));
        goto cleanup;
    }

    // Send the response to the client.
    n = send(fd, connection->response, connection->response_len, 0);
    if (n < 0) {
        perror("send");
        goto cleanup;
    }

cleanup:
    // Clean up.
    curl_easy_cleanup(connection->curl);
    free(sanitized_request);
    free(connection);
    close(fd);

    return NULL;
}

int main() {
    // Initialize libcurl.
    curl_global_init(CURL_GLOBAL_ALL);

    // Create a socket.
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket options.
    int yes = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Bind the socket to an address.
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for connections.
    if (listen(fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        return 1;
    }

    // Accept connections and create threads to handle them.
    while (1) {
        int client_fd = accept(fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // Create a connection.
        struct connection *connection = malloc(sizeof(struct connection));
        if (!connection) {
            fprintf(stderr, "malloc failed\n");
            close(client_fd);
            continue;
        }

        // Initialize the connection.
        connection->fd = client_fd;
        connection->curl = curl_easy_init();
        if (!connection->curl) {
            fprintf(stderr, "curl_easy_init failed\n");
            free(connection);
            close(client_fd);
            continue;
        }

        // Create a thread to handle the connection.
        struct thread_args *thread_args = malloc(sizeof(struct thread_args));
        if (!thread_args) {
            fprintf(stderr, "malloc failed\n");
            curl_easy_cleanup(connection->curl);
            free(connection);
            close(client_fd);
            continue;
        }

        thread_args->fd = client_fd;
        thread_args->connection = connection;

        pthread_t thread;
        int res = pthread_create(&thread, NULL, thread_main, thread_args);
        if (res != 0) {
            fprintf(stderr, "pthread_create failed: %s\n", strerror(res));
            free(thread_args);
            curl_easy_cleanup(connection->curl);
            free(connection);
            close(client_fd);
            continue;
        }

        // Detach the thread so that it can run concurrently with the main thread.
        pthread_detach(thread);
    }

    // Clean up.
    curl_global_cleanup();

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

typedef struct {
    int fd;
    struct sockaddr_in addr;
    socklen_t addrlen;
} client_t;

typedef struct {
    int fd;
    char *buf;
    size_t buflen;
    size_t bufpos;
} request_t;

typedef struct {
    client_t *client;
    request_t *request;
    char *response;
    size_t response_len;
} session_t;

void *handle_session(void *arg) {
    session_t *session = (session_t *) arg;
    client_t *client = session->client;
    request_t *request = session->request;
    char *response = session->response;
    size_t response_len = session->response_len;

    // Read the request from the client
    while (1) {
        ssize_t n = read(client->fd, request->buf + request->bufpos, request->buflen - request->bufpos);
        if (n <= 0) {
            break;
        }
        request->bufpos += n;
        if (request->bufpos == request->buflen) {
            break;
        }
    }

    // Parse the request
    char *method = strtok(request->buf, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Handle the request
    if (strcmp(method, "GET") == 0) {
        if (strcmp(path, "/") == 0) {
            response = "<h1>Welcome to my website!</h1>";
            response_len = strlen(response);
        } else {
            response = "<h1>404 Not Found</h1>";
            response_len = strlen(response);
        }
    } else {
        response = "<h1>501 Not Implemented</h1>";
        response_len = strlen(response);
    }

    // Send the response to the client
    write(client->fd, response, response_len);

    // Close the client connection
    close(client->fd);

    // Free the session
    free(session->client);
    free(session->request);
    free(session->response);
    free(session);

    return NULL;
}

int main() {
    // Create a socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (listen(fd, 5) < 0) {
        perror("listen");
        return 1;
    }

    // Accept connections
    while (1) {
        client_t *client = (client_t *) malloc(sizeof(client_t));
        client->addrlen = sizeof(client->addr);
        client->fd = accept(fd, (struct sockaddr *) &client->addr, &client->addrlen);
        if (client->fd < 0) {
            perror("accept");
            continue;
        }

        // Create a request
        request_t *request = (request_t *) malloc(sizeof(request_t));
        request->buf = (char *) malloc(4096);
        request->buflen = 4096;
        request->bufpos = 0;

        // Create a session
        session_t *session = (session_t *) malloc(sizeof(session_t));
        session->client = client;
        session->request = request;
        session->response = NULL;
        session->response_len = 0;

        // Create a thread to handle the session
        pthread_t tid;
        pthread_create(&tid, NULL, handle_session, session);
    }

    // Close the socket
    close(fd);

    return 0;
}
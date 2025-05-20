//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define HTTP_PORT 80

typedef struct {
    int sockfd;
    char *request;
    char *response;
    int request_len;
    int response_len;
} http_session;

void http_proxy_init(http_session *session, int client_sockfd) {
    session->sockfd = client_sockfd;
    session->request = malloc(BUFFER_SIZE);
    session->response = malloc(BUFFER_SIZE);
    session->request_len = 0;
    session->response_len = 0;
}

void http_proxy_free(http_session *session) {
    close(session->sockfd);
    free(session->request);
    free(session->response);
}

int http_proxy_read(http_session *session) {
    int n = read(session->sockfd, session->request + session->request_len, BUFFER_SIZE - session->request_len);
    if (n < 0) {
        return -1;
    }
    session->request_len += n;
    return n;
}

int http_proxy_write(http_session *session) {
    int n = write(session->sockfd, session->response, session->response_len);
    if (n < 0) {
        return -1;
    }
    session->response_len -= n;
    return n;
}

int http_proxy_forward(http_session *session) {
    struct hostent *host;
    struct sockaddr_in server_addr;
    int server_sockfd;
    int n;

    // Parse the request
    char *host_name = strstr(session->request, "Host: ");
    if (host_name == NULL) {
        return -1;
    }
    host_name += 6;
    char *host_end = strchr(host_name, '\r');
    if (host_end == NULL) {
        return -1;
    }
    *host_end = '\0';

    // Resolve the hostname
    host = gethostbyname(host_name);
    if (host == NULL) {
        return -1;
    }

    // Create a socket to the server
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        return -1;
    }

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(HTTP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(server_sockfd);
        return -1;
    }

    // Forward the request
    if (write(server_sockfd, session->request, session->request_len) < 0) {
        close(server_sockfd);
        return -1;
    }

    // Receive the response
    while ((n = read(server_sockfd, session->response + session->response_len, BUFFER_SIZE - session->response_len)) > 0) {
        session->response_len += n;
    }
    close(server_sockfd);

    return 0;
}

int main(int argc, char *argv[]) {
    int client_sockfd, port;
    struct sockaddr_in server_addr;
    socklen_t client_addr_len;
    http_session session;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }
    port = atoi(argv[1]);

    // Create a socket
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(client_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(client_sockfd);
        return 1;
    }

    // Listen for connections
    listen(client_sockfd, 5);

    // Accept connections
    while (1) {
        client_addr_len = sizeof(server_addr);
        int new_sockfd = accept(client_sockfd, (struct sockaddr *)&server_addr, &client_addr_len);
        if (new_sockfd < 0) {
            perror("accept");
            continue;
        }

        // Create a new session
        http_proxy_init(&session, new_sockfd);

        // Read the request
        if (http_proxy_read(&session) < 0) {
            http_proxy_free(&session);
            close(new_sockfd);
            continue;
        }

        // Forward the request
        if (http_proxy_forward(&session) < 0) {
            http_proxy_free(&session);
            close(new_sockfd);
            continue;
        }

        // Write the response
        while (session.response_len > 0) {
            if (http_proxy_write(&session) < 0) {
                http_proxy_free(&session);
                close(new_sockfd);
                break;
            }
        }

        // Free the session
        http_proxy_free(&session);
        close(new_sockfd);
    }

    // Close the socket
    close(client_sockfd);

    return 0;
}
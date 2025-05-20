//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *hostname;
    uint16_t port;
} server_info;

static bool parse_server_info(const char *uri, server_info *info) {
    char *host_start = NULL, *host_end = NULL, *port_start = NULL, *port_end = NULL;
    
    host_start = strstr(uri, "://") + 3;
    if (host_start == NULL) {
        return false;
    }

    host_end = strchr(host_start, ':');
    if (host_end == NULL) {
        host_end = strchr(host_start, '/');
    }

    port_start = strchr(host_start, ':');
    if (port_start == NULL) {
        port_start = "80";
    } else {
        port_start++;
    }

    port_end = strchr(port_start, '/');

    if (host_end == NULL || port_end == NULL) {
        return false;
    }
    
    info->hostname = strndup(host_start, host_end - host_start);
    info->port = atoi(port_start);

    return true;
}

static int create_socket(const server_info *info) {
    struct sockaddr_in addr = { 0 };
    int sockfd;
    struct addrinfo *result, *rp;
    int status;

    status = getaddrinfo(info->hostname, NULL, NULL, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return -1;
    }

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        addr.sin_family = rp->ai_family;
        addr.sin_port = htons(info->port);
        addr.sin_addr = ((struct sockaddr_in *)rp->ai_addr)->sin_addr;
        if (connect(sockfd, (struct sockaddr *)&addr, rp->ai_addrlen) == 0) {
            break;
        }
        close(sockfd);
    }

    freeaddrinfo(result);

    return sockfd;
}

static int send_request(int sockfd, const char *request) {
    int len = strlen(request);
    int sent = 0;
    while (sent < len) {
        int n = send(sockfd, request + sent, len - sent, 0);
        if (n == -1) {
            return -1;
        }
        sent += n;
    }
    return sent;
}

static int receive_response(int sockfd, char *buffer, int len) {
    int received = 0;
    while (received < len) {
        int n = recv(sockfd, buffer + received, len - received, 0);
        if (n == -1) {
            return -1;
        }
        received += n;
    }
    return received;
}

static void print_response(const char *buffer, int len) {
    printf("HTTP Response:\n");
    printf("%.*s", len, buffer);
}

static void cleanup(int sockfd, char *hostname) {
    close(sockfd);
    free(hostname);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URI>\n", argv[0]);
        return 1;
    }

    server_info info = { 0 };
    if (!parse_server_info(argv[1], &info)) {
        fprintf(stderr, "Invalid URI: %s\n", argv[1]);
        return 1;
    }
    char *hostname = strdup(info.hostname);

    int sockfd = create_socket(&info);
    if (sockfd == -1) {
        fprintf(stderr, "Could not create socket\n");
        cleanup(sockfd, hostname);
        return 1;
    }

    const char *request = "GET / HTTP/1.1\r\n"
                         "Host: %s\r\n"
                         "Connection: close\r\n"
                         "\r\n";

    int len = snprintf(NULL, 0, request, hostname);
    char buffer[len + 1];
    snprintf(buffer, len + 1, request, hostname);
    if (send_request(sockfd, buffer) == -1) {
        fprintf(stderr, "Could not send request\n");
        cleanup(sockfd, hostname);
        return 1;
    }

    len = BUFFER_SIZE;
    if (receive_response(sockfd, buffer, len) == -1) {
        fprintf(stderr, "Could not receive response\n");
        cleanup(sockfd, hostname);
        return 1;
    }

    print_response(buffer, len);

    cleanup(sockfd, hostname);

    return 0;
}
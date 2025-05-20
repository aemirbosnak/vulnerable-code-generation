//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 80

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *host = url;
    char *path = strstr(url, "/");
    if (path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path++;
    }

    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        fprintf(stderr, "Unable to resolve host %s: %s\n", host, strerror(errno));
        return 1;
    }

    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;

    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Unable to create socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *addr_list[0];

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Unable to connect to server: %s\n", strerror(errno));
        return 1;
    }

    char *request = malloc(BUFFER_SIZE * sizeof(char));
    snprintf(request, BUFFER_SIZE,
             "GET %s HTTP/1.0\r\n"
                     "Host: %s\r\n"
                     "User-Agent: AdaLovelyClient\r\n"
                     "\r\n", path, host);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        fprintf(stderr, "Unable to send request to server: %s\n", strerror(errno));
        return 1;
    }

    char *buffer = malloc(BUFFER_SIZE * sizeof(char));
    ssize_t bytes_received;

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        fflush(stdout);
    }

    free(request);
    free(buffer);
    close(sockfd);

    return 0;
}
//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {

    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port username\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *username = argv[3];

    printf("Connecting to %s port %s...\n", hostname, port);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;    
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(hostname, port, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    status = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (status == -1) {
        perror("connect");
        return 1;
    }

    printf("Connected.\n");

    char buffer[MAX_BUFFER];

    ssize_t bytes_received = read(sockfd, buffer, MAX_BUFFER);
    buffer[bytes_received] = '\0';

    printf("%s\n", buffer);

    snprintf(buffer, MAX_BUFFER, "USER %s\r\n", username);
    status = send(sockfd, buffer, strlen(buffer), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    bytes_received = read(sockfd, buffer, MAX_BUFFER);
    buffer[bytes_received] = '\0';

    printf("%s\n", buffer);

    snprintf(buffer, MAX_BUFFER, "PASS ");
    char *password = getpass("Password: ");
    snprintf(buffer+strlen(buffer), MAX_BUFFER-strlen(buffer), "%s\r\n", password);

    status = send(sockfd, buffer, strlen(buffer), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    bytes_received = read(sockfd, buffer, MAX_BUFFER);
    buffer[bytes_received] = '\0';

    printf("%s\n", buffer);

    snprintf(buffer, MAX_BUFFER, "STAT\r\n");
    status = send(sockfd, buffer, strlen(buffer), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    bytes_received = read(sockfd, buffer, MAX_BUFFER);
    buffer[bytes_received] = '\0';

    printf("%s\n", buffer);

    snprintf(buffer, MAX_BUFFER, "QUIT\r\n");
    status = send(sockfd, buffer, strlen(buffer), 0);
    if (status == -1) {
        perror("send");
        return 1;
    }

    bytes_received = read(sockfd, buffer, MAX_BUFFER);
    buffer[bytes_received] = '\0';

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}
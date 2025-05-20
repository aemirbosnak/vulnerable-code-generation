//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int host_len;
    int opt = 1;

    // Set the socket options
    ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));
    if (ret < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    memset(&server_addr, 0, sizeof(server_addr));
    host_len = strlen(argv[1]);
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    // Send the request
    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("connect");
        exit(1);
    }

    // Send the request
    send(sockfd, "GET / HTTP/1.1\r\nHost: ", strlen("GET / HTTP/1.1\r\nHost: "), 0);
    while (1) {
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret < 0) {
            perror("recv");
            exit(1);
        } else if (ret == 0) {
            printf("Connection closed\n");
            break;
        }
        printf("Received %d bytes: %s\n", ret, buffer);
    }

    // Close the socket
    close(sockfd);
    return 0;
}
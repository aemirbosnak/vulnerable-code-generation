//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    struct hostent* host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        exit(1);
    }
    memcpy(&server_addr.sin_addr, host_info->h_addr_list[0], host_info->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        exit(1);
    }

    char* username = "anonymous";
    char* password = "example@example.com";
    char buf[MAX_DATA_SIZE];
    snprintf(buf, MAX_DATA_SIZE, "USER %s\r\n", username);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_DATA_SIZE, 0);
    printf("%s", buf);

    snprintf(buf, MAX_DATA_SIZE, "PASS %s\r\n", password);
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_DATA_SIZE, 0);
    printf("%s", buf);

    snprintf(buf, MAX_DATA_SIZE, "LIST\r\n");
    send(sockfd, buf, strlen(buf), 0);
    while (recv(sockfd, buf, MAX_DATA_SIZE, 0) > 0) {
        printf("%s", buf);
    }

    snprintf(buf, MAX_DATA_SIZE, "QUIT\r\n");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, buf, MAX_DATA_SIZE, 0);
    printf("%s", buf);

    close(sockfd);

    return 0;
}
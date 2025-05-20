//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: cannot resolve hostname %s\n", hostname);
        return 2;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: cannot create socket\n");
        return 3;
    }

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    memcpy(&serveraddr.sin_addr.s_addr, host->h_addr, host->h_length);
    serveraddr.sin_port = htons(21);

    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error: cannot connect to ftp server\n");
        return 4;
    }

    char buffer[256];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}
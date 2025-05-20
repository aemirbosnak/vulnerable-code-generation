//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 110

int main() {
    struct sockaddr_in serverAddr;
    int sockfd, n;
    char buf[1024];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        perror("ERROR, couldn't convert address");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char command[100];
    sprintf(command, "USER username\r\n");
    write(sockfd, command, strlen(command));

    sprintf(command, "PASS password\r\n");
    write(sockfd, command, strlen(command));

    sprintf(command, "LIST\r\n");
    write(sockfd, command, strlen(command));

    n = read(sockfd, buf, sizeof(buf));
    printf("Server replied: %s\n", buf);

    close(sockfd);

    return 0;
}
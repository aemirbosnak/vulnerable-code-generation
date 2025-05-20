//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(command, "USER ");
    strcat(command, argv[2]);
    strcat(command, "\r\n");

    strcpy(command, "PASS ");
    strcat(command, argv[3]);
    strcat(command, "\r\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket failed\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connect failed\n");
        close(sockfd);
        return 1;
    }

    if (send(sockfd, command, strlen(command), 0) == -1) {
        printf("Error: send failed\n");
        close(sockfd);
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == 0) {
            printf("Disconnected\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}
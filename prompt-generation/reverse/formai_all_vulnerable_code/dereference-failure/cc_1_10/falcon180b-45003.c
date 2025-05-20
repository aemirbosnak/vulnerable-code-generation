//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX];
    char command[MAX];

    if(argc < 4) {
        printf("Usage:./ftp_client <hostname> <username> <password>\n");
        exit(1);
    }

    strcpy(command, argv[1]);
    strcat(command, " ");
    strcat(command, argv[2]);
    strcat(command, " ");
    strcat(command, argv[3]);

    printf("Connecting to %s...\n", command);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, command, &servaddr.sin_addr);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to %s\n", command);
        exit(1);
    }

    printf("Connected to %s\n", command);

    while(1) {
        printf("Enter command: ");
        fgets(buffer, MAX, stdin);

        if(strcmp(buffer, "quit") == 0) {
            break;
        }

        send(sockfd, buffer, strlen(buffer), 0);

        memset(buffer, 0, MAX);
        recv(sockfd, buffer, MAX, 0);

        printf("%s\n", buffer);
    }

    close(sockfd);

    return 0;
}
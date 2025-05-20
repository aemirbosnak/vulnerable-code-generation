//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(errno);
    }

    printf("Enter FTP server IP address: ");
    scanf("%s", inet_ntoa(server_addr.sin_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(errno);
    }

    printf("Connected to FTP server\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        send(sockfd, command, strlen(command), 0);

        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            perror("recv failed");
            exit(errno);
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
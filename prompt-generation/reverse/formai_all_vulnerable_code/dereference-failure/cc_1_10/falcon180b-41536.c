//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define MAX_COMMAND_LEN 512
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *command = (char *) malloc(MAX_COMMAND_LEN * sizeof(char));
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        exit(1);
    }

    strcpy(command, "USER ");
    strcat(command, argv[2]);
    strcat(command, "\r\n");

    strcpy(command, "PASS ");
    strcat(command, argv[3]);
    strcat(command, "\r\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send(sockfd, command, strlen(command), 0);

    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    free(command);
    return 0;
}
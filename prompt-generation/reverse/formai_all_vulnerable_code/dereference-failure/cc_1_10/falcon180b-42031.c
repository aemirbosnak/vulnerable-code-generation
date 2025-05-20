//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;
    char *filename;
    char *username;
    char *password;

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Connecting to server...\n");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");
    printf("Entering username and password...\n");

    username = argv[2];
    password = argv[3];

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n == -1) {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Login successful\n");

    while (1) {
        printf("Enter command (get/put/quit): ");
        scanf("%s", buffer);

        send(sockfd, buffer, strlen(buffer), 0);

        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received: %s\n", buffer);

        if (strcmp(buffer, "QUIT") == 0) {
            break;
        }
    }

    close(sockfd);
    printf("Exiting program\n");

    return 0;
}
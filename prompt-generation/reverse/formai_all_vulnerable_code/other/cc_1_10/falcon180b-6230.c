//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *username, *password;
    char *host;

    if (argc < 3) {
        printf("Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    username = argv[2];
    password = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    send_command(sockfd, "USER", username);
    send_command(sockfd, "PASS", password);
    send_command(sockfd, "STAT");

    while (1) {
        retval = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (retval == 0) {
            printf("Server disconnected\n");
            break;
        } else if (retval == -1) {
            printf("Error receiving data\n");
            return 1;
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}

int send_command(int sockfd, char *command, char *username) {
    char buffer[BUFFER_SIZE];
    int retval;

    sprintf(buffer, "%s %s\r\n", command, username);
    retval = send(sockfd, buffer, strlen(buffer), 0);
    if (retval == -1) {
        printf("Error sending command\n");
        return -1;
    }

    return 0;
}
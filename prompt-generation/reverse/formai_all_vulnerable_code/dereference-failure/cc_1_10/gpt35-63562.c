//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s SERVER_IP SERVER_PORT\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }

    // initialize server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_ip);
    serv_addr.sin_port = htons(server_port);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server.");
    }
    printf("Connected to server %s:%d\n", server_ip, server_port);

    // receive welcome message
    char buffer[BUFF_SIZE];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) < 0) {
        error("Error receiving message from server.");
    }
    printf("%s", buffer);

    // loop for command input
    while (true) {
        printf("Enter FTP command: ");
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character

        // send command to server
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            error("Error sending command to server.");
        }

        // quit if command is "quit"
        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        // receive response from server
        memset(buffer, 0, sizeof(buffer));
        if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) < 0) {
            error("Error receiving response from server.");
        }
        printf("%s", buffer);
    }

    // close socket and exit
    close(sockfd);
    return 0;
}
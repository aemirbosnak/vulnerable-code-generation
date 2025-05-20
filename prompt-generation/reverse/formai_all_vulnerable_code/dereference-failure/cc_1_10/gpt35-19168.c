//FormAI DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE 512

fd_set readfds;

void read_from_server(int sockfd) {
    char buffer[MAX_BUFF_SIZE];
    memset(buffer, 0, MAX_BUFF_SIZE);
    int nbytes = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (nbytes < 0)
        perror("Error reading from server");
    printf("%s\n", buffer);
}

void send_to_server(int sockfd) {
    char buffer[MAX_BUFF_SIZE];
    memset(buffer, 0, MAX_BUFF_SIZE);
    printf("Enter message to server:\n");
    fgets(buffer, MAX_BUFF_SIZE, stdin);
    write(sockfd, buffer, strlen(buffer));
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(strtol(argv[2], NULL, 10));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) < 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server as %d\n", sockfd);

    while (true) {
        FD_ZERO(&readfds); // Clear all file descriptors from the set
        FD_SET(0, &readfds); // Add standard input (0) to the set
        FD_SET(sockfd, &readfds); // Add the socket to the set

        int status = select(sockfd + 1, &readfds, NULL, NULL, NULL);
        if (status < 0)
            perror("Error selecting file descriptors");

        if (FD_ISSET(sockfd, &readfds))
            read_from_server(sockfd);
        else if (FD_ISSET(0, &readfds))
            send_to_server(sockfd);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}
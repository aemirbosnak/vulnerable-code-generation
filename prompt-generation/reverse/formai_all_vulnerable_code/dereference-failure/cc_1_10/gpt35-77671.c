//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

const int MAX_SIZE = 1024;

void read_server_response(int sfd) {
    char response[MAX_SIZE + 1];
    memset(response, 0, MAX_SIZE + 1);
    ssize_t recvd = recv(sfd, (void *) response, MAX_SIZE, 0);
    if (recvd == -1 || recvd == 0) {
        printf("Error receiving response from server\n");
        return;
    }
    printf("Server Response: %s\n", response);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <server_ip_address> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    int server_port = atoi(argv[2]);

    struct sockaddr_in server_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(server_port),
    };
    if (inet_pton(AF_INET, server_address, &server_addr.sin_addr) < 0) {
        printf("Invalid server IP address\n");
        exit(EXIT_FAILURE);
    }

    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    printf("Successfully connected to server\n");

    while (true) {
        printf("\nEnter IMAP command: ");
        char command[MAX_SIZE + 1];
        memset(command, 0, MAX_SIZE + 1);
        fgets(command, MAX_SIZE, stdin);
        ssize_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        if (send(sfd, (void *)command, strlen(command), 0) == -1) {
            printf("Error sending command to server\n");
            exit(EXIT_FAILURE);
        }

        if (strcmp(command, "exit") == 0) {
            printf("Disconnecting from server...\n");
            break;
        }

        read_server_response(sfd);
    }

    close(sfd);
    return 0;
}
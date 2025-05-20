//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage : %s <IMAP server> <port number> <username>\n", argv[0]);
        return 0;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *username = argv[3];

    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    int sock;
    struct sockaddr_in server_address = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        printf("Invalid address / Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    printf("Connected to %s:%d successfully!\n", server_ip, server_port);

    read(sock, response, BUFFER_SIZE);
    printf("%s", response);

    snprintf(command, BUFFER_SIZE, "a1 LOGIN %s \n", username);
    write(sock, command, strlen(command));
    read(sock, response, BUFFER_SIZE);
    printf("%s", response);

    snprintf(command, BUFFER_SIZE, "a2 LIST \"\" *\n");
    write(sock, command, strlen(command));
    read(sock, response, BUFFER_SIZE);
    printf("%s", response);

    close(sock);

    return 0;
}
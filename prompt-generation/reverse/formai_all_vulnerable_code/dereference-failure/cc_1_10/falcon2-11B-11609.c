//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, port;
    struct sockaddr_in server;
    char buffer[MAX_BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    port = socket(AF_INET, SOCK_STREAM, 0);
    if (port == -1) {
        perror("Error creating socket");
        return 1;
    }

    if (connect(port, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    printf("Connected to SMTP server\n");

    while (1) {
        int num_bytes_read = recv(port, buffer, MAX_BUF_SIZE, 0);
        if (num_bytes_read < 0) {
            perror("Error reading from socket");
            return 1;
        }

        printf("%s", buffer);

        int num_bytes_written = send(port, "EHLO client", strlen("EHLO client"), 0);
        if (num_bytes_written < 0) {
            perror("Error writing to socket");
            return 1;
        }
    }

    close(port);
    return 0;
}
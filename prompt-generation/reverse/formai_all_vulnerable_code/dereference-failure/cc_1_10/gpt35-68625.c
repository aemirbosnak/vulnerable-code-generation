//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXBUF 512

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server IP> <server port> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd == -1) {
        perror("Error creating socket.");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        perror("Invalid server IP address.");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server.");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    char buffer[MAXBUF];
    memset(buffer, 0, MAXBUF);

    sprintf(buffer, "RETR %s\n", argv[3]);

    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending command to server.");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[3], "wb");
    if (file == NULL) {
        perror("Error opening file for writing.");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    int bytes_received = 0;

    while ((bytes_received = recv(sock_fd, buffer, MAXBUF, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, file);
    }

    if (bytes_received < 0) {
        perror("Error receiving data from server.");
    }

    fclose(file);
    close(sock_fd);

    return 0;
}
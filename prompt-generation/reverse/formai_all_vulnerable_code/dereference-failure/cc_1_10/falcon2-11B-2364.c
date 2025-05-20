//Falcon2-11B DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, client_fd, n;
    char buffer[MAX_BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <port> <message>\n", argv[0]);
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return 1;
    }

    listen(server_fd, 5);

    client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("accept");
        return 1;
    }

    if (read(client_fd, buffer, MAX_BUFFER_SIZE) < 0) {
        perror("read");
        return 1;
    }

    buffer[strcspn(buffer, "\r\n")] = '\0';
    printf("Client: %s\n", buffer);

    if (write(client_fd, "Server: Hello, client!\n", 25) < 0) {
        perror("write");
        return 1;
    }

    close(client_fd);

    return 0;
}
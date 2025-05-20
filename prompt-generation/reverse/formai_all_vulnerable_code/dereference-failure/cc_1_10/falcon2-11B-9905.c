//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

int main() {
    int socket_fd, n;
    struct sockaddr_in server_address;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    memcpy((char *)&server_address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    n = recv(socket_fd, buffer, BUFFER_SIZE, 0);

    if (n < 0) {
        perror("Receive failed");
        exit(1);
    }

    printf("%s", buffer);

    close(socket_fd);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd, numbytes;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage:./client <IP address> <port number> <message>\n");
        return 1;
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    strcpy(send_buffer, argv[3]);
    numbytes = send(socket_fd, send_buffer, strlen(send_buffer), 0);

    if (numbytes == -1) {
        printf("Error sending message\n");
        return 1;
    }

    printf("Message sent successfully\n");

    numbytes = recv(socket_fd, recv_buffer, BUFFER_SIZE, 0);

    if (numbytes == -1) {
        printf("Error receiving message\n");
        return 1;
    }

    printf("Received message: %s\n", recv_buffer);

    close(socket_fd);

    return 0;
}
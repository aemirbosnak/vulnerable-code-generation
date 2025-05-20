//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    int socket_fd, portno, n;
    struct sockaddr_in server_address;
    struct hostent *server;

    char recv_buffer[1024], send_buffer[1024];

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname("mail.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR: Unable to resolve server address\n");
        exit(1);
    }

    portno = htons(110);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(portno);
    memcpy((char *) &server_address.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "ERROR: Unable to connect to server\n");
        exit(1);
    }

    while (1) {
        printf("Enter email address: ");
        fgets(recv_buffer, sizeof(recv_buffer), stdin);

        if (send(socket_fd, recv_buffer, strlen(recv_buffer), 0) < 0) {
            fprintf(stderr, "ERROR: Unable to send email address\n");
            exit(1);
        }

        printf("Enter password: ");
        fgets(send_buffer, sizeof(send_buffer), stdin);

        if (send(socket_fd, send_buffer, strlen(send_buffer), 0) < 0) {
            fprintf(stderr, "ERROR: Unable to send password\n");
            exit(1);
        }

        printf("Enter command: ");
        fgets(recv_buffer, sizeof(recv_buffer), stdin);

        if (send(socket_fd, recv_buffer, strlen(recv_buffer), 0) < 0) {
            fprintf(stderr, "ERROR: Unable to send command\n");
            exit(1);
        }

        if (recv(socket_fd, recv_buffer, sizeof(recv_buffer), 0) < 0) {
            fprintf(stderr, "ERROR: Unable to receive response\n");
            exit(1);
        }

        printf("Server response: %s\n", recv_buffer);
    }

    close(socket_fd);
    return 0;
}
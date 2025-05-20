//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define PASV_PORT 20

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (control_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct addrinfo *server_info = NULL;
    if (getaddrinfo(server, "21", NULL, &server_info)!= 0) {
        printf("Error resolving server address: %s\n", gai_strerror(errno));
        exit(1);
    }

    connect(control_socket, server_info->ai_addr, server_info->ai_addrlen);

    char *response;
    send(control_socket, "USER ", 5, 0);
    recv(control_socket, &response, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    send(control_socket, username, strlen(username), 0);
    recv(control_socket, &response, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    send(control_socket, "PASS ", 5, 0);
    send(control_socket, password, strlen(password), 0);
    recv(control_socket, &response, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    char *command = "PWD";
    send(control_socket, command, strlen(command), 0);
    recv(control_socket, &response, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    close(control_socket);

    return 0;
}
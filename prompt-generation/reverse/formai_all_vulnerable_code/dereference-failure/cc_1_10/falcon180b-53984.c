//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void error_handling(const char* message);

int main(int argc, char* argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(server_addr);

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <IP address> <port number> <message>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "localhost") == 0) {
        strcpy(server_addr.sin_addr.s_addr, inet_addr("127.0.0.1"));
    } else {
        if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
            error_handling("Invalid IP address");
        }
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error_handling("socket failed");
    }

    if (setsockopt(client_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error_handling("setsockopt");
    }

    if (connect(client_socket, (struct sockaddr*)&server_addr, addrlen) == -1) {
        error_handling("connect failed");
    }

    send(client_socket, argv[3], strlen(argv[3]), 0);
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
        error_handling("recv failed");
    }

    printf("Received message: %s\n", buffer);

    close(client_socket);

    return 0;
}

void error_handling(const char* message) {
    perror(message);
    exit(1);
}
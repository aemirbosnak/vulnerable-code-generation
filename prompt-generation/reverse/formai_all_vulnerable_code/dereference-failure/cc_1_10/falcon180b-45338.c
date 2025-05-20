//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER_PORT 8081
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    char message[BUFFER_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s message server_ip\n", argv[0]);
        return 1;
    }

    strcpy(message, argv[1]);
    strcpy(SERVER_IP, argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        close(sock);
        return 1;
    }

    send(sock, message, strlen(message), 0);

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            fprintf(stderr, "Error receiving data\n");
            close(sock);
            return 1;
        }

        buffer[bytes_received] = '\0';
        printf("%s\n", buffer);
    }

    close(sock);
    return 0;
}
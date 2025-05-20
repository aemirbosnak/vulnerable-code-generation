//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[1024];

    if (argc < 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        return 1;
    }

    while (1) {
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            break;
        }

        if (recv(client_socket, buffer, sizeof(buffer), 0) == -1) {
            perror("recv");
            break;
        }

        printf("Received message: %s\n", buffer);
    }

    close(client_socket);
    return 0;
}
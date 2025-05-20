//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_PACKET_SIZE 1024

int main() {
    int server_fd, new_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    int packet_size;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        packet_size = recv(new_socket, NULL, MAX_PACKET_SIZE, 0);
        if (packet_size < 0) {
            perror("Receive error");
            exit(EXIT_FAILURE);
        }

        printf("Received packet of size %d:\n", packet_size);
        printf("%s", (char*)malloc(packet_size));
        free(malloc(packet_size));

        send(new_socket, "Thank you for connecting!\n", strlen("Thank you for connecting!\n"), 0);

        close(new_socket);
    }

    close(server_fd);
    return 0;
}
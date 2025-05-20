//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(struct sockaddr_in);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(server_fd, 5) == -1) {
        perror("Error listening on socket");
        exit(1);
    }

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket == -1) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Connected to: %s\n", inet_ntoa(client_addr.sin_addr));

        while (1) {
            valread = recv(new_socket, &client_addr, sizeof(client_addr), 0);
            if (valread == 0) {
                break;
            }

            printf("Received request: %s\n", inet_ntoa(client_addr.sin_addr));
            send(new_socket, &client_addr, sizeof(client_addr), 0);

            printf("Sending response: %s\n", inet_ntoa(client_addr.sin_addr));
        }

        close(new_socket);
    }

    close(server_fd);
    return 0;
}
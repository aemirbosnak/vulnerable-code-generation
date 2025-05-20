//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        error_handling("socket failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("bind failed");
        return 1;
    }

    if (listen(server_socket, 10) < 0) {
        error_handling("listen failed");
        return 1;
    }

    printf("Server is listening on IP address %s and port %d\n", argv[1], atoi(argv[2]));

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if (client_socket == -1) {
            error_handling("accept failed");
            continue;
        }

        printf("Connection accepted from IP address %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                error_handling("recv failed");
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                error_handling("send failed");
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "Error: %s\n", message);
}
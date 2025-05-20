//FormAI DATASET v1.0 Category: Simple Web Server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void print_404_error(int sock) {
    char error_message[] = "HTTP/1.1 404 Not Found\r\n\r\n";
    send(sock, error_message, strlen(error_message), 0);
}

void print_success(int sock, FILE *file) {
    char *response = "HTTP/1.1 200 OK\r\n\r\n";
    send(sock, response, strlen(response), 0);

    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        send(sock, line, strlen(line), 0);
    }
}

void handle_client(int sock) {
    char buffer[1024];
    recv(sock, buffer, sizeof(buffer), 0);

    char *parsed = strtok(buffer, " ");
    parsed = strtok(NULL, " ");

    char filename[100] = ".";
    strcat(filename, parsed);

    if (access(filename, F_OK) == -1) {
        print_404_error(sock);
        return;
    }

    FILE *file = fopen(filename, "r");

    print_success(sock, file);

    fclose(file);
}

int main(int argc, char **argv) {
    int server_socket, client_socket, address_length;
    struct sockaddr_in server_address, client_address;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    memcpy(&server_address.sin_addr, &(struct in_addr){INADDR_ANY}, sizeof(struct in_addr));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    printf("Listening on port 8080\n");

    listen(server_socket, 5);

    while (1) {
        address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_length);

        if (client_socket < 0) {
            continue;
        }

        handle_client(client_socket);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}
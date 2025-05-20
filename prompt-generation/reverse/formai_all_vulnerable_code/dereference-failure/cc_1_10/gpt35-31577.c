//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char *server_ip;
    int port;
    char *message = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    char server_response[4096];

    if (argc < 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return -1;
    }

    server_ip = argv[1];
    port = atoi(argv[2]);

    client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0) {
        printf("Error creating socket!\n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Connection failed!\n");
        return -1;
    }

    if (send(client_socket, message, strlen(message), 0) < 0) {
        printf("Error sending message to server!\n");
        return -1;
    }

    memset(server_response, 0, sizeof(server_response));
    if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
        printf("Error receiving message from server!\n");
        return -1;
    }

    printf("Server response:\n %s\n", server_response);

    close(client_socket);

    return 0;
}
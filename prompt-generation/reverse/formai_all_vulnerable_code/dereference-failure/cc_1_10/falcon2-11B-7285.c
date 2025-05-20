//Falcon2-11B DATASET v1.0 Category: Networking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 12345

int main(int argc, char *argv[])
{
    int server_socket, new_socket, bytes_read, i;
    struct sockaddr_in server_address, client_address;
    struct hostent *server;
    char buffer[1024];

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR: hostname could not be resolved\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    memcpy((char *) &server_address.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("ERROR on listen");
        exit(1);
    }

    for (;;) {
        new_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &i);
        if (new_socket == -1) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection from %s port %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        memset(buffer, 0, sizeof(buffer));
        bytes_read = recv(new_socket, buffer, sizeof(buffer), 0);
        if (bytes_read == -1) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received: %s\n", buffer);
        send(new_socket, "Thank you for connecting!\n", strlen("Thank you for connecting!") + 1, 0);

        close(new_socket);
    }

    return 0;
}
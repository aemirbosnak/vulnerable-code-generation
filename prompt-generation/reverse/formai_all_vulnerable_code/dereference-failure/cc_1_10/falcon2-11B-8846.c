//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    int yes = 1;

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(0);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        error("ERROR opening socket");

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR on binding");

    listen(server_fd, MAX_CLIENTS);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &valread);
        if (new_socket < 0)
            error("ERROR on accept");

        printf("New client connected\n");

        while (1) {
            valread = recv(new_socket, &client_addr, sizeof(struct sockaddr_in), 0);
            if (valread < 0)
                error("ERROR reading from socket");

            printf("Client %s says: %s\n", inet_ntoa(client_addr.sin_addr), &valread);

            valread = send(new_socket, &client_addr, sizeof(struct sockaddr_in), 0);
            if (valread < 0)
                error("ERROR writing to socket");

            printf("Server says: %s\n", &valread);
        }
    }

    close(server_fd);
    return 0;
}
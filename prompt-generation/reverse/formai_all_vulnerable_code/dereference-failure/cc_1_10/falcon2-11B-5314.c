//Falcon2-11B DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in server_addr, client_addr;
    int yes = 1;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&valread);
        if (new_socket < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connected by client with address: %s\n", inet_ntoa(client_addr.sin_addr));

        char buffer[MAX_BUFFER_SIZE];
        valread = read(new_socket, buffer, sizeof(buffer));
        if (valread < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received: %s\n", buffer);

        valread = write(new_socket, buffer, sizeof(buffer));
        if (valread < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        close(new_socket);
    }

    return 0;
}
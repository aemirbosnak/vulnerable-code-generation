//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket, portno;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);

    if (argc!= 2) {
        fprintf(stderr, "Usage : %s <portno>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    if (portno <= 0 || portno > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket < 0) {
            perror("accept");
            exit(1);
        }

        char buffer[256];
        int nbytes;

        while ((nbytes = recv(new_socket, buffer, 255, 0)) > 0) {
            buffer[nbytes] = '\0';
            printf("Received: %s\n", buffer);
            send(new_socket, buffer, nbytes, 0);
        }

        close(new_socket);
    }

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int server_fd, new_socket, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr,"Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    new_socket = accept(server_fd, (struct sockaddr *) &serv_addr, (socklen_t *) &n);
    if (new_socket < 0) {
        perror("accept");
        exit(1);
    }

    while (1) {
        bzero(buffer, 1024);
        n = read(new_socket, buffer, 1024);
        if (n <= 0) {
            close(new_socket);
            exit(0);
        }

        printf("Received message: %s\n", buffer);
        write(new_socket, "ACK\n", 4);
    }

    return 0;
}
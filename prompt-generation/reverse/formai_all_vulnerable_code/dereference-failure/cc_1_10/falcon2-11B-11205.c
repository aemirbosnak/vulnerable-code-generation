//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BACKLOG 10

int main(int argc, char **argv) {
    struct sockaddr_in server_address;
    int sockfd;
    int port_number;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    for (;;) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_address, &client_address_len);
        if (client_sockfd < 0) {
            perror("accept");
            exit(1);
        }

        char buffer[1024];
        int n = read(client_sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            perror("read");
            exit(1);
        }

        printf("Received: %s\n", buffer);
        sprintf(buffer, "HTTP/1.0 200 OK\r\n\r\nHello, World!");
        write(client_sockfd, buffer, strlen(buffer));

        close(client_sockfd);
    }

    close(sockfd);
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int server_fd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "Error opening socket\n");
        return 1;
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error on binding\n");
        return 1;
    }

    listen(server_fd, 5);

    while (1) {
        new_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (new_fd < 0) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[1024];
        int nread;
        while ((nread = recv(new_fd, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received: %s\n", buffer);
            send(new_fd, "HTTP/1.1 200 OK\r\n\r\n", 22, 0);
            send(new_fd, "Hello, world!", 13, 0);
        }

        close(new_fd);
    }

    close(server_fd);
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    int server_sockfd;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("Error opening socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return 1;
    }

    char request[1024];
    int request_len = 0;
    int response_len = 0;
    int bytes_read = 0;
    char response[1024];

    while (1) {
        request_len = read(STDIN_FILENO, request, sizeof(request));
        if (request_len == -1) {
            perror("Error reading request");
            return 1;
        }

        bytes_read = send(server_sockfd, request, request_len, 0);
        if (bytes_read == -1) {
            perror("Error sending request to server");
            return 1;
        }

        bytes_read = recv(server_sockfd, response, sizeof(response), 0);
        if (bytes_read == -1) {
            perror("Error receiving response from server");
            return 1;
        }

        response_len = write(STDOUT_FILENO, response, bytes_read);
        if (response_len == -1) {
            perror("Error writing response");
            return 1;
        }
    }

    close(server_sockfd);
    return 0;
}
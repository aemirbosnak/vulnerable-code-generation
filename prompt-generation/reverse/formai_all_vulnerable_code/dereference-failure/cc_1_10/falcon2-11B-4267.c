//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    char *server_port = argv[2];

    struct addrinfo hints, *servinfo, *p;
    int status;
    int server_sock;
    char buffer[1024];
    char request_buffer[1024];
    char response_buffer[1024];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(server_ip, server_port, &hints, &servinfo);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    server_sock = socket(servinfo->ai_family, servinfo->ai_socktype,
                    servinfo->ai_protocol);
    if (server_sock == -1) {
        perror("socket");
        exit(1);
    }

    freeaddrinfo(servinfo);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        memset(request_buffer, 0, sizeof(request_buffer));
        memset(response_buffer, 0, sizeof(response_buffer));

        printf("Waiting for client...\n");
        fflush(stdout);
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            memset(request_buffer, 0, sizeof(request_buffer));
            memset(response_buffer, 0, sizeof(response_buffer));

            printf("Waiting for request...\n");
            fflush(stdout);
            int n = read(client_sock, buffer, sizeof(buffer));
            if (n == -1) {
                perror("read");
                close(client_sock);
                break;
            }

            printf("Request received: %s\n", buffer);
            fflush(stdout);
            int request_length = strlen(buffer);
            memcpy(request_buffer, buffer, request_length);
            request_buffer[request_length] = '\0';

            printf("Request: %s\n", request_buffer);
            fflush(stdout);

            memset(buffer, 0, sizeof(buffer));
            memset(response_buffer, 0, sizeof(response_buffer));

            printf("Waiting for response...\n");
            fflush(stdout);
            int m = write(client_sock, response_buffer, sizeof(response_buffer));
            if (m == -1) {
                perror("write");
                close(client_sock);
                break;
            }

            printf("Response sent: %s\n", response_buffer);
            fflush(stdout);
        }

        close(client_sock);
    }

    close(server_sock);
    return 0;
}
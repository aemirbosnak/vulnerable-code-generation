//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    uint16_t port = atoi(argv[2]);

    struct hostent *server = gethostbyname(hostname);
    if(server == NULL) {
        printf("Error: No such host '%s'\n", hostname);
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&server_address.sin_addr.s_addr, (size_t)server->h_length);
    server_address.sin_port = htons(port);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0) {
        printf("Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    char request[256];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
    send(client_socket, request, strlen(request), 0);

    char response[4096];
    memset(response, 0, sizeof(response));
    recv(client_socket, response, sizeof(response), 0);

    printf("%s", response);

    close(client_socket);
    return EXIT_SUCCESS;
}
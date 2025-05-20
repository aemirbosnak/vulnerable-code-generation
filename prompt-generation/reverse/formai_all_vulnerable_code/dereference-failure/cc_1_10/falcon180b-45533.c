//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./ping <hostname> <port>\n");
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // get host info
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    // fill in sockaddr_in struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send request
    char request[BUFFER_SIZE] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, hostname);
    strcat(request, "\r\nConnection: close\r\n\r\n");
    send(sock, request, strlen(request), 0);

    // receive response
    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    recv(sock, response, BUFFER_SIZE, 0);

    // close socket
    close(sock);

    // print response
    printf("Response:\n%s\n", response);

    return 0;
}
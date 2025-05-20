//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define USERNAME "your_username"
#define PASSWORD "your_password"
#define SERVER "pop.gmail.com"
#define PORT 110

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *server_info;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int i;
    char *user = USERNAME;
    char *pass = PASSWORD;
    char *host = SERVER;
    char *port = PORT;

    // Initialize hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Get server address and port
    if ((i = getaddrinfo(host, port, &hints, &server_info))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(i));
        exit(1);
    }

    // Create socket
    if ((sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol)) == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    if (connect(sock, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    // Authenticate with server
    sprintf(buffer, "USER %s\r\n", user);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("Received: %s\n", buffer);

    sprintf(buffer, "PASS %s\r\n", pass);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("Received: %s\n", buffer);

    // Retrieve email list from server
    sprintf(buffer, "LIST\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("Received: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}
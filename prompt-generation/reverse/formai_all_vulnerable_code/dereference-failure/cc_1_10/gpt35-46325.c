//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_RESPONSE_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: unknown host '%s'.\n", argv[1]);
        exit(1);
    }

    char *ip_str = inet_ntoa(*((struct in_addr*)host->h_addr_list[0]));
    printf("Connecting to %s (%s)...\n", argv[1], ip_str);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: could not create socket.\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    inet_pton(AF_INET, ip_str, &server_address.sin_addr);

    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: could not connect to server %s.\n", ip_str);
        exit(1);
    }

    char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char buffer[MAX_RESPONSE_SIZE];
    sprintf(buffer, request, argv[1]);

    if (write(socket_fd, buffer, strlen(buffer)) < 0) {
        printf("Error: could not write to socket.\n");
        exit(1);
    }

    int bytes_read = 0;
    int total_bytes_read = 0;
    while ((bytes_read = read(socket_fd, buffer + total_bytes_read, MAX_RESPONSE_SIZE - total_bytes_read - 1)) > 0) {
        total_bytes_read += bytes_read;
    }
    if (bytes_read < 0) {
        printf("Error: could not read from socket.\n");
        exit(1);
    }

    buffer[total_bytes_read] = '\0';

    printf("Response: \n%s\n", buffer);

    return 0;
}
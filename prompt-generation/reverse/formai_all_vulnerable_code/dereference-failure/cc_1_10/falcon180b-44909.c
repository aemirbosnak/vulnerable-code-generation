//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void usage(char *program) {
    printf("Usage: %s <hostname>\n", program);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage(argv[0]);
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Invalid hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect to host: %s\n", hostname);
        close(sock);
        exit(EXIT_FAILURE);
    }

    char send_buffer[BUFFER_SIZE];
    memset(send_buffer, 'A', BUFFER_SIZE);
    send(sock, send_buffer, BUFFER_SIZE, 0);

    char recv_buffer[BUFFER_SIZE];
    int recv_len = recv(sock, recv_buffer, BUFFER_SIZE, 0);
    if (recv_len <= 0) {
        printf("Failed to receive data from host: %s\n", hostname);
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Received %d bytes of data from host: %s\n", recv_len, hostname);
    close(sock);
    exit(EXIT_SUCCESS);
}
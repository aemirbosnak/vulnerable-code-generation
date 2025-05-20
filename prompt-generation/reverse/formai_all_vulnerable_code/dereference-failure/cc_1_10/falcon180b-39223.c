//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define WAIT_TIME 5

void print_error(const char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        print_error("gethostbyname");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("socket");
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char send_buffer[BUFFER_SIZE];
    memset(send_buffer, 'A', BUFFER_SIZE);
    int send_len = send(sock, send_buffer, BUFFER_SIZE, 0);
    if (send_len == -1) {
        print_error("send");
    }

    char recv_buffer[BUFFER_SIZE];
    int recv_len = recv(sock, recv_buffer, BUFFER_SIZE, 0);
    if (recv_len == -1) {
        print_error("recv");
    }

    close(sock);

    if (recv_len > 0) {
        printf("Ping successful!\n");
    } else {
        printf("Ping failed.\n");
    }

    return 0;
}
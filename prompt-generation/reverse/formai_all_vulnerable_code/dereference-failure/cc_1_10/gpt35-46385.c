//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_RECV_BUF 4096
#define MAX_SEND_BUF 1024
#define PORT_NUMBER 80

void scan_host(const char* host, int port, int depth);

int main(int argc, char **argv) {
    // check if arguments are provided
    if (argc < 2) {
        printf("Usage: %s <host> [port]\n\n", argv[0]);
        printf("Default port is %d\n", PORT_NUMBER);
        return 0;
    }

    const char* hostname = argv[1];
    int port = PORT_NUMBER;
    if (argc > 2) port = atoi(argv[2]);

    printf("Scanning host %s on port %d\n", hostname, port);
    scan_host(hostname, port, 3);

    return 0;
}

void scan_host(const char* hostname, int port, int depth) {
    // create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0) {
        perror("socket");
        return;
    }

    // setup address struct
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Could not resolve host: %s\n", hostname);
        close(client_socket);
        return;
    }
    struct in_addr** addr_list = (struct in_addr**) host->h_addr_list;

    // try to connect to each IP
    int i = 0;
    while (addr_list[i] != NULL) {
        struct sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);
        server_address.sin_addr = *addr_list[i];

        // connect to server
        if (connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
            // connection failed
            if (depth > 0) {
                printf("%s:%d - Connection failed\n", inet_ntoa(server_address.sin_addr), port);
                scan_host(hostname, port, depth - 1);
            }
            else {
                perror("connect");
            }
        }
        else {
            // connection success
            printf("%s:%d - Connection succeeded\n", inet_ntoa(server_address.sin_addr), port);
            char send_buffer[MAX_SEND_BUF];
            snprintf(send_buffer, MAX_SEND_BUF, "GET / HTTP/1.0\r\n\r\n");
            if (send(client_socket, send_buffer, strlen(send_buffer), 0) < 0) {
                perror("send");
                continue;
            }

            char recv_buffer[MAX_RECV_BUF];
            if (recv(client_socket, recv_buffer, MAX_RECV_BUF, 0) < 0) {
                perror("recv");
                continue;
            }

            printf("Received: %s\n", recv_buffer);
        }

        i++;
    }

    close(client_socket);
}
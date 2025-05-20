//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define PORT_NUMBER "80"
#define MAX_HOST_NAME 256
#define MAX_PORT_NUMBER 6

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    char *host_name;
    char *port_number;
    int port;
    char buffer[1024];

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    host_name = argv[1];
    port_number = PORT_NUMBER;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(host_name);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memcpy(&port, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)host->h_addr, host->h_length) == -1) {
        printf("Error connecting to host\n");
        exit(1);
    }

    printf("Connected to %s:%s\n", host_name, port_number);

    while (TRUE) {
        memset(buffer, 0, sizeof(buffer));
        send(sock, "GET / HTTP/1.1\r\nHost: ", 23, 0);
        send(sock, host_name, strlen(host_name), 0);
        send(sock, "\r\n", 2, 0);

        int bytes_received = 0;
        while ((bytes_received < sizeof(buffer)) && (recv(sock, buffer + bytes_received, sizeof(buffer) - bytes_received, 0) > 0)) {
            bytes_received += strlen(buffer + bytes_received);
        }

        close(sock);
        if (bytes_received > 0) {
            printf("Received response from %s:%s\n", host_name, port_number);
            printf("%s", buffer);
        }
    }

    return 0;
}
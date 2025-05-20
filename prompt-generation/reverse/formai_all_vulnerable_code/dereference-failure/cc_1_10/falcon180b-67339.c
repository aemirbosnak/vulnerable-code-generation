//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port;

    if (end_port <= start_port) {
        end_port = start_port + MAX_PORTS - 1;
    }

    int sock;
    struct sockaddr_in server;
    struct hostent *host;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == 0) {
        perror("socket failed");
        exit(1);
    }

    host = gethostbyname(ip_address);

    if (host == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    memcpy(&server.sin_addr, host->h_addr, host->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    for (int port = start_port; port <= end_port; port++) {
        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "GET / HTTP/1.0\r\n\r\n");

        send(sock, buffer, strlen(buffer), 0);

        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';

            if (strstr(buffer, "200 OK")!= NULL) {
                printf("Port %d is open\n", port);
            } else {
                printf("Port %d is closed\n", port);
            }
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);

    return 0;
}
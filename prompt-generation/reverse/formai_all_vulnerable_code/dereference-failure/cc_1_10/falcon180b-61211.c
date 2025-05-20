//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SOCKET_TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        return 1;
    }

    char *server_address = argv[1];
    int port_number = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    if (inet_pton(AF_INET, server_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid server address\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while (1) {
        int timeout = SOCKET_TIMEOUT;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        bytes_received = recv(sock, buffer, BUFFER_SIZE, MSG_DONTWAIT);
        if (bytes_received <= 0) {
            if (errno!= EAGAIN && errno!= EWOULDBLOCK) {
                printf("Error receiving data: %s\n", strerror(errno));
                close(sock);
                return 1;
            }
            usleep(100000); // 100ms
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);

        if (strstr(buffer, "bye")) {
            printf("Server disconnected\n");
            break;
        }
    }

    close(sock);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./ping <IP address> <port number>\n");
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char send_data[MAX_DATA_SIZE] = "PING";
    send(sockfd, send_data, strlen(send_data), 0);

    char recv_data[MAX_DATA_SIZE];
    int bytes_received = 0;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    while (bytes_received < sizeof(recv_data)) {
        int result = recv(sockfd, recv_data + bytes_received, MAX_DATA_SIZE - bytes_received, 0);
        if (result == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            } else {
                printf("Error receiving data: %s\n", strerror(errno));
                close(sockfd);
                return 1;
            }
        } else if (result == 0) {
            printf("Server not responding\n");
            close(sockfd);
            return 1;
        }
        bytes_received += result;
    }

    close(sockfd);
    printf("PING successful\n");
    return 0;
}
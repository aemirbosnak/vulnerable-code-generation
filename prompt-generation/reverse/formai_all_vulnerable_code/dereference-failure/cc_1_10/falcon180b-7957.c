//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/select.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int maxfd;
    fd_set master_set;
    fd_set read_set;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    FD_ZERO(&master_set);
    FD_ZERO(&read_set);

    FD_SET(sockfd, &master_set);
    maxfd = sockfd;

    while (1) {
        read_set = master_set;
        if (select(maxfd + 1, &read_set, NULL, NULL, NULL) == -1) {
            printf("Error with select\n");
            exit(1);
        }

        if (FD_ISSET(sockfd, &read_set)) {
            bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Connection closed by server\n");
                exit(0);
            } else {
                buffer[bytes_received] = '\0';
                printf("%s", buffer);
            }
        }
    }

    return 0;
}
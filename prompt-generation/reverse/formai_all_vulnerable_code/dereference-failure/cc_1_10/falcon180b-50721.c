//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int is_alive = 0;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (retval == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("No response from server\n");
            close(sockfd);
            return 1;
        }

        buffer[bytes_received] = '\0';

        if (strstr(buffer, "HTTP/1.1 200 OK")!= NULL) {
            is_alive = 1;
        }
    }

    close(sockfd);
    return 0;
}
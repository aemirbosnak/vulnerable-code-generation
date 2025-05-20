//Falcon2-11B DATASET v1.0 Category: Networking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR on binding\n");
        exit(1);
    }

    listen(sockfd, 5);
    int new_socket = accept(sockfd, NULL, NULL);
    if (new_socket < 0) {
        printf("ERROR on accepting\n");
        exit(1);
    }

    char buffer[1024];
    int num_bytes;

    while ((num_bytes = recv(new_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[num_bytes] = '\0';
        printf("Client (%s, %s): %s\n", inet_ntoa(serv_addr.sin_addr),
               htons(serv_addr.sin_port), buffer);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(sockfd);

    return 0;
}
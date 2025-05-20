//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: safe
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PORT 12345

void handle_connection(int sockfd, struct sockaddr_in client_addr) {
    char buf[1024];
    int n;

    while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
        printf("Received %d bytes from %s:%d:\n%s\n", n,
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port),
               buf);
        send(sockfd, "ACK\n", sizeof("ACK\n"), 0);
    }
    close(sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, client_addr_len;
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 3) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_addr_len = sizeof(client_addr);
        if ((sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n",
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port));
        handle_connection(sockfd, client_addr);
    }

    close(sockfd);
    return 0;
}
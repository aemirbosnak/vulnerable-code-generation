//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

struct sockaddr_in server_addr;
char recv_buff[256];

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_addr.s_addr = ((struct in_addr *)host->h_addr_list[0])->s_addr;

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter a message to send: ");
        fgets(recv_buff, sizeof(recv_buff), stdin);
        if (strcmp(recv_buff, "quit\n") == 0) {
            break;
        }

        if (send(sockfd, recv_buff, strlen(recv_buff) + 1, 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        if (recv(sockfd, recv_buff, sizeof(recv_buff), 0) == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s", recv_buff);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}
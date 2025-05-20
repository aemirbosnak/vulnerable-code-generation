//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

// function to handle connection and send data
void send_data(int socket, char *data, int size) {
    if (send(socket, data, size, 0) < 0) {
        perror("send");
        exit(1);
    }
}

// function to receive data and close connection
void recv_data(int socket, char *data, int size) {
    if (recv(socket, data, size, 0) < 0) {
        perror("recv");
        exit(1);
    }
    close(socket);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <target> <port>\n", argv[0]);
        exit(1);
    }

    struct hostent *server;
    struct sockaddr_in addr;
    int sockfd;
    char buffer[1024];

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(1);
    }

    addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&addr.sin_addr.s_addr, server->h_length);
    addr.sin_port = htons(atoi(argv[2]));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        send_data(sockfd, "GET / HTTP/1.1\r\n", 26);
        send_data(sockfd, "\r\n", 2);

        recv_data(sockfd, buffer, 1024);
        if (strstr(buffer, "HTTP/1.1 200 OK")) {
            printf("%s:%s is open\n", inet_ntoa(addr.sin_addr), argv[2]);
        } else {
            printf("%s:%s is closed\n", inet_ntoa(addr.sin_addr), argv[2]);
        }
    }

    close(sockfd);
    return 0;
}
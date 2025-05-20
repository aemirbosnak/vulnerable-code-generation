//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>

#define BUFFER_SIZE 256

void print_error(char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char* argv[]) {
    int sockfd, portno, n;
    int maxfd;
    fd_set readfds;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    char buffer[BUFFER_SIZE];

    if(argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        print_error("socket failed");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        print_error("connect failed");
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    while(1) {
        FD_SET(0, &readfds);
        n = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if((n < 0) && (errno!= EINTR)) {
            print_error("select error");
        }

        if(FD_ISSET(0, &readfds)) {
            bzero(buffer, BUFFER_SIZE);
            n = read(0, buffer, BUFFER_SIZE);
            if(n < 0) {
                print_error("read error");
            } else if(n == 0) {
                break;
            }

            send(sockfd, buffer, strlen(buffer), 0);
        }

        if(FD_ISSET(sockfd, &readfds)) {
            bzero(buffer, BUFFER_SIZE);
            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if(n < 0) {
                print_error("recv error");
            } else if(n == 0) {
                printf("Connection closed by server\n");
                break;
            }

            printf("Received data: %s", buffer);
        }
    }

    close(sockfd);
    return 0;
}
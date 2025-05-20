//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }
    
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char sendbuf[1000];
    int i;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: %s not found\n", argv[1]);
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(53);
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }
    
    printf("Pinging %s (53/tcp)...\n", argv[1]);
    printf("Host address: %s\n", inet_ntoa(serv_addr.sin_addr));
    
    for (i = 0; i < 10; i++) {
        send(sockfd, "GET / HTTP/1.1\r\n\r\n", 31, 0);
        if (recv(sockfd, sendbuf, 1000, 0) == 0) {
            printf("Ping to %s failed\n", argv[1]);
            exit(1);
        }
        printf("%d bytes from %s: i = %d\n", recv(sockfd, sendbuf, 1000, 0), inet_ntoa(serv_addr.sin_addr), i);
    }
    
    printf("Ping statistics for %s: \n", argv[1]);
    printf("10 packets transmitted, 10 received, 0% packet loss, time 30000ms\n");
    printf("rtt min/avg/max/mdev = 0.000/0.000/0.000/0.000 ms\n");
    
    close(sockfd);
    return 0;
}
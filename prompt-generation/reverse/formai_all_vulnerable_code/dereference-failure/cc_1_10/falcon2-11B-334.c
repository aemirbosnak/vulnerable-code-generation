//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    struct hostent* host;
    struct in_addr *addr_list;
    struct sockaddr_in serv_addr;
    struct hostent* result;
    int sockfd, len;
    char sendbuf[100];
    char recvbuf[100];
    char* ip = "8.8.8.8"; // Set the IP to ping

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // Set the port to ping

    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        perror("ERROR converting address");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    bzero(sendbuf, 100);
    sprintf(sendbuf, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", ip);

    len = strlen(sendbuf);
    write(sockfd, sendbuf, len);

    bzero(recvbuf, 100);
    len = read(sockfd, recvbuf, 100);

    printf("Response: %s\n", recvbuf);

    close(sockfd);

    return 0;
}
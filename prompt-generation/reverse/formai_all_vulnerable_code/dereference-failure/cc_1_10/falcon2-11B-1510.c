//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_SIZE 100
#define HOST_LEN 15

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[MAX_SIZE];
    struct hostent *server;
    struct in_addr *ip;
    char *host = argv[1];
    int count = 1;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    server = gethostbyname(host);

    if (server == NULL) {
        printf("ERROR, no such host\n");
        return 1;
    }

    ip = (struct in_addr *)server->h_addr_list[0];
    printf("Pinging %s (%s)...\n", host, inet_ntoa(*ip));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    while (count <= 5) {
        count++;
        send(sockfd, "GET / HTTP/1.0\r\n\r\n", 29, 0);
        recv(sockfd, buffer, MAX_SIZE, 0);
        if (strstr(buffer, "200 OK")) {
            printf("Success! Ping time: %.2fms\n", 1000 / count);
        } else {
            printf("FAIL! Timeout reached.\n");
        }
    }

    return 0;
}
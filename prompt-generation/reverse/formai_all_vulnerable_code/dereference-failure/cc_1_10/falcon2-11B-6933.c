//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

// Function to send ICMP echo request
int send_icmp(int sockfd, const char* dest_ip) {
    struct sockaddr_in servaddr;
    struct hostent *server;

    if ((server = gethostbyname(dest_ip)) == NULL) {
        perror("gethostbyname() failed");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(1);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect() failed");
        return -1;
    }

    if (sendto(sockfd, "Hello, world!", strlen("Hello, world!"), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("sendto() failed");
        return -1;
    }

    if (close(sockfd) < 0) {
        perror("close() failed");
        return -1;
    }

    return 0;
}

int main(int argc, char** argv) {
    int sockfd, len;
    struct sockaddr_in servaddr;
    char* dest_ip = argv[1];

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket() failed");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)&dest_ip, (char *)&servaddr.sin_addr.s_addr, strlen(dest_ip));
    servaddr.sin_port = htons(0);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect() failed");
        return -1;
    }

    if (send_icmp(sockfd, dest_ip) < 0) {
        perror("send_icmp() failed");
        return -1;
    }

    if (close(sockfd) < 0) {
        perror("close() failed");
        return -1;
    }

    return 0;
}
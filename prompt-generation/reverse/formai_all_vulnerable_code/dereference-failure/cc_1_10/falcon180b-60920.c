//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <domain_name>\n", argv[0]);
        return 1;
    }

    char domain_name[BUFFER_SIZE];
    strcpy(domain_name, argv[1]);

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if(getaddrinfo(domain_name, NULL, &hints, &result)!= 0) {
        printf("Error: %s\n", gai_strerror(errno));
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(sockfd == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if(connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    printf("Pinging %s...\n", domain_name);
    char buffer[BUFFER_SIZE];
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            printf("Error: %s\n", strerror(errno));
            close(sockfd);
            return 1;
        }
        printf("%s", buffer);
        usleep(100000);
    }

    close(sockfd);
    return 0;
}
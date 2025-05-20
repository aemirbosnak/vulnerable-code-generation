//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MESSAGE 4096

int main(int argc, char *argv[]) {
    int sockfd, bytes_read;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char message[MAX_MESSAGE];

    if(argc!= 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(110);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while(1) {
        bytes_read = recv(sockfd, message, MAX_MESSAGE, 0);
        if(bytes_read == 0) {
            printf("No more emails\n");
            break;
        }
        printf("%s\n", message);
    }

    close(sockfd);
    return 0;
}
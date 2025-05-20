//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    
    struct hostent *he;
    struct sockaddr_in sin;
    int sockfd, valread;
    
    he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        exit(1);
    }
    
    sin.sin_family = AF_INET;
    bcopy((char *)he->h_addr, (char *)&sin.sin_addr.s_addr, he->h_length);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(1);
    }
    
    if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        fprintf(stderr, "Error: Failed to connect\n");
        exit(1);
    }
    
    char buf[100];
    bzero(buf, sizeof(buf));
    
    valread = read(sockfd, buf, sizeof(buf));
    if (valread < 0) {
        fprintf(stderr, "Error: Failed to read from socket\n");
        exit(1);
    }
    
    if (strcmp(buf, "PING") == 0) {
        printf("PONG\n");
        valread = write(sockfd, "PONG", sizeof("PONG"));
        if (valread < 0) {
            fprintf(stderr, "Error: Failed to write to socket\n");
            exit(1);
        }
        close(sockfd);
        exit(0);
    } else {
        fprintf(stderr, "Error: Unknown response\n");
        exit(1);
    }
}
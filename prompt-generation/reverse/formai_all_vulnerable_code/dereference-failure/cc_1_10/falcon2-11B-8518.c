//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host> [<port>]\n", argv[0]);
        return 1;
    }
    
    char *host = argv[1];
    int port = 80;
    if (argc >= 3) {
        port = atoi(argv[2]);
    }
    
    struct hostent *he;
    struct sockaddr_in serv_addr;
    int sockfd, newsockfd;
    struct sockaddr_in their_addr;
    socklen_t addrlen;
    int status;
    
    if ((he = gethostbyname(host)) == NULL) {
        fprintf(stderr, "Error: Unknown host.\n");
        return 1;
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) he->h_addr, (char *) &serv_addr.sin_addr.s_addr, he->h_length);
    serv_addr.sin_port = htons(port);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket.\n");
        return 1;
    }
    
    status = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (status < 0) {
        fprintf(stderr, "Error connecting.\n");
        return 1;
    }
    
    printf("Connected to %s on port %d.\n", host, ntohs(serv_addr.sin_port));
    
    addrlen = sizeof(their_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &their_addr, &addrlen);
    if (newsockfd < 0) {
        fprintf(stderr, "Error accepting connection.\n");
        return 1;
    }
    
    printf("Accepted connection from %s on port %d.\n", inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port));
    
    status = close(sockfd);
    if (status < 0) {
        fprintf(stderr, "Error closing socket.\n");
        return 1;
    }
    
    status = close(newsockfd);
    if (status < 0) {
        fprintf(stderr, "Error closing socket.\n");
        return 1;
    }
    
    return 0;
}
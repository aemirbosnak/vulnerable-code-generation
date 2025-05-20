//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *hostname = argv[1];
    char port_str[10];

    if(argc!= 2){
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(hostname);
    if(server == NULL){
        fprintf(stderr, "Error: Unknown host\n");
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[2]);
    printf("Scanning port %d on %s...\n", port, hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bzero((char *)&(serv_addr.sin_zero), 8);
    serv_addr.sin_port = htons(port);

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    printf("Port %d is open\n", port);
    n = recv(sockfd, port_str, sizeof(port_str), 0);
    if(n == -1){
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Port %d is closed\n", port);
    }

    close(sockfd);
    return 0;
}
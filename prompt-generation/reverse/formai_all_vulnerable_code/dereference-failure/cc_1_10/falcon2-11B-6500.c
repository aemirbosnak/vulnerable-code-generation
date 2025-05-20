//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }
    
    struct addrinfo *server_addr;
    struct addrinfo hints;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    
    int sockfd;
    if (getaddrinfo(argv[2], argv[1], &hints, &server_addr)!= 0) {
        fprintf(stderr, "Error getting server address\n");
        exit(1);
    }
    
    sockfd = socket(server_addr->ai_family, server_addr->ai_socktype, server_addr->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }
    
    if (connect(sockfd, server_addr->ai_addr, server_addr->ai_addrlen) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }
    
    char buf[1024];
    printf("Enter the URL you want to proxy: ");
    fgets(buf, sizeof buf, stdin);
    
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Error sending request\n");
        exit(1);
    }
    
    if (recv(sockfd, buf, sizeof buf, 0) < 0) {
        fprintf(stderr, "Error receiving response\n");
        exit(1);
    }
    
    printf("Response: %s\n", buf);
    
    exit(0);
}
//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port_number\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int portNumber = atoi(argv[2]);
    char *hostName = argv[1];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }
    // Resolve hostname
    struct hostent *server = gethostbyname(hostName);
    if (server == NULL) {
        perror("Error resolving hostname");
        exit(EXIT_FAILURE);
    }
    // Setup address struct
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portNumber);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }
    
    char buffer[MAX_LEN];
    bzero(buffer, MAX_LEN);
    sprintf(buffer, "Hello SMTP Server");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }
    bzero(buffer, MAX_LEN);
    if (read(sockfd, buffer, MAX_LEN - 1) < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[MAX_LINE];
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port number>\n", argv[0]);
        exit(1);
    }
    
    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }
    
    // Send the email message
    while (fgets(buf, MAX_LINE, stdin)) {
        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            exit(1);
        }
    }
    
    // Close the socket
    close(sockfd);
    
    return 0;
}
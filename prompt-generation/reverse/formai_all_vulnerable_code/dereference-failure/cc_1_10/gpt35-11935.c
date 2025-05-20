//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

// Function to print error messages
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    // Check if user provided necessary command line arguments
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    // Get server information by hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    // Set the server address and port
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    // Create connection
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    // Send GET request
    sprintf(buffer,"GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if (write(sockfd,buffer,strlen(buffer)) < 0) {
        error("ERROR writing to socket");
    }
    // Read response
    memset(buffer, 0, BUFFER_SIZE);
    while ((n = read(sockfd,buffer,BUFFER_SIZE-1)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
    if (n < 0) {
        error("ERROR reading from socket");
    }
    close(sockfd);
    return 0;
}
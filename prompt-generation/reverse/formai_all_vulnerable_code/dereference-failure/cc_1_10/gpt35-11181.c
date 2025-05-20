//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_SIZE 1024

int main(int argc, char const *argv[]) {
	
    int sockfd, portno, n;
    char buffer[MAX_SIZE], message[MAX_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = 8080;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    server = gethostbyname("localhost");
    
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(2);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(3);
    }
    
    while (1) {
        printf("Please enter the message: ");
        bzero(buffer,MAX_SIZE);
        fgets(buffer,MAX_SIZE-1,stdin);
        n = write(sockfd, buffer, strlen(buffer));
        
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(4);
        }
        
        bzero(message, MAX_SIZE);
        n = read(sockfd, message, MAX_SIZE - 1);
        
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(5);
        }
        
        printf("%s\n",message);
    }
    
    close(sockfd);
    return 0;
}
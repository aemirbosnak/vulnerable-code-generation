//FormAI DATASET v1.0 Category: Networking ; Style: Ada Lovelace
// Program Name: The Networking Difference
// Author: Ada Lovelace (not really, it's just her style)

#include <stdio.h>  
#include <stdlib.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <string.h>  

void error(char *msg) {  
    perror(msg); // Prints error messages  
    exit(1);  
}  

int main(int argc, char *argv[]) {  
    int sockfd, newsockfd, portno, client_len;  
    char buffer[256];  
    struct sockaddr_in server_addr, client_addr;  

    if (argc < 2) {  
        printf("Usage: %s <port number>\n", argv[0]);  
        exit(1);  
    }  

    sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    if (sockfd < 0) {  
        error("ERROR opening socket");  
    }  

    bzero((char *) &server_addr, sizeof(server_addr));  
    portno = atoi(argv[1]);  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_addr.s_addr = INADDR_ANY;  
    server_addr.sin_port = htons(portno);  

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {  
        error("ERROR on binding");  
    }  

    listen(sockfd, 5);  
    client_len = sizeof(client_addr);  

    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);  
    if (newsockfd < 0) {  
        error("ERROR on accept");  
    }  

    bzero(buffer, 256);  
    int n = read(newsockfd, buffer, 255);  
    if (n < 0) {  
        error("ERROR reading from socket");  
    }  

    printf("Message from client: %s\n", buffer);  
    n = write(newsockfd, "I see you!", strlen("I see you!"));  
    if (n < 0) {  
        error("ERROR writing to socket");  
    }  

    close(newsockfd);  
    close(sockfd);  
    return 0;  
}
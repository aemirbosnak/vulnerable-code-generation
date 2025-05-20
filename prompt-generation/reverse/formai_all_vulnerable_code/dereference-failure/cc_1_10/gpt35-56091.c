//FormAI DATASET v1.0 Category: Client Server Application ; Style: grateful
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen; 
    char buffer[1024]; 
    struct sockaddr_in serv_addr, cli_addr; 
    int n; 
    
    if (argc < 2) {
        error("ERROR, no port provided\n");
    } 
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0) {
        error("ERROR opening socket\n");
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr)); 
    portno = atoi(argv[1]); 
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno); 
    
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding\n");
    }
    
    listen(sockfd, 5); 
    clilen = sizeof(cli_addr); 
    
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        error("ERROR on accept\n");
    }
    
    printf("Connected with client\n");
    
    while (1) {
        bzero(buffer, 1024); 
        
        n = read(newsockfd, buffer, 1024); 
        if (n < 0) {
            error("ERROR reading from socket\n");
        }
        
        printf("Client: %s\n", buffer); 
        printf("Server: "); 
        bzero(buffer, 1024); 
        fgets(buffer, 1024, stdin); 
        
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket\n");
        }
        
        int i = strncmp("Bye", buffer, 3);
        
        if (i == 0) {
            break;
        }
    }
    
    close(newsockfd); 
    close(sockfd); 
    
    return 0;
}
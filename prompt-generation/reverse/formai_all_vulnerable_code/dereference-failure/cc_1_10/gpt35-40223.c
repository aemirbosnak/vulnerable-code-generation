//FormAI DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
 
void error(char *msg){
    perror(msg);
    exit(1);
}
 
int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: ./server <PORT>\n");
        exit(1);
    }
 
    int sockfd, newsockfd, portno, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("Error opening socket.");
    }
 
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("Binding failed.");
    }
 
    listen(sockfd, 5);
 
    printf("Waiting for client...\n");
 
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len);
 
    if(newsockfd < 0){
        error("Error on accepting.");
    }
 
    printf("Client connected!\n");
 
    while(1){
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
 
        if(n < 0){
            error("Error reading from socket.");
            break;
        }
 
        printf("Client: %s\n", buffer);
 
        bzero(buffer, 256);
        printf("Server: ");
        fgets(buffer, 255, stdin);
 
        n = write(newsockfd, buffer, strlen(buffer));
 
        if(n < 0){
            error("Error writing to socket.");
            break;
        }
    }
 
    close(newsockfd);
    close(sockfd);
    return 0;
}
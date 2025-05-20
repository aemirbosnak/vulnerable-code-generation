//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) 
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char buffer[MAX_BUFF_SIZE];

    if (argc < 2) 
    {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)  
    {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));  
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)  
    {
        perror("Error on binding");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);  
    clilen = sizeof(cli_addr);

    while (1) 
    {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);  
        if (newsockfd < 0)  
        {
            perror("Error on accept");
            continue;
        }

        while (1) 
        {       
            memset(buffer, 0, MAX_BUFF_SIZE);  
            n = read(newsockfd, buffer, MAX_BUFF_SIZE - 1);  
            if (n < 0)  
            {
                perror("Error reading from socket");
                break;
            }
    
            if (n == 0)  
            {
                printf("Client disconnected\n");
                break;
            }

            printf("Received: %s", buffer);  
            memset(buffer, 0, MAX_BUFF_SIZE);  
            sprintf(buffer, "Echo: %s", buffer);  
            n = write(newsockfd, buffer, strlen(buffer));  
            if (n < 0)  
            {
                perror("Error writing to socket");
                break;
            }
        }
        close(newsockfd);  
    }
    close(sockfd);  
    return 0;
}
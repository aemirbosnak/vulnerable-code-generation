//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr,"Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    
    // set up listening socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    struct sockaddr_in serv_addr, cli_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    int portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }
    
    listen(sockfd,5);
    socklen_t clilen = sizeof(cli_addr);
    
    while (1) {
        int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }
        
        // read the request from the client
        char buffer[2049];
        bzero(buffer,2048);
        int n = read(newsockfd,buffer,2048);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        
        // get the hostname and port number of the target server
        char *host = strtok(buffer, " ");
        host = strtok(NULL, " ");
        host = strtok(host, "/");
        char *port_string = strchr(host, ':');
        if (port_string) {
            *port_string = '\0';
            port_string++;
        } else {
            port_string = "80";
        }
        struct hostent *server = gethostbyname(host);
        if (server == NULL) {
            printf("ERROR, no such host\n");
            exit(0);
        }
        int portno = atoi(port_string);
        
        // connect to the target server
        struct sockaddr_in serveraddr;
        bzero((char *) &serveraddr, sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
        serveraddr.sin_port = htons(portno);
        int serverfd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverfd < 0) {
            error("ERROR opening socket");
        }
        if (connect(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
            error("ERROR connecting");
        }
        
        // send the request to the target server
        n = write(serverfd,buffer,strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }
        
        // read the response from the target server
        bzero(buffer,2048);
        n = read(serverfd,buffer,2048);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        
        // send the response to the client
        n = write(newsockfd,buffer,strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }
        
        close(newsockfd);
        close(serverfd);
    }
    close(sockfd);
    return 0;
}
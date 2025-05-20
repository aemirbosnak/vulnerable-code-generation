//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: distributed
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <errno.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
  
int main(int argc, char **argv)  
{  
    int listenfd, connfd;   // variables to keep track of the sockets
    struct sockaddr_in servaddr, clifaddr, cliladdr;   // variables to store IP and port information
  
    listenfd = socket(AF_INET, SOCK_STREAM, 0);   // create a socket for listening
  
    if(listenfd == -1)   // check for socket error
    {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
  
    bzero(&servaddr, sizeof(servaddr));   // zero out the address
    servaddr.sin_family = AF_INET;   // set the family
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   // use any available IP address
    servaddr.sin_port = htons(atoi(argv[1]));   // use given port from command line arguments
  
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)   // bind the socket to the address
    {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
  
    if(listen(listenfd, 5) == -1)   // start listening for connections
    {
        fprintf(stderr, "Error listening to socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
  
    socklen_t len = sizeof(struct sockaddr_in);   // get length of address
    connfd = accept(listenfd, (struct sockaddr*)&clifaddr, &len);   // accept incoming connection
  
    if(connfd == -1)   // check for connection error
    {
        fprintf(stderr, "Error accepting a connection: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
  
    int numbytes;   // variable to store number of bytes received
  
    char buffer[1024];
  
    if((numbytes = recv(connfd, buffer, sizeof(buffer), 0)) == -1)   // receive data from client
    {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
  
    buffer[numbytes] = '\0';
  
    printf("Received: %s\n", buffer);
  
  
    close(connfd);   // close the socket
  
    return 0;
}
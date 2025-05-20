//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <sys/select.h> 
#include <arpa/inet.h> 
#include <netdb.h> 
#include <fcntl.h> 

#define BUFFER_SIZE 16384

void handle_connection(int client_sockfd) {
    char buffer[BUFFER_SIZE];
    int n, server_sockfd;
    struct hostent *server_info;
    struct sockaddr_in server_addr;
    fd_set readfds;
    server_info = gethostbyname("example.com"); // replace with desired domain
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server_info->h_addr_list[0], (char *)&server_addr.sin_addr.s_addr, server_info->h_length);
    server_addr.sin_port = htons(80); // use port 80 for http
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    // now that we have connected to the server, set both client and server sockets to non-blocking mode
    fcntl(client_sockfd, F_SETFL, O_NONBLOCK);
    fcntl(server_sockfd, F_SETFL, O_NONBLOCK);
    // main loop that reads from both sockets
    while(1) {
        // clear the readfds set
        FD_ZERO(&readfds);
        // add both client and server to readfds
        FD_SET(client_sockfd, &readfds);
        FD_SET(server_sockfd, &readfds);
        // wait for activity using select()
        select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
        // check if client has sent something
        if(FD_ISSET(client_sockfd, &readfds)) {
            bzero(buffer, BUFFER_SIZE);
            n = read(client_sockfd, buffer, BUFFER_SIZE);
            if(n <= 0) {
                close(client_sockfd);
                close(server_sockfd);
                exit(0);
            }
            write(server_sockfd, buffer, n);
        }
        // check if server has sent something
        if(FD_ISSET(server_sockfd, &readfds)) {
            bzero(buffer, BUFFER_SIZE);
            n = read(server_sockfd, buffer, BUFFER_SIZE);
            if(n <= 0) {
                close(client_sockfd);
                close(server_sockfd);
                exit(0);
            }
            write(client_sockfd, buffer, n);
        }
    }
}

int main(int argc,char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 12345; // use any port that is not busy
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    while(1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if(newsockfd < 0) {
            perror("Error on accept");
            exit(1);
        }
        handle_connection(newsockfd);
    }
    close(sockfd);
    return 0;
}
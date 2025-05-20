//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 

#define MAX_BUFF_SIZE 1024

void error(const char *msg);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    char buff[MAX_BUFF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;

    if (argc < 2) {
        fprintf(stderr,"usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("Error on binding");

    listen(sockfd, 5);
    cli_len = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len);
        if (newsockfd < 0) 
            error("Error on accept");

        bzero(buff, MAX_BUFF_SIZE);
        n = read(newsockfd, buff, MAX_BUFF_SIZE);
        if (n < 0) 
            error("Error reading from socket");

        printf("Request from client:\n%s\n", buff);

        // parse client request to get destination website and port number
        char *website = strtok(buff, " ");
        if (website != NULL) {
            website = strtok(NULL, " ");
        }
        char *port_string = strstr(website, ":");
        if (port_string == NULL) {
            portno = 80;
        } else {
            portno = atoi(port_string+1);
            *port_string = '\0';
            website[strlen(website)-1] = '\0';
        }

        // get destination server's IP address
        struct hostent *server = gethostbyname(website);
        if (server == NULL) {
            fprintf(stderr, "Error, no such host as %s\n", website);
            exit(EXIT_FAILURE);
        }

        // open connection to destination server
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) 
            error("Error opening socket");

        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(portno);
        if (connect(server_sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
            error("Error connecting to server");

        // forward HTTP request to destination server
        n = write(server_sockfd, buff, sizeof(buff));
        if (n < 0) 
            error("Error writing to socket");

        // print response from destination server
        bzero(buff, MAX_BUFF_SIZE);
        while((n = read(server_sockfd, buff, MAX_BUFF_SIZE-1)) > 0) {
            printf("%s", buff);
            n = write(newsockfd, buff, strlen(buff));
            if (n < 0) 
                error("Error writing to socket");
            bzero(buff, MAX_BUFF_SIZE);
        }
        if (n < 0) 
            error("Error reading from socket");

        // close the connections
        close(server_sockfd);
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
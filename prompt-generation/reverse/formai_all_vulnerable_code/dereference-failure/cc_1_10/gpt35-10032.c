//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, 
               (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) 
            error("ERROR on accept");

        bzero(buffer,BUFSIZE);
        n = read(newsockfd,buffer,BUFSIZE);
        if (n < 0) error("ERROR reading from socket");
        printf("Received request:\n%s\n", buffer);

        char *hostname = strtok(buffer, " ");
        hostname = strtok(NULL, " ");
        printf("Hostname: %s\n", hostname);

        char response[BUFSIZE];
        memset(response, 0, BUFSIZE);
        char *http_version = strstr(buffer, "HTTP/1.");
        if (http_version != NULL) {
            strcat(response, http_version);
            http_version = strstr(response, "\r\n");
            http_version += 2;
            *http_version = '\0';
        }

        struct hostent *server = gethostbyname(hostname);
        if (server == NULL) error("ERROR, no such host");

        int server_port = 80;
        char *port = strstr(hostname, ":");
        if (port != NULL) {
            port++;
            server_port = atoi(port);
            *port = '\0';
        }

        printf("Server name: %s\n", server->h_name);
        printf("Server IP address: %s\n", inet_ntoa(*(struct in_addr*)server->h_addr));

        int serverfd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverfd < 0) 
            error("ERROR opening socket");

        struct sockaddr_in server_addr;
        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, 
              (char *)&server_addr.sin_addr.s_addr,
              server->h_length);
        server_addr.sin_port = htons(server_port);

        if (connect(serverfd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) 
            error("ERROR connecting");

        n = write(serverfd,buffer,strlen(buffer));
        if (n < 0) error("ERROR writing to socket");

        bzero(buffer,BUFSIZE);
        while ((n = read(serverfd,buffer,BUFSIZE)) > 0) {
            n = write(newsockfd,buffer,n);
            if (n < 0) {
                error("ERROR writing to socket");
                break;
            }
            bzero(buffer,BUFSIZE);
        }
        
        close(serverfd);
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
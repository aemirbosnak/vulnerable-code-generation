//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUF_SIZE 100000

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        bzero(buffer, BUF_SIZE);
        n = read(newsockfd,buffer,BUF_SIZE-1);
        if (n < 0) error("ERROR reading from socket");

        //parse request
        char method[256], path[256];
        sscanf(buffer, "%s %s", method, path);

        //check if method is GET
        if (strcmp(method, "GET") == 0) {
            //connect to server
            int server_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (server_fd < 0) error("ERROR opening server socket");

            struct sockaddr_in server_addr;
            bzero((char *) &server_addr, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            bcopy((char *)server->h_addr,
                  (char *)&server_addr.sin_addr.s_addr,
                  server->h_length);
            server_addr.sin_port = htons(80);

            if (connect(server_fd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0)
                error("ERROR connecting to server");

            //send request to server
            n = write(server_fd, buffer, strlen(buffer));
            if (n < 0) error("ERROR writing to socket");

            //receive response from server
            char server_buffer[BUF_SIZE];
            bzero(server_buffer, BUF_SIZE);
            n = read(server_fd, server_buffer, BUF_SIZE-1);
            if (n < 0) error("ERROR reading from server");

            //send response to client
            n = write(newsockfd, server_buffer, strlen(server_buffer));
            if (n < 0) error("ERROR writing to socket");

            close(server_fd);
        } else {
            //unsupported method
            char response[] = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
            write(newsockfd, response, strlen(response));
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}
//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int serverfd, clientfd, portno, clilen;
    char buffer[BUFSIZE], request[BUFSIZE], response[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int n;

    if(argc < 2){
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd < 0){
        error("ERROR opening socket");
    }
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if(bind(serverfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR on binding");
    }
    listen(serverfd, 5);

    while(1){
        clilen = sizeof(cli_addr);
        clientfd = accept(serverfd, (struct sockaddr *) &cli_addr, &clilen);
        if(clientfd < 0){
            error("ERROR on accept");
        }

        memset(buffer, 0, BUFSIZE);
        n = read(clientfd, buffer, BUFSIZE);
        if(n < 0){
            error("ERROR reading from socket");
        }

        sscanf(buffer, "%s", request);
        if(strcmp(request, "GET") == 0){
            // manipulate the GET request here
            printf("\nRequest:\n%s\n", buffer);
        }

        memset(response, 0, BUFSIZE);
        strcat(response, "HTTP/1.0 200 OK\r\n");
        strcat(response, "Content-Type: text/html\r\n");
        strcat(response, "\r\n");
        strcat(response, "<html><body><h1>It works!</h1></body></html>");

        n = write(clientfd, response, strlen(response));
        if(n < 0){
            error("ERROR writing to socket");
        }

        close(clientfd);
    }

    return 0;
}
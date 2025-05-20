//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h> 
#include <unistd.h>

#define MAX_RESPONSE_SIZE 1024
#define MAX_BUFFER_SIZE 4096

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER_SIZE];
    char response[MAX_RESPONSE_SIZE];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    n = read(sockfd,response,MAX_RESPONSE_SIZE);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",response);

    sprintf(buffer, "USER %s\r\n", "username");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    memset(response, 0, sizeof(response));
    n = read(sockfd, response, MAX_RESPONSE_SIZE);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n", response);

    sprintf(buffer, "PASS %s\r\n", "password");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    memset(response, 0, sizeof(response));
    n = read(sockfd, response, MAX_RESPONSE_SIZE);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n", response);

    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    memset(response, 0, sizeof(response));
    n = read(sockfd, response, MAX_RESPONSE_SIZE);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n", response);

    close(sockfd);
    return 0;
}
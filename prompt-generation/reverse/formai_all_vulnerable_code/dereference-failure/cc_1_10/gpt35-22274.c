//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define BUF_SIZE 256

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) 
        error("ERROR opening socket");

    //get server info
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    //fill in server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    //connect to server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    //get user input and send to server
    printf("Please enter a message: ");
    memset(buffer, 0, BUF_SIZE);
    fgets(buffer, BUF_SIZE-1, stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    //read response from server
    memset(buffer, 0, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    //close socket
    close(sockfd);
    return 0;
}
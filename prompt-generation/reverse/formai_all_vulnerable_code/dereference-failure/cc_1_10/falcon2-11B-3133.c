//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, valread, numbytes, i;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    int portno = 80;
    int n;

    if (argc > 1)
        portno = atoi(argv[1]);

    //Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //Set up the address struct
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    //Connect to the server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    //Send HTTP request
    sprintf(buffer,"GET / HTTP/1.0\r\nHost: www.google.com\r\n\r\n");
    write(sockfd,buffer,strlen(buffer));

    //Receive response
    bzero(buffer,1024);
    numbytes = read(sockfd,buffer,1024);
    if (numbytes < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[numbytes] = '\0';

    //Print response
    printf("%s",buffer);

    //Close socket
    close(sockfd);

    return 0;
}
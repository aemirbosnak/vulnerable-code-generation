//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#define MAXBUFFER 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXBUFFER];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("Error opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("Error connecting");
    }

    printf("FTP client connected to server: %s:%d\n", argv[1], portno);

    while(1){
        bzero(buffer, MAXBUFFER);
        printf("\nftp> ");
        fgets(buffer, MAXBUFFER, stdin);

        if (strlen(buffer) > 0 && buffer[strlen(buffer)-1] == '\n'){
            buffer[strlen(buffer)-1] = '\0';
        }

        /* Write command to server */
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            error("Error writing to socket");
        }

        /* Close connection if user enters QUIT */
        if(strncmp(buffer, "QUIT", 4) == 0){
            printf("FTP client closing connection\n");
            close(sockfd);
            return 0;
        }

        /* Read server response */
        bzero(buffer, MAXBUFFER);
        n = read(sockfd, buffer, MAXBUFFER);

        if (n < 0) {
            error("Error reading from socket");
        }

        printf("%s\n",buffer);
    }

    return 0;
}
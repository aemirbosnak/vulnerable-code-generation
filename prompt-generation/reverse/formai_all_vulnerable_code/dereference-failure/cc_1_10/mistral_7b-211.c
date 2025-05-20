//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 21
#define MAXDATASIZE 1024

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXDATASIZE];
    char command[MAXDATASIZE];
    char *username = "anonymous";
    char *password = "mymail@example.com";

    if (argc < 2) {
        fprintf(stderr,"%s requires a hostname or IP address.\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    write(sockfd, "USER ", 5);
    write(sockfd, username, strlen(username)+1);
    write(sockfd, "\r\n", 2);

    write(sockfd, "PASS ", 5);
    write(sockfd, password, strlen(password)+1);
    write(sockfd, "\r\n", 2);

    while (1) {
        bzero(buffer,MAXDATASIZE);
        bzero(command,MAXDATASIZE);
        fgets(command,MAXDATASIZE,stdin);
        n = write(sockfd, command, strlen(command));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        if (strncmp(command,"QUIT",4) == 0) {
            break;
        }

        n = read(sockfd,buffer,MAXDATASIZE);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("%s",buffer);
    }

    close(sockfd);
    return 0;
}
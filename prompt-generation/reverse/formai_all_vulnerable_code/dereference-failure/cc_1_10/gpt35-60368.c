//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("FTP Client Connected\n");
    printf("To quit, type 'QUIT'\n");

    while (1) {
        bzero(buffer,BUFFER_SIZE);
        printf("Enter Command: ");
        fgets(buffer,BUFFER_SIZE-1,stdin);

        if (strlen(buffer) > 0 && buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }

        if (strcmp(buffer, "QUIT") == 0) {
            printf("Connection Closed\n");
            break;
        }
        else {
            n = write(sockfd, buffer, strlen(buffer));
            if (n < 0) {
                error("ERROR writing to socket");
            }

            bzero(buffer,BUFFER_SIZE);
            n = read(sockfd, buffer, BUFFER_SIZE-1);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            printf("%s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}
//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

// Function to handle errors
void handle_error(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        handle_error("ERROR opening socket");
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

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        handle_error("ERROR connecting");
    }

    printf("Connected to server. Type 'quit' to exit.\n");
    printf("-\n");

    while(1){
        bzero(buffer,256);
        printf("FTP> ");
        fgets(buffer,255,stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        if(strcmp(buffer, "quit") == 0){
            printf("Goodbye!\n");
            break;
        }

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            handle_error("ERROR writing to socket");
        }

        bzero(buffer,256);
        n = read(sockfd, buffer, 255);
        if (n < 0) {
            handle_error("ERROR reading from socket");
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}
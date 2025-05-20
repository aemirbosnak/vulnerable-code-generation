//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    char buffer[1024];
    int n;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n",argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET,argv[1],&serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd,5);

    while(1) {
        newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&n);
        if (newsockfd<0) {
            perror("ERROR on accept");
            exit(1);
        }

        bzero(buffer,1024);
        n = read(newsockfd,buffer,1024);
        if (n<0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("Received %d bytes from client: %s\n",n,buffer);

        close(newsockfd);
    }

    return 0;
}
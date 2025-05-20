//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    struct hostent *server;

    if (argc!= 3) {
        fprintf(stderr,"usage: %s hostname port\n",argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"no such host\n");
        exit(2);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(3);
    }

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(4);
    }

    printf("Connected to %s on port %d\n",inet_ntoa(serv_addr.sin_addr),ntohs(serv_addr.sin_port));

    while (1) {
        n = read(sockfd,buffer,sizeof(buffer));
        if (n < 0) {
            perror("read failed");
            exit(5);
        }
        if (n == 0) {
            printf("Server closed the connection\n");
            break;
        }
        printf("Received %d bytes: %s\n",n,buffer);
    }

    close(sockfd);
    return 0;
}
//FormAI DATASET v1.0 Category: Firewall ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, c, n, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];
    char *ip_addr;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR on binding\n");
        exit(1);
    }

    listen(sockfd, 5);

    c = sizeof(struct sockaddr_in);

    while (TRUE) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*)&c);

        if (newsockfd < 0) {
            fprintf(stderr,"ERROR on accept\n");
            exit(1);
        }

        ip_addr = inet_ntoa(cli_addr.sin_addr);

        if (strcmp(ip_addr, "0.0.0.0") == 0) {
            close(newsockfd);
            continue;
        }

        /* Parse Client Message */
        memset(buffer, 0, 256);
        n = read(newsockfd,buffer,255);

        printf("Remote Address: %s\n", ip_addr);
        printf("Message from client: %s\n",buffer);

        /* Check if Message contains Attack Signature */
        if (strstr(buffer, "attack_signature")) {
            printf("Attack Signature detected, closing connection for %s\n", ip_addr);
            close(newsockfd);
            continue;
        }

        /* Message is Good */
        n = write(newsockfd,"OK",2);

        if (n < 0) {
            fprintf(stderr,"ERROR writing to socket\n");
            exit(1);
        }

        close(newsockfd);
     }

     close(sockfd);
     return 0;
}
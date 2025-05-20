//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, n;
    char buffer[256];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    int connections = 0;
    char welcome_msg[512] = "Welcome to the CYBERSPACE SERVER.\n\n# of Active Connections: ";
    char num_con[1];

    while(1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) 
            error("ERROR on accept");

        connections++;
        memset(num_con, '\0', sizeof(num_con));
        sprintf(num_con, "%d", connections);
        strcat(welcome_msg, num_con);

        n = write(newsockfd, welcome_msg, strlen(welcome_msg));
        if (n < 0) error("ERROR writing to socket");

        memset(buffer, '\0', sizeof(buffer));
        n = read(newsockfd,buffer,sizeof(buffer));
        if (n < 0) error("ERROR reading from socket");

        printf("[%d] Message from client: %s\n", connections, buffer);

        n = write(newsockfd,"I got your message",18);
        if (n < 0) error("ERROR writing to socket");

        close(newsockfd);
        memset(welcome_msg, '\0', sizeof(welcome_msg));
        strcpy(welcome_msg, "Welcome to the CYBERSPACE SERVER.\n\n# of Active Connections: ");
    }

    close(sockfd);

    return 0; 

}
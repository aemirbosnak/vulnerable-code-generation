//FormAI DATASET v1.0 Category: Browser Plugin ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       printf("Usage: %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        printf("ERROR opening socket\n");
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(0);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        printf("ERROR connecting\n");

    sprintf(buffer,"GET / HTTP/1.1\r\n");
    sprintf(buffer,"%shost: %s\r\n",buffer,argv[1]);
    sprintf(buffer,"%sConnection: close\r\n\r\n",buffer);

    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
         printf("ERROR writing to socket\n");

    bzero(buffer,256);

    while (read(sockfd,buffer,255) > 0){
        printf("%s",buffer);
        bzero(buffer,256);
    }
    printf("\n");
    close(sockfd);
    return 0;
}
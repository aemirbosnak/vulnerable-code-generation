//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname;
    int portno;
    char *path;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    
    if (argc < 4) {
        fprintf(stderr,"usage %s hostname port path\n", argv[0]);
        exit(0);
    }
    
    hostname = argv[1];
    portno = atoi(argv[2]);
    path = argv[3];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR, connection failed\n");
        exit(0);
    }
    
    sprintf(buffer, "GET %s HTTP/1.0\r\n\r\n", path);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR, writing to socket failed\n");
        exit(0);
    }
    
    memset(buffer, 0, BUFFER_SIZE);
    while ((n = read(sockfd, buffer, BUFFER_SIZE-1)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
    printf("\n");
    
    close(sockfd);
    return 0;
}
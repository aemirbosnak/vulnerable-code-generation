//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    
    portno = atoi(argv[2]);
    
    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    
    /* Set server address */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);
    
    /* Connect to server */
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    
    printf("Connected to server.\n");
    
    while (1) {
        printf("ftp> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        /* Send command to server */
        n = write(sockfd, buffer, strlen(buffer));
        
        if (n <= 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        
        memset(buffer, 0, BUFFER_SIZE);
        
        /* Receive response from server */
        n = read(sockfd, buffer, BUFFER_SIZE);
        
        if (n <= 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        
        printf("%s\n", buffer);
    }
    
    close(sockfd);
    
    return 0;
}
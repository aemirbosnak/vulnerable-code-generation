//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }
    
    struct sockaddr_in servaddr, cliaddr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9000);
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Error: %s is an invalid IP address\n", argv[1]);
        exit(1);
    }
    
    if(bind(sockfd, (const struct sockaddr *)&cliaddr, sizeof(cliaddr)) < 0) {
        printf("Bind error: %s\n", strerror(errno));
        close(sockfd);
        exit(1);
    }
    
    char sendline[MAXLINE];
    char recvline[MAXLINE];
    int len, n;
    socklen_t servlen = sizeof(servaddr);
    
    printf("Enter network topology command: ");
    fgets(sendline, MAXLINE, stdin);
    
    sendto(sockfd, (const char *)sendline, strlen(sendline), 
        MSG_CONFIRM, (const struct sockaddr *)&servaddr, servlen);
    printf("Command sent.\n");
    
    n = recvfrom(sockfd, (char *)recvline, MAXLINE, 
        MSG_WAITALL, (struct sockaddr *)&servaddr, &servlen);
    recvline[n] = '\0';
    printf("Topology map received:\n%s", recvline);
    
    close(sockfd);
    return 0;
}
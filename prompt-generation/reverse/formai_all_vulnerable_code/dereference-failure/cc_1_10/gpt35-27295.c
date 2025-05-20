//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <string.h>  
#include <netdb.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  

#define BUF_SIZE 4096  
#define DEFAULT_PORT "993"

int main(int argc, char **argv)  
{  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s hostname username\n", argv[0]);  
        exit(1);  
    }  

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    struct hostent *he;  
    struct sockaddr_in serveraddr;  

    if ((he = gethostbyname(argv[1])) == NULL) {  
        fprintf(stderr, "Cannot resolve hostname %s\n", argv[1]);  
        exit(1);  
    }  

    bzero(&serveraddr, sizeof(serveraddr));  
    serveraddr.sin_family = AF_INET;  
    serveraddr.sin_port = htons(atoi(DEFAULT_PORT));  
    serveraddr.sin_addr = *((struct in_addr *)he->h_addr);  

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {  
        fprintf(stderr, "Cannot connect to %s\n", argv[1]);  
        exit(1);  
    }  

    char buf[BUF_SIZE];  
    ssize_t nread;  

    nread = read(sockfd, buf, BUF_SIZE);  
    if (nread <= 0) {  
        fprintf(stderr, "Error reading from server\n");  
        exit(1);  
    }  

    buf[nread] = '\0';  
    printf("%s", buf);  

    char username[128];  
    sprintf(username, "tag1 LOGIN %s {10}\r\n", argv[2]);  
    write(sockfd, username, strlen(username));  
    sleep(1);  
    write(sockfd, "password\r\n", strlen("password\r\n"));  
    nread = read(sockfd, buf, BUF_SIZE);  
    buf[nread] = '\0';  
    printf("%s", buf);  

    char logout[128] = "tag2 LOGOUT\r\n";  
    write(sockfd, logout, strlen(logout));  
    nread = read(sockfd, buf, BUF_SIZE);  
    buf[nread] = '\0';  
    printf("%s", buf);  

    close(sockfd);  
    return 0;  
}
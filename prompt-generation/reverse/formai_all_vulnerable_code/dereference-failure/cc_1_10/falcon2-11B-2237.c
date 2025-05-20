//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <website_url>\n", argv[0]);
        return 1;
    }
    
    char url[100];
    strcpy(url, argv[1]);
    
    int sockfd;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    host = gethostbyname(url);
    if (host == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) host->h_addr, (char *) &serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = htons(80);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    
    char buffer[1024];
    bzero(buffer, 1024);
    
    while (1) {
        int n = read(sockfd, buffer, 1024);
        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }
        
        if (n == 0) {
            printf("Website is down\n");
            exit(EXIT_FAILURE);
        }
        
        printf("Website is up\n");
        printf("Received: %s\n", buffer);
        fflush(stdout);
        sleep(5);
    }
    
    close(sockfd);
    return 0;
}
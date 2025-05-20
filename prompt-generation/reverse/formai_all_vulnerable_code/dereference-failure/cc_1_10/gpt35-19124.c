//FormAI DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#define TIMEOUT_SEC 2 /* timeout for connection attempts in seconds*/
#define MAX_PORT 65535 /* maximum port number to check*/

int main(int argc, char **argv) {

    if (argc != 2) { /* input validation*/
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    
    char *hostname = argv[1];
    char host_ip[32];
    struct hostent *host;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    
    printf("Scanning ports on %s...\n\n", hostname);
    
    if ((host = gethostbyname(hostname)) == NULL) { /* error checking*/
        herror("gethostbyname() failed");
        exit(1);
    }

    strcpy(host_ip, inet_ntoa(*(struct in_addr*) host->h_addr_list[0]));
    
    int sockfd;
    struct sockaddr_in target;
    fd_set fdset;
    int i, port, result;
    for(port = 1; port <= MAX_PORT; port++) {
        
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        
        if(sockfd < 0) {
            perror("socket() failed");
            exit(1);
        }
        
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(host_ip);
        
        FD_ZERO(&fdset);
        FD_SET(sockfd, &fdset);
        
        /* set socket timeout */
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
        
        /* connect to the target port */
        result = connect(sockfd, (struct sockaddr*) &target, sizeof(target));
        
        /* check for success or failure*/
        if(result == 0) {
            printf("Port %d open!\n", port);
        } else {
            /* connection failed, port is closed*/
        }
        
        close(sockfd);
    }

    return 0;
}
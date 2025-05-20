//FormAI DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_MIN 1
#define PORT_MAX 65535

bool is_valid_port(int port) {
    return port >= PORT_MIN && port <= PORT_MAX;
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Please provide a valid IP address\n");
        return 1;
    }
    
    char* ip_address = argv[1];
    
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    
    for (portno = PORT_MIN; portno <= PORT_MAX; portno++) {
        
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Could not create socket\n");
            return 1;
        }
        
        server = gethostbyname(ip_address);
        if (server == NULL) {
            printf("Could not resolve hostname\n");
            return 1;
        }
        
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(portno);
        
        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            printf("Port %d is closed\n", portno);
        } else {
            printf("Port %d is open!\n", portno);
            close(sockfd);
        }
        
    }
    
    return 0;
}
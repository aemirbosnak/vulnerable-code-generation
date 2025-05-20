//FormAI DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define MAX_PORTS 65535 //max port number to scan
#define TIMEOUT 3 //timeout for connecting to port in seconds

int main(int argc, char *argv[]) {
    
    //check if valid arguments were given
    if(argc != 2) {
        printf("Invalid syntax. Usage: ./portscanner <IP Address>\n");
        exit(1);
    }

    char *ip_addr = argv[1];

    printf("Scanning IP Address: %s\n", ip_addr);

    int sockfd, port;
    struct sockaddr_in target_addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    char banner[1024];

    //create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    //set target ip address and port type
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(ip_addr);

    //check each port for open connection
    for(port = 1; port <= MAX_PORTS; port++) {
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
      
        //set port number
        target_addr.sin_port = htons(port);

        if(connect(sockfd, (struct sockaddr *)&target_addr, addr_size) == 0) {
            //open port found
            printf("Port %d: Open\n", port);
            //try to get banner if available
            if(getsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, banner, &addr_size) == 0) {
                printf("    Service: %s\n", banner);
            }
            close(sockfd);
            continue;
        }
        close(sockfd);
    }
    
    printf("Scan complete.\n");
    return 0;
}
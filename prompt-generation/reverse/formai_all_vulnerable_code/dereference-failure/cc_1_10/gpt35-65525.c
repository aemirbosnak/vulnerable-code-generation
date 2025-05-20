//FormAI DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

#define TIMEOUT_SEC 1

/* function to display help menu */
void display_help() {
    printf("Usage: portscanner <IP ADDRESS> <FROM PORT> <TO PORT>\n");
    printf("\n");
    printf("Example: ./portscanner 192.168.1.1 1 65535\n");
    printf("\n");
}

/* function to check if a given port is open or not */
int check_port_open(char* ip_address, int port) {
    struct sockaddr_in sa;
    int sockfd, ret;

    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // set the timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

    // setup the socket address structure
    bzero(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &sa.sin_addr);

    // attempt to connect to the port
    ret = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    if(ret < 0) {
        close(sockfd);
        return 0;
    }

    // port is open
    close(sockfd);
    return 1;
}

/* main function */
int main(int argc, char **argv) {

    // check if there are enough arguments
    if(argc < 4) {
        printf("Invalid Arguments\n");
        display_help();
        return 0;
    }

    char* ip_address = argv[1];
    int from_port = atoi(argv[2]);
    int to_port = atoi(argv[3]);
    int i;

    // loop through all the given ports
    for(i=from_port; i<=to_port; i++) {
        int is_open = check_port_open(ip_address, i);
        if(is_open) {
            printf("Port %d is open\n", i);
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[]){
    int sockfd;
    struct sockaddr_in serv_addr;
    char *ip;
    int port;

    if(argc!= 3){
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    printf("Scanning IP Address: %s\n", ip);
    printf("Scanning Port Range: %d\n", port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1){
        printf("Error: Could not create socket!\n");
        exit(1);
    }

    while(port <= 65535){
        memset(&serv_addr, 0, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr.s_addr = inet_addr(ip);

        if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0){
            printf("Port %d is open!\n", port);
        } else {
            printf("Port %d is closed!\n", port);
        }

        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if(sockfd == -1){
            printf("Error: Could not create socket!\n");
            exit(1);
        }

        port++;
    }

    return 0;
}
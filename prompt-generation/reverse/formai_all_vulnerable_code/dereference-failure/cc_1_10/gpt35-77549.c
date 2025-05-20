//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>

#define PORT 80

int main(void){
    int sockfd, ret, i;
    struct sockaddr_in servaddr, localaddr;
    char localip[INET_ADDRSTRLEN], website[100];

    printf("Enter website to scan: ");
    scanf("%s", website);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("\nERROR: Could not create socket. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else{
        printf("\nWireless Network Scanner started.\n\n");
    }

    memset(&servaddr, 0, sizeof(servaddr)); // zero out the sockaddr_in struct
    servaddr.sin_family = AF_INET; // set address family
    servaddr.sin_port = htons(PORT); // set the port
    ret = inet_pton(AF_INET, website, &servaddr.sin_addr); // convert IP address to network byte order
    if(ret == 0){
        printf("\nERROR: Invalid website address. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else if(ret < 0){
        printf("\nERROR: Could not convert website address to network byte order. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // get IP address of the local machine
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    getifaddrs(&ifap);
    for(ifa = ifap; ifa; ifa = ifa->ifa_next){
        if(ifa->ifa_addr->sa_family == AF_INET){
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            if(strcmp(ifa->ifa_name, "wlp2s0") == 0){ // change this to the name of your wireless interface
                inet_ntop(AF_INET, &sa->sin_addr, localip, INET_ADDRSTRLEN);
            }
        }
    }
    freeifaddrs(ifap);

    printf("Scanning wireless network '%s' with IP address '%s'...\n", website, localip);

    // scan the network
    for(i = 1; i < 256; i++){
        localaddr.sin_family = AF_INET;
        localaddr.sin_port = htons(PORT);
        char addr[15];
        sprintf(addr, "%s.%d", website, i);
        inet_pton(AF_INET, addr, &localaddr.sin_addr);

        ret = connect(sockfd, (struct sockaddr *)&localaddr, sizeof(localaddr));
        if(ret == 0){
            printf("--> %s\n", addr);
        }
    }

    close(sockfd);

    printf("\nWireless Network Scanner completed.\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#define MAX_INTERFACES 16

int main(){
    int sockfd;
    struct ifconf ifc;
    struct ifreq *ifr;
    int numInterfaces;
    char ip[INET_ADDRSTRLEN];

    /* Create a socket to test available network interfaces */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        perror("Error creating socket");
        return -1;
    }

    /* Get the list of available network interfaces */
    ifc.ifc_buf = NULL;
    ifc.ifc_len = 0;
    if(ioctl(sockfd, SIOCGIFCONF, &ifc) < 0){
        perror("Error getting interface configuration");
        return -1;
    }

    /* Allocate memory for all the interfaces */
    ifr = (struct ifreq*)malloc(ifc.ifc_len);
    if(!ifr){
        perror("Error allocating memory for interfaces");
        return -1;
    }

    /* Fill the memory with interface information */
    ifc.ifc_buf = (char*)ifr;
    if(ioctl(sockfd, SIOCGIFCONF, &ifc) < 0){
        perror("Error filling memory with interface information");
        return -1;
    }

    /* Get the number of interfaces */
    numInterfaces = ifc.ifc_len/sizeof(struct ifreq);

    /* Iterate through all the available interfaces */
    for(int i=0; i<numInterfaces; i++){
        /* Get the IP address of the interface */
        if(ioctl(sockfd, SIOCGIFADDR, &ifr[i]) < 0){
            perror("Error getting IP address");
        } else {
            /* Print out the interface name and IP address */
            printf("Interface: %s\tIP Address: %s\n",
                   ifr[i].ifr_name,
                   inet_ntop(AF_INET,
                             &((struct sockaddr_in*)&ifr[i].ifr_addr)->sin_addr,
                             ip, sizeof(ip)));
        }
    }

    free(ifr);
    close(sockfd);
    return 0;
}
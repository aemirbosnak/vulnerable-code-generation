//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char **argv){

    if(argc != 2){
        fprintf(stderr, "Usage: ./topo <ip_address>\n");
        return 1;
    }

    char *ip_address = argv[1]; // Store the IP address entered by the user
    struct hostent *host = gethostbyname(ip_address);

    if(!host){
        fprintf(stderr, "Could not get information for %s\n", ip_address);
        return 2;
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        fprintf(stderr, "Socket creation failed!\n");
        return 3;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(1234); // Topology Mapper will listen to this port.
    dest_addr.sin_addr = *((struct in_addr*)host->h_addr);

    // Bind the socket to the above address
    if(bind(sockfd, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) < 0){
        fprintf(stderr, "Socket binding failed!\n");
        return 4;
    }

    printf("Topology Mapper is waiting for data on port %d\n", ntohs(dest_addr.sin_port));

    while(1){
        struct sockaddr_in sender_addr;
        socklen_t sender_addr_len = sizeof(sender_addr);
        char buffer[1024];
        memset(&buffer, 0, sizeof(buffer));

        // Wait for data to be received
        int recv_len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&sender_addr, &sender_addr_len);
        if(recv_len > 0){
            printf("Received data from %s:%d\n", inet_ntoa(sender_addr.sin_addr), ntohs(sender_addr.sin_port));
            printf("Data: %s\n", buffer);

            struct hostent *remote_host = gethostbyaddr((char*)&sender_addr.sin_addr, sizeof(sender_addr.sin_addr), AF_INET);
            if(remote_host){
                printf("Host name: %s\n", remote_host->h_name);
            }

            printf("\n");
        }
    }

    close(sockfd);
    return 0;
}
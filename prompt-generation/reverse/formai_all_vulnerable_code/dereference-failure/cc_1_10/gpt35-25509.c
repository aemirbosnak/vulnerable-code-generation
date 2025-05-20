//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_PACKET_SIZE 4096
#define IP_FOUND "IP_FOUND"
#define IP_FOUND_ACK "IP_FOUND_ACK"

int main(int argc, char *argv[]) {
    int sock;
    int broadcast = 1;
    struct sockaddr_in broadcast_addr; 
    struct sockaddr_in incoming_addr;
    socklen_t incoming_len;
    int nbytes, yes = 1;
    char buffer[MAX_PACKET_SIZE];

    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast) == -1) {
        printf("Error setting socket option.\n");
        exit(1);
    }

    memset(&broadcast_addr, 0, sizeof broadcast_addr);
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(8080);
    broadcast_addr.sin_addr.s_addr = inet_addr("192.168.1.255");

    if (bind(sock, (struct sockaddr *)&broadcast_addr, sizeof(struct sockaddr)) == -1) {
        printf("Error binding to socket.\n");
        exit(1);
    }

    incoming_len = sizeof incoming_addr;

    while (1) {
        nbytes = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&incoming_addr, &incoming_len);

        if (nbytes == -1) {
            printf("Error receiving data.\n");
            exit(1);
        }

        int numbytes;
        char host_name[128];
        struct hostent *host_entry;
        struct ifreq ifr;
        
        memset(&ifr, 0, sizeof(ifr));
        strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ - 1);
        
        if (ioctl(sock, SIOCGIFHWADDR, &ifr) < 0) {
            printf("Error getting MAC address.\n");
            exit(1);
        }
        
        memcpy(&host_entry->h_addr_list[0], ifr.ifr_hwaddr.sa_data, ETH_ALEN);
        host_entry = gethostbyname(host_name);

        if (strncmp(buffer, IP_FOUND, strlen(IP_FOUND)) == 0) {
            printf("Received broadcast IP found message from %s\n",inet_ntoa(incoming_addr.sin_addr));
            printf("Sending IP found ACK message.\n");

            numbytes = sprintf(buffer, IP_FOUND_ACK);
            nbytes = sendto(sock, buffer, numbytes, 0, (struct sockaddr *)&incoming_addr, sizeof(struct sockaddr));

            if (nbytes == -1) {
                printf("Error sending data.\n");
                exit(1);
            }
        }
        else if (strncmp(buffer, IP_FOUND_ACK, strlen(IP_FOUND_ACK)) == 0) {
            printf("Received IP found ACK message from %s\n",inet_ntoa(incoming_addr.sin_addr));
        }
    }

    close(sock);

    return 0;
}
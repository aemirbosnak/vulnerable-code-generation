//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

#define SCAN_DELAY_MS 1000
#define MAX_IP_ADDR_LENGTH 16
#define MAX_PORT_LENGTH 6
#define MAX_BUFF_LENGTH 4096

int main(int argc, char *argv[]) {
    int sockfd, port, rc, on = 1;
    char ip_addr[MAX_IP_ADDR_LENGTH], port_str[MAX_PORT_LENGTH];
    char buff[MAX_BUFF_LENGTH];
    struct sockaddr_in serv_addr;

    if (argc != 2) {
        printf("Usage: %s <IP-addr>\n", argv[0]);
        return 1;
    }
    
    strncpy(ip_addr, argv[1], MAX_IP_ADDR_LENGTH);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);

    printf("Starting scan for %s...\n", ip_addr);

    for (port = 0; port <= 65535; port++) {
        snprintf(port_str, MAX_PORT_LENGTH, "%d", port);

        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);      
        if (sockfd > 0) {
            setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
            setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
            
            serv_addr.sin_port = htons(port);
            rc = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
            
            if (rc == 0) {
                snprintf(buff, MAX_BUFF_LENGTH, "Port %d is open.", port);
                printf("%-30s\r", buff);
                fflush(stdout);
            }

            close(sockfd);
        }
        
        usleep(SCAN_DELAY_MS);
    }

    printf("\nDone.\n");

    return 0;
}
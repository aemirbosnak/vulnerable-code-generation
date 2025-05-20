//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

void print_network_info(char *ip_address, int port) {
    struct hostent *host;
    struct sockaddr_in address;
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    bzero((char *) &address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    
    host = gethostbyname(ip_address);
    if (host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    
    bcopy((char *) host->h_addr, (char *) &address.sin_addr.s_addr, host->h_length);
    
    if (connect(sockfd, &address, sizeof(address)) < 0) {
        printf("Host %s is down\n", ip_address);
    } else {
        printf("Host %s is up\n", ip_address);
    }
    
    close(sockfd);
}

int main() {
    int port = 80;
    char *ip_address;
    char *ip_range_start;
    char *ip_range_end;
    int i, j, k;
    
    printf("Enter the IP address range to scan in format xxx.xxx.xxx (start) xxx.xxx.xxx (end)\n");
    scanf("%s %s", ip_range_start, ip_range_end);
    
    for (i = 0; i < 255; i++) {
        for(j = 0; j < 255; j++) {
            for(k = 0; k < 255; k++) {
                asprintf(&ip_address, "%s.%d.%d.%d", ip_range_start, i, j, k);
                print_network_info(ip_address, port);
                free(ip_address);
            }
        }
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>   
#include <sys/socket.h>   
#include <arpa/inet.h> 
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>

void scan_port(char *host, int start_port, int end_port) {
    struct hostent *he;
    struct in_addr **addr_list;
    int sockfd, i, port_number;
    struct sockaddr_in sa;

    if ((he = gethostbyname(host)) == NULL) {
        printf("Error: Cannot resolve hostname %s\n", host);
        return;
    }
    addr_list = (struct in_addr **) he->h_addr_list;

    for (i = 0; addr_list[i] != NULL; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("Could not create socket\n");
            return;
        }

        sa.sin_addr = *(addr_list[i]);
        sa.sin_family = AF_INET;

        for (port_number = start_port; port_number <= end_port; port_number++) {
            sa.sin_port= htons(port_number);

            if (connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
                printf("Port %d is closed\n", port_number);
            }
            else {
                printf("Port %d is open\n", port_number);
            }
        }

        close(sockfd);
    }
}

int main(int argc , char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s host start_port end_port\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port <= 0 || end_port <= 0 || start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_port(host, start_port, end_port);

    return 0;
}
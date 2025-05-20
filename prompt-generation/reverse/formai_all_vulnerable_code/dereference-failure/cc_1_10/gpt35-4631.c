//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX 1024
#define PORT 8080

struct Edge {
    char from[INET_ADDRSTRLEN];
    char to[INET_ADDRSTRLEN];   
};

int main(int argc, char *argv[]) {
    char hostname[NI_MAXHOST];
    struct hostent *he;
    struct in_addr **addr_list;
    struct sockaddr_in server_addr;
    int sockfd, num_edges = 0;
    char buffer[MAX];

    if(argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    strncpy(hostname, argv[1], NI_MAXHOST);

    if ((he = gethostbyname(hostname)) == NULL) {  
        herror("gethostbyname");
        exit(1);
    }

    addr_list = (struct in_addr **)he->h_addr_list;

    for(int i = 0; addr_list[i] != NULL; i++) {
        server_addr.sin_addr = *addr_list[i];
        char *ip = inet_ntoa(server_addr.sin_addr);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);
        if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            continue;
        }
        struct Edge edge;
        strcpy(edge.from, ip);

        for(int j = 0; addr_list[j] != NULL; j++) {
            if(i != j) {
                server_addr.sin_addr = *addr_list[j];
                char *ip2 = inet_ntoa(server_addr.sin_addr);
                if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                    perror("connect");
                    continue;
                }
                strcpy(edge.to, ip2);
                printf("%s --> %s\n", edge.from, edge.to);
                num_edges++;
            }
        }
        close(sockfd);
    }
    printf("\nTotal edges: %d\n", num_edges);
    return 0;
}
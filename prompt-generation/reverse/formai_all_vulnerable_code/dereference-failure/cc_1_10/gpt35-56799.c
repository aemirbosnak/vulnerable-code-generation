//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024

struct host {
    char name[64];
    char ip[16];
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct host hosts[256];
    memset(hosts, 0, sizeof(hosts));

    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    int i = 0;
    while (he->h_addr_list[i] != NULL) {
        strcpy(hosts[i].ip, inet_ntoa(*((struct in_addr*) he->h_addr_list[i])));
        strcpy(hosts[i].name, argv[1]);
        i++;
    }

    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(80);

    char buffer[MAX_BUFFER_SIZE];
    int sockfd;
    for (int j = 0; j < i; j++) {   
        saddr.sin_addr.s_addr = inet_addr(hosts[j].ip);

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, (struct sockaddr*) &saddr, sizeof(saddr)) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hosts[j].name);
        write(sockfd, buffer, strlen(buffer));

        if (read(sockfd, buffer, MAX_BUFFER_SIZE) > 0) {
            printf("%s\n", buffer);
        }

        close(sockfd);
    }

    return 0;
}
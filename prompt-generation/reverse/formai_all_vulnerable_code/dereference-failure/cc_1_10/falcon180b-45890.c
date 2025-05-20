//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PORTS 65535

void scan_ports(int sockfd, struct sockaddr_in *serv_addr) {
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    for (int i = 1; i <= MAX_PORTS; i++) {
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("%d - Open\n", i);
        } else {
            printf("%d - Closed\n", i);
        }
    }
}

int main() {
    char hostname[1024];
    printf("Enter hostname: ");
    scanf("%s", hostname);

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: No such host\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Socket creation failed\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(0);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)server->h_addr), &serv_addr.sin_addr);

    scan_ports(sockfd, &serv_addr);

    close(sockfd);
    return 0;
}
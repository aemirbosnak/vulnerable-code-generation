//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <target_host> [start_port end_port]\n", argv[0]);
        return 1;
    }

    char host[256];
    sprintf(host, "%s", argv[1]);
    struct hostent *he;
    if ((he = gethostbyname(host)) == NULL) {
        fprintf(stderr, "Error: no such host\n");
        return 1;
    }

    struct in_addr *addr;
    addr = (struct in_addr *)he->h_addr_list[0];

    int sockfd, port;
    socklen_t len = sizeof(struct sockaddr_in);
    for (port = atoi(argv[2]); port <= atoi(argv[3]); port++) {
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr.s_addr = inet_addr(addr->s_addr);

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error opening socket");
            continue;
        }

        if (connect(sockfd, (struct sockaddr *)&serv_addr, len) < 0) {
            perror("Error connecting");
            close(sockfd);
            continue;
        }

        printf("%d is open\n", port);

        close(sockfd);
    }

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BUFF 1000

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target_ip> <count>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in target_addr;
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = *(long int *)host->h_addr;
    target_addr.sin_port = htons(80);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    int count = atoi(argv[2]);
    for (int i = 0; i < count; i++) {
        send(sockfd, "GET / HTTP/1.0\r\n\r\n", 30, 0);
        char buff[MAX_BUFF];
        int bytes_read = recv(sockfd, buff, MAX_BUFF, 0);
        if (bytes_read <= 0) {
            fprintf(stderr, "Failed to receive data\n");
            exit(1);
        }
        printf("%s\n", buff);
        close(sockfd);
        sleep(1);
    }

    return 0;
}
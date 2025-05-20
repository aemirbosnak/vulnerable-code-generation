//FormAI DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORTS 65536
#define MAX_BUF 128

int main(int argc, char** argv){

    if (argc < 2) {
        printf("Usage: %s IP_ADDRESS [optional: starting port] [optional: ending port]\n", argv[0]);
        return 1;
    }

    struct sockaddr_in target_addr;
    int start_port = 1;
    int end_port = MAX_PORTS;
    int sockfd, result;
    char buffer[MAX_BUF];

    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // specify starting and ending port if provided
    if (argc > 2) {
        start_port = atoi(argv[2]);
        if (argc == 4) {
            end_port = atoi(argv[3]);
        }
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        perror("Socket error");
        return 1;
    }

    for (int i = start_port; i <= end_port; i++) {

        target_addr.sin_port = htons(i);
        // connect to the target address and port
        if (connect(sockfd, (struct sockaddr*) &target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d: OPEN\n", i);
        }

        // reset socket connection before attempting next port
        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1){
            perror("Socket error");
            return 1;
        }
    }
    printf("Finished scanning.\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, start_port, end_port, i, j, res;
    struct sockaddr_in target;
    char *ip_address = argv[1];

    //input validation
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port > end_port) {
        fprintf(stderr, "<Start Port> cannot be greater than <End Port>\n");
        exit(EXIT_FAILURE);
    }

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    //set up target sockaddr_in struct
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    //check to make sure IP address is valid
    if (target.sin_addr.s_addr == INADDR_NONE) {
        fprintf(stderr, "%s is not a valid IP address\n", ip_address);
        exit(EXIT_FAILURE);
    }

    printf("Scanning IP Address: %s\n", ip_address);
    printf("Start Port: %d\n", start_port);
    printf("End Port: %d\n", end_port);

    //scan ports
    for (i = start_port; i <= end_port; i++) {
        target.sin_port = htons(i);

        res = connect(sockfd, (struct sockaddr *)&target, sizeof(target));

        if (res == 0) {
            printf("Port %d is open\n", i);
        } else {
            //print error message unless it's a timeout
            if (errno != ETIMEDOUT && errno != ECONNREFUSED) {
                fprintf(stderr, "Error connecting to port %d: %s\n", i, strerror(errno));
            }
        }

        close(sockfd);
    }

    return 0;
}
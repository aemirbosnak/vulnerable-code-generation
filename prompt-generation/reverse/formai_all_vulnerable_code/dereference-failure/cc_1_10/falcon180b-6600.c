//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage: %s <hostname> <start_port> <end_port>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("Error opening socket\n");
        return 1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    listen(sockfd, 5);

    for (portno = start_port; portno <= end_port; portno++) {
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_addr.s_addr = inet_addr(hostname);
        cli_addr.sin_port = htons(portno);

        if (connect(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr)) == 0) {
            printf("Port %d is open\n", portno);
        } else {
            printf("Port %d is closed\n", portno);
        }
    }

    close(sockfd);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, port, ret;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *ip;
    int start_port, end_port;

    // check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    // convert IP address from string to binary format
    ip = argv[1];
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    // get start and end ports
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket failed");
    }

    // loop through all ports and check if they are open
    for (port = start_port; port <= end_port; port++) {
        // set up server address structure for this port
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);

        // connect to the server
        ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // if connect returns 0, the port is open
        if (ret == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error on port %d: %s\n", port, strerror(errno));
        }
    }

    // close socket
    close(sockfd);

    return 0;
}
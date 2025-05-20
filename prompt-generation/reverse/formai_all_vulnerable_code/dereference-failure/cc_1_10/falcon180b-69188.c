//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in target;
    int target_port;
    char *target_host;
    struct hostent *he;

    if (argc!= 3) {
        printf("Usage: %s <hostname/IP> <port>\n", argv[0]);
        exit(1);
    }

    target_host = argv[1];
    target_port = atoi(argv[2]);

    // Resolve hostname/IP
    he = gethostbyname(target_host);
    if (he == NULL) {
        printf("Error: could not resolve hostname/IP\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    // Set up target address
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(target_port);
    target.sin_addr.s_addr = *(unsigned long *)he->h_addr;

    // Connect to target
    retval = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
    if (retval == -1) {
        printf("Error: could not connect to target\n");
        exit(1);
    }

    // Send ping request
    char ping_req[] = "PING";
    send(sockfd, ping_req, strlen(ping_req), 0);

    // Receive response
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    retval = recv(sockfd, buffer, sizeof(buffer), 0);
    if (retval <= 0) {
        printf("Error: no response received\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}
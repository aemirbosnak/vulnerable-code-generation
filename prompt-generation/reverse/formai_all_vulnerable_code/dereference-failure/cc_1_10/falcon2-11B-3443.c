//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>

void print_node_info(const struct sockaddr_in *node) {
    printf("Node: %s\n", inet_ntoa(node->sin_addr));
    printf("Port: %d\n", node->sin_port);
}

int main(int argc, char *argv[]) {
    int sockfd, portnum, n;
    struct sockaddr_in servaddr;
    char *hostname = NULL;
    struct hostent *hostinfo;

    // Parse command line arguments
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    hostname = argv[1];

    // Resolve hostname to IP address
    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        printf("ERROR: No such host\n");
        exit(1);
    }
    bzero((char *) &servaddr, sizeof(servaddr));
    bcopy((char *) hostinfo->h_addr, (char *) &servaddr.sin_addr.s_addr,
           hostinfo->h_length);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);

    // Connect to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    printf("Connected to %s on port %d\n", inet_ntoa(servaddr.sin_addr),
           ntohs(servaddr.sin_port));

    // Get the server's IP address
    struct sockaddr_in server;
    socklen_t serverlen = sizeof(server);
    getsockname(sockfd, (struct sockaddr *) &server, &serverlen);
    printf("Server's IP address: %s\n", inet_ntoa(server.sin_addr));

    // Close the socket
    close(sockfd);

    return 0;
}
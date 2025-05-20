//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <target_ip> <port>\n", argv[0]);
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Resolve the target IP and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the target
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return -1;
    }

    // Send a message to the target
    char *msg = "Hello from the Network Topology Mapper!";
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("send");
        return -1;
    }

    // Receive a response from the target
    char buf[1024];
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return -1;
    }

    // Print the response
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}
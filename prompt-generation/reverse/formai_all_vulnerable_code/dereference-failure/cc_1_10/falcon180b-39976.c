//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd;
    int port;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char *ip;
    int opt = 1;
    int val = 1;
    int err;
    int res;

    if (argc!= 3) {
        fprintf(stderr, "Usage:./ping <IP address> <port number>\n");
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    // Get host information
    host = gethostbyname(ip);
    if (host == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    // Fill in server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send data to server
    res = write(sockfd, "PING", 4);
    if (res < 0) {
        perror("write");
        exit(1);
    }

    // Receive data from server
    char buffer[1024];
    res = read(sockfd, buffer, sizeof(buffer));
    if (res <= 0) {
        perror("read");
        exit(1);
    }

    // Print response
    printf("Response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}
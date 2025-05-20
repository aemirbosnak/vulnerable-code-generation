//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void print_network_topology(const char* hostname, int port) {
    struct hostent* hostinfo;
    struct sockaddr_in addr;
    int sockfd;
    int portnum;
    char host[NI_MAXHOST];

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        printf("Host not found\n");
        return;
    }

    memset((char*)&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr*)hostinfo->h_addr_list[0];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket\n");
        return;
    }

    portnum = htons(port);
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("Failed to connect to server\n");
        return;
    }

    printf("Connected to server: %s\n", inet_ntoa(addr.sin_addr));

    // Send data to server
    char data[] = "Hello, server!";
    int data_size = strlen(data);
    send(sockfd, data, data_size, 0);

    // Receive response from server
    char response[1024];
    recv(sockfd, response, sizeof(response), 0);
    printf("Received response: %s\n", response);

    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    print_network_topology(argv[1], atoi(argv[2]));

    return 0;
}
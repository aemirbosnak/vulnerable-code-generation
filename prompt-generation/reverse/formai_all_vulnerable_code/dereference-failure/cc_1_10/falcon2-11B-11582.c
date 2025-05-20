//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <string.h>
#include <netinet/tcp.h>

// Function to get local IP address
void getLocalIP() {
    int sockfd, n;
    struct sockaddr_in serv_addr, client_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server = gethostbyname("localhost");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(0);

    n = sendto(sockfd, "Hello from localhost", 20, 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    printf("Local IP Address: %s\n", inet_ntoa(serv_addr.sin_addr));
    close(sockfd);
}

// Function to get network topology
void getNetworkTopology() {
    struct hostent *server;
    int sockfd, n;
    struct sockaddr_in serv_addr, client_addr;
    struct hostent *p;
    char buffer[100];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    p = gethostbyname("google.com");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)p->h_addr, (char *)&serv_addr.sin_addr.s_addr, p->h_length);
    serv_addr.sin_port = htons(0);

    n = sendto(sockfd, "GET / HTTP/1.0\r\nHost: google.com\r\n\r\n", 58, 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    printf("Topology: %s\n", buffer);
    close(sockfd);
}

int main() {
    getLocalIP();
    getNetworkTopology();
    return 0;
}
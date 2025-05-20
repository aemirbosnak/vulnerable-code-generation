//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>

// Define constants
#define MAXLINE 1024
#define MAXIP 16

// Define a function to get IP address from hostname
char *dns_lookup(char *hostname)
{
    struct hostent *host_entity;
    char *ip = (char *) calloc(MAXIP, sizeof(char));
    if ((host_entity = gethostbyname(hostname)) == NULL) {
        printf("Could not resolve hostname");
        return NULL;
    }
    // Convert the IP to readable format
    inet_ntop(AF_INET, (void *) host_entity->h_addr_list[0], ip, MAXIP);
    return ip;
}

// Define main function
int main()
{
    int sockfd, n, len;
    struct sockaddr_in servaddr, cliaddr;
    char sendline[MAXLINE], recvline[MAXLINE], hostname[MAXLINE], *ip;
    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("error creating socket");
        exit(EXIT_FAILURE);
    }
    // Set address of server
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8181);
    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("error binding socket");
        exit(EXIT_FAILURE);
    }
    // Get hostname from user input
    printf("Enter hostname to map network topology: ");
    fgets(hostname, MAXLINE, stdin);
    hostname[strlen(hostname)-1] = '\0';
    // Get IP address from hostname
    ip = dns_lookup(hostname);
    if (ip == NULL) {
        exit(EXIT_FAILURE);
    }
    // Send IP address to server
    sendto(sockfd, ip, strlen(ip), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
    len = sizeof(cliaddr);
    // Receive network topology data from server
    n = recvfrom(sockfd, recvline, MAXLINE, 0, (struct sockaddr*)&cliaddr, &len);
    // Print network topology data from server
    printf("\n\nReceived network topology data from server:\n\n%s", recvline);
    // Close socket
    close(sockfd);
    return 0;
}
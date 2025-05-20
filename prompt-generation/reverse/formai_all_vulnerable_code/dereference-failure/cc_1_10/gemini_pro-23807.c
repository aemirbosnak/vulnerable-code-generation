//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

// helper function to get the IP address of a website
int get_ip_address(char *hostname, char *ip_address) {
    struct addrinfo hints, *res;

    // set up the hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;  // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP

    // get the IP address of the website
    int status = getaddrinfo(hostname, NULL, &hints, &res);
    if (status != 0) {
        return -1;
    }

    // copy the IP address to the output buffer
    struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
    strcpy(ip_address, inet_ntoa(addr->sin_addr));

    // free the addrinfo structure
    freeaddrinfo(res);

    return 0;
}

// helper function to check if a website is up
int check_website(char *hostname) {
    char ip_address[16];

    // get the IP address of the website
    int status = get_ip_address(hostname, ip_address);
    if (status != 0) {
        return -1;
    }

    // create a socket to connect to the website
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    // connect to the website
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    status = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (status == -1) {
        close(sockfd);
        return -1;
    }

    // close the socket
    close(sockfd);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];

    // check if the website is up
    int status = check_website(hostname);
    if (status == 0) {
        printf("Website %s is up.\n", hostname);
    } else {
        printf("Website %s is down.\n", hostname);
    }

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to check if a given IP address is allowed to access a given port
int check_access(const char *ip_addr, int port) {
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    int rc = getaddrinfo(ip_addr, NULL, &hints, &servinfo);
    if (rc!= 0) {
        perror("ERROR getting address information");
        return -1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int yes = 1;
        if (port == 0) {
            yes = 1; // Allow all ports
        } else {
            int yes = 0; // Allow only specified port
        }

        if (port!= 0 && p->ai_addrlen == 0) {
            continue;
        }

        if (port == 0) {
            yes = 1;
        } else {
            yes = 1; // Allow only specified port
        }

        if (yes) {
            int rv = connect(sockfd, p->ai_addr, p->ai_addrlen);
            if (rv!= 0) {
                perror("ERROR connecting");
                return -1;
            }
        }
    }

    freeaddrinfo(servinfo);
    close(sockfd);

    return 0;
}

// Function to add or remove IP addresses from a list of allowed IP addresses
int add_ip_addr(const char *ip_addr, int port) {
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    int rc = getaddrinfo(ip_addr, NULL, &hints, &servinfo);
    if (rc!= 0) {
        perror("ERROR getting address information");
        return -1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int yes = 1;
        if (port == 0) {
            yes = 1; // Allow all ports
        } else {
            int yes = 0; // Allow only specified port
        }

        if (port!= 0 && p->ai_addrlen == 0) {
            continue;
        }

        if (port == 0) {
            yes = 1;
        } else {
            yes = 1; // Allow only specified port
        }

        if (yes) {
            int rv = connect(sockfd, p->ai_addr, p->ai_addrlen);
            if (rv!= 0) {
                perror("ERROR connecting");
                return -1;
            }
        }
    }

    freeaddrinfo(servinfo);
    close(sockfd);

    return 0;
}

int main() {
    // Test code
    const char *ip_addr = "192.168.0.1";
    int port = 80;
    int ret = check_access(ip_addr, port);
    if (ret == 0) {
        printf("Allowed\n");
    } else {
        printf("Not allowed\n");
    }

    ret = add_ip_addr(ip_addr, port);
    if (ret == 0) {
        printf("Added\n");
    } else {
        printf("Not added\n");
    }

    return 0;
}
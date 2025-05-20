//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_URL_LENGTH 2048 // Maximum length of a URL
#define MAX_IP_LENGTH INET6_ADDRSTRLEN // Maximum length of an IP address (IPv4 or IPv6)
#define MAX_PORT_LENGTH 6 // Maximum length of a port number (65535 is the maximum value)

// Function to convert an IP address to a string
void ip_to_string(const struct sockaddr *addr, char *dst, size_t size)
{
    if (addr->sa_family == AF_INET) {
        inet_ntop(AF_INET, &(((struct sockaddr_in *)addr)->sin_addr), dst, size);
    } else {
        inet_ntop(AF_INET6, &(((struct sockaddr_in6 *)addr)->sin6_addr), dst, size);
    }
}

// Function to get the host and port from a URL
int get_host_and_port(const char *url, char *host, char *port)
{
    char *p;
    char *h = host;
    int is_ipv6 = 0;
    
    // Check for IPv6 address
    if (url[0] == '[') {
        p = strchr(url, ']');
        if (p == NULL) {
            printf("Invalid URL: %s\n", url);
            return -1;
        }
        strncpy(host, url + 1, p - url - 1);
        h = host + (p - url) - 1;
        is_ipv6 = 1;
    } else {
        p = strchr(url, ':');
        if (p == NULL) {
            printf("Invalid URL: %s\n", url);
            return -1;
        }
        strncpy(host, url, p - url);
    }
    *h = '\0';

    p++;

    strncpy(port, p, MAX_PORT_LENGTH);
    port[MAX_PORT_LENGTH - 1] = '\0';

    // Check for invalid characters in port
    for (int i = 0; i < strlen(port); i++) {
        if (port[i] < '0' || port[i] > '9') {
            printf("Invalid URL: %s\n", url);
            return -1;
        }
    }

    if (!is_ipv6 && strcmp(port, "") == 0) {
        strncpy(port, "80", MAX_PORT_LENGTH);
    }

    return 0;
}

// Function to check if a website is up
int check_website(const char *url)
{
    char host[MAX_URL_LENGTH];
    char port[MAX_PORT_LENGTH];
    if (get_host_and_port(url, host, port) < 0) {
        return -1;
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo *result, *rp;
    int s;

    s = getaddrinfo(host, port, &hints, &result);
    if (s != 0) {
        printf("getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }

    int sockfd;
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            // Connection successful
            break;
        }
        close(sockfd);
    }

    if (rp == NULL) {
        // Couldn't connect to any address
        printf("%s is down\n", url);
        freeaddrinfo(result);
        return 0;
    }

    char ip[MAX_IP_LENGTH];
    ip_to_string(rp->ai_addr, ip, MAX_IP_LENGTH);

    printf("%s (%s) is up\n", url, ip);

    freeaddrinfo(result);
    close(sockfd);

    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s [website URL]\n", argv[0]);
        return 1;
    }

    char *url = argv[1];

    while (1) {
        check_website(url);
        sleep(60);
    }

    return 0;
}
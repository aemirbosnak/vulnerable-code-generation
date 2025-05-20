//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 80
#define TIMEOUT 5

typedef struct {
    char *hostname;
    int sockfd;
} website;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    website w;
    w.hostname = argv[1];

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(w.hostname);
    if (host == NULL) {
        fprintf(stderr, "Can't resolve hostname '%s'\n", w.hostname);
        exit(1);
    }

    // Create a socket
    w.sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (w.sockfd == -1) {
        perror("Can't create socket");
        exit(1);
    }

    // Set socket timeout
    struct timeval tv = { TIMEOUT, 0 };
    if (setsockopt(w.sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("Can't set socket timeout");
        exit(1);
    }

    // Connect to the website
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(w.sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Can't connect to website");
        exit(1);
    }

    // Send a HTTP request
    const char *request = "HEAD / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char buf[1024];
    snprintf(buf, sizeof(buf), request, w.hostname);
    if (send(w.sockfd, buf, strlen(buf), 0) == -1) {
        perror("Can't send HTTP request");
        exit(1);
    }

    // Receive the HTTP response
    if (recv(w.sockfd, buf, sizeof(buf), 0) == -1) {
        perror("Can't receive HTTP response");
        exit(1);
    }

    // Check if the website is up
    if (strstr(buf, "200 OK") != NULL) {
        printf("Website '%s' is up\n", w.hostname);
    } else {
        printf("Website '%s' is down\n", w.hostname);
    }

    // Close the socket
    close(w.sockfd);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 10

struct website {
    char* hostname;
    int port;
    int timeout;
};

struct website* create_website(char* hostname, int port, int timeout) {
    struct website* website = malloc(sizeof(struct website));
    website->hostname = strdup(hostname);
    website->port = port;
    website->timeout = timeout;
    return website;
}

void destroy_website(struct website* website) {
    free(website->hostname);
    free(website);
}

int check_website(struct website* website) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(website->port);
    struct hostent* host = gethostbyname(website->hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }
    memcpy(&servaddr.sin_addr, host->h_addr_list[0], host->h_length);

    int ret = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (ret == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    struct timeval timeout;
    timeout.tv_sec = website->timeout;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    char buffer[1];
    ret = recv(sockfd, buffer, 1, 0);
    if (ret == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    close(sockfd);

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> [port] [timeout]\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    int port = DEFAULT_PORT;
    if (argc >= 3) {
        port = atoi(argv[2]);
    }
    int timeout = DEFAULT_TIMEOUT;
    if (argc >= 4) {
        timeout = atoi(argv[3]);
    }

    struct website* website = create_website(hostname, port, timeout);

    int ret = check_website(website);
    if (ret == -1) {
        fprintf(stderr, "Error checking website\n");
        destroy_website(website);
        return 1;
    }

    printf("Website is up\n");

    destroy_website(website);

    return 0;
}
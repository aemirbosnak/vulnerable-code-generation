//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

struct hostinfo {
    char hostname[100];
    int port;
};

struct hostinfo get_hostname(char* ip) {
    struct hostent* host;
    host = gethostbyaddr((char*)&ip, sizeof(ip), AF_INET);
    if (host == NULL) {
        return (struct hostinfo) {"Unknown", -1};
    }
    strcpy(host->h_name, host->h_name);
    return (struct hostinfo) {host->h_name, host->h_aliases[0]};
}

int main() {
    int sockfd, port, newfd, len;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostinfo info;
    char buf[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(12345);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("Error on listen");
        exit(1);
    }

    while (1) {
        newfd = accept(sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&len);
        if (newfd < 0) {
            perror("Error on accept");
            exit(1);
        }

        bzero(buf, 100);
        len = recv(newfd, buf, 100, 0);
        if (len < 0) {
            perror("Error on recv");
            exit(1);
        }

        info = get_hostname(buf);
        printf("Client connected from %s:%d\n", info.hostname, info.port);
        if (write(newfd, buf, len) < 0) {
            perror("Error on write");
            exit(1);
        }
        close(newfd);
    }

    close(sockfd);
    return 0;
}
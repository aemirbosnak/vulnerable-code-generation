//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int ping(char *hostname, int attempts)
{
    int sockfd, status, bytes_sent, bytes_recv;
    struct sockaddr_in servaddr;
    struct hostent *hp;

    if (attempts > 5) {
        return -1;
    }

    hp = gethostbyname(hostname);
    if (hp == NULL) {
        return -1;
    }

    servaddr.sin_family = hp->h_addrtype;
    servaddr.sin_port = htons(53);
    servaddr.sin_addr.s_addr = inet_addr(hp->h_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(IPPROTO_TCP));
    if (sockfd < 0) {
        return -1;
    }

    bytes_sent = send(sockfd, "PING", 5, 0);
    if (bytes_sent < 0) {
        close(sockfd);
        return -1;
    }

    bytes_recv = recv(sockfd, "RESPONSE", 5, 0);
    if (bytes_recv < 0) {
        close(sockfd);
        return -1;
    }

    close(sockfd);

    if (strcmp("RESPONSE", bytes_recv) == 0) {
        return 0;
    } else {
        return ping(hostname, attempts + 1);
    }
}

int main()
{
    char *hostname = "google.com";
    int attempts = 0;

    if (ping(hostname, attempts) == 0) {
        printf("Ping successful!\n");
    } else {
        printf("Ping failed.\n");
    }

    return 0;
}
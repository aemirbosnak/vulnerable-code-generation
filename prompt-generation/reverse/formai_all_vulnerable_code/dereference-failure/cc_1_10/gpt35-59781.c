//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_DATA_LEN 1024

int main(int argc, char* argv[])
{

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];

    struct addrinfo hints, * res;
    int status;

    /* fill hints structure with 0 */
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;    /* IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* TCP */

    if ((status = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        printf("Error: %s", gai_strerror(status));
        return 1;
    }

    char ipstr[INET6_ADDRSTRLEN];
    struct sockaddr_in *ipv4;
    struct sockaddr_in6 *ipv6;

    /* loop through all the results and connect to the first we can */
    for (struct addrinfo* p = res; p != NULL; p = p->ai_next) {
        if (p->ai_family == AF_INET) { // IPv4
            ipv4 = (struct sockaddr_in*)p->ai_addr;
            inet_ntop(AF_INET, &(ipv4->sin_addr), ipstr, sizeof(ipstr));
        }
        else if (p->ai_family == AF_INET6) { // IPv6
            ipv6 = (struct sockaddr_in6*)p->ai_addr;
            inet_ntop(AF_INET6, &(ipv6->sin6_addr), ipstr, sizeof(ipstr));
        }

        /* create socket */
        int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("Error: socket");
            continue;
        }

        /* connect socket */
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("Error: connect");
            close(sockfd);
            continue;
        }

        /* send data to server */
        if (send(sockfd, "Hello Server!", MAX_DATA_LEN, 0) == -1) {
            perror("Error: send");
            close(sockfd);
            continue;
        }

        /* receive data from server */
        char buff[MAX_DATA_LEN];
        if (recv(sockfd, buff, MAX_DATA_LEN, 0) == -1) {
            perror("Error: recv");
            close(sockfd);
            continue;
        }

        printf("Connected to %s.\nReceived data from server: %s\n", ipstr, buff);
        close(sockfd);
        break;
    }

    freeaddrinfo(res);

    return 0;
}
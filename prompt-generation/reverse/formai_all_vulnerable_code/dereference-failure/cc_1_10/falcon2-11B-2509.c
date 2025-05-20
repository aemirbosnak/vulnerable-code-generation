//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc!= 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    struct hostent *hostp;
    hostp = gethostbyname(argv[1]);
    if (hostp == NULL) {
        printf("No such host\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)hostp->h_addr, (char *)&serv_addr.sin_addr.s_addr, hostp->h_length);
    serv_addr.sin_port = htons(5000);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char buffer[1024];
    int n = 0;
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received %d bytes: %s\n", n, buffer);
        send(sockfd, buffer, n, 0);
    }

    close(sockfd);
    return 0;
}
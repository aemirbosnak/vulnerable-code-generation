//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: surrealist
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    struct hostent *host;
    struct sockaddr_in serv_addr;
    int sockfd, portno;
    int opt = 1;

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error, no such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = htons(atoi(argv[1]));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *) host->h_addr, (char *) &serv_addr.sin_addr.s_addr, host->h_length);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        printf("Error, socket failed\n");
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error, setsockopt failed\n");
        return 1;
    }

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error, bind failed\n");
        return 1;
    }

    while (1) {
        char buffer[1000];
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n < 0) {
            printf("Error, recvfrom failed\n");
            return 1;
        }
        printf("%s\n", buffer);
    }

    return 0;
}
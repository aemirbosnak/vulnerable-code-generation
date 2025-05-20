//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct in_addr *addr;
    char *host;
    char buf[100];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    int port = atoi(argv[2]);

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    addr = (struct in_addr *) server->h_addr_list[0];
    printf("Hostname: %s\n", inet_ntoa(*addr));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    bcopy((char *)addr, (char *)&serv_addr.sin_addr.s_addr, sizeof(struct in_addr));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s on port %d\n", inet_ntoa(*addr), port);

    n = recv(sockfd, buf, 100, 0);
    if (n < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("Received %d bytes of data: %s\n", n, buf);

    return 0;
}
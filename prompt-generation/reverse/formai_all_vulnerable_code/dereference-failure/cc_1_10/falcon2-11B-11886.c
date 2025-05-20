//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    struct hostent *he;
    struct in_addr *ipv4;

    if ((he = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: host not found\n");
        return 1;
    }

    if ((ipv4 = (struct in_addr *) he->h_addr_list[0]) == NULL) {
        fprintf(stderr, "Error: host not found\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: socket creation failed\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = ipv4->s_addr;
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: connection failed\n");
        return 1;
    }

    char response[1024];
    int n = 0;
    while ((n = read(sockfd, response, sizeof(response))) > 0) {
        response[n] = '\0';
        printf("Response: %s\n", response);
    }

    return 0;
}
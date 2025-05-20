//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cryptic
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 1;
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8888);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    char buf[1024];
    bzero(buf, sizeof(buf));

    while (1) {
        int n = read(sockfd, buf, sizeof(buf));
        if (n <= 0) {
            perror("read error");
            return 1;
        }
        printf("%s", buf);
        bzero(buf, sizeof(buf));
    }

    return 0;
}
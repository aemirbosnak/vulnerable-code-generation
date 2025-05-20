//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // Set up a UDP socket
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int len = sizeof(serv_addr);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation error");
        return 1;
    }
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        return 1;
    }
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    while (1) {
        char buf[1024];
        int n = read(sockfd, buf, sizeof(buf));
        if (n <= 0) {
            perror("read error");
            return 1;
        }
        int i;
        for (i = 0; i < n; i++) {
            if (buf[i] == '\n') {
                printf("%c", buf[i]);
                break;
            }
            printf("%c", buf[i]);
        }
        printf("\n");
        sleep(1);
    }
    close(sockfd);
    return 0;
}
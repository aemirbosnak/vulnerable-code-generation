//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFSIZ 1024
#define TRUE 1
#define FALSE 0
#define PORT 7

int main(int argc, char *argv[]) {
    int sockfd, n, i;
    int opt = TRUE;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char *ipaddr;
    char buf[BUFSIZ];
    char *ptr;

    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    ipaddr = argv[1];
    host = gethostbyname(ipaddr);

    if (host == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(ipaddr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    while (TRUE) {
        printf("Enter a string to send: ");
        fgets(buf, BUFSIZ, stdin);
        buf[strcspn(buf, "\n")] = '\0';

        if (strlen(buf) == 0) {
            continue;
        }

        send(sockfd, buf, strlen(buf), 0);

        n = recv(sockfd, buf, BUFSIZ, 0);

        if (n <= 0) {
            break;
        }

        buf[n] = '\0';
        printf("Received: %s\n", buf);
    }

    close(sockfd);

    return 0;
}
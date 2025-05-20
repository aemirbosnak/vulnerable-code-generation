//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <netinet/tcp.h>

void get_ip_address(struct sockaddr_in *sin, const char *hostname, int port) {
    struct hostent *host;
    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }

    memcpy((char *)sin, (char *)host->h_addr_list[0], host->h_length);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <start port> <end port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    get_ip_address(&sin, hostname, 0);

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        return 1;
    }

    for (int i = start_port; i <= end_port; i++) {
        if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) == 0) {
            printf("%d: Open\n", i);
            close(sockfd);
        } else {
            printf("%d: Closed\n", i);
        }
    }

    close(sockfd);
    return 0;
}
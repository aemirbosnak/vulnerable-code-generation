//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <linux/sockios.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int sockfd, valread, optval = 1;
    struct ifreq ifr;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    double start, end, timeTaken;
    FILE *fp;
    int testCount = 10;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Socket creation error");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection error");
        exit(1);
    }

    fp = fopen("results.txt", "w");

    for (int i = 0; i < testCount; i++) {
        start = clock();

        valread = read(sockfd, buffer, 1024);

        end = clock();
        timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

        fprintf(fp, "Test %d: %f seconds\n", i + 1, timeTaken);
    }

    fclose(fp);

    return 0;
}
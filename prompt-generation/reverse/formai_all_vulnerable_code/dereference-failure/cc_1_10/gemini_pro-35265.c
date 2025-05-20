//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ssid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent *host = gethostbyname("8.8.8.8");
    if (!host)
        die("gethostbyname");

    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0)
        die("socket");

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    char buf[BUFSIZE];
    int len = sizeof(addr);
    int n = sendto(sock, NULL, 0, 0, (struct sockaddr *)&addr, len);
    if (n < 0)
        die("sendto");

    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sock, &rfds);

    n = select(sock + 1, &rfds, NULL, NULL, &tv);
    if (n < 0)
        die("select");

    if (FD_ISSET(sock, &rfds)) {
        n = recvfrom(sock, buf, BUFSIZE, 0, (struct sockaddr *)&addr, &len);
        if (n < 0)
            die("recvfrom");

        buf[n] = '\0';
        printf("%s\n", buf);
    } else {
        printf("Request timed out.\n");
    }

    close(sock);
    return EXIT_SUCCESS;
}
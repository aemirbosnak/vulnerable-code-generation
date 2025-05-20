//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 1024

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

int download_test(char *url, int sockfd) {
    char buff[BUFFSIZE];
    int nbytes;

    double start = get_time();
    while ((nbytes = read(sockfd, buff, BUFFSIZE)) > 0) {
        ;
    }
    double end = get_time();

    if (nbytes < 0) {
        perror("read");
        return -1;
    }

    return (int)((end - start) * 1000);
}

int upload_test(char *url, int sockfd) {
    char buff[BUFFSIZE];
    int nbytes;

    double start = get_time();
    while ((nbytes = write(sockfd, buff, BUFFSIZE)) > 0) {
        ;
    }
    double end = get_time();

    if (nbytes < 0) {
        perror("write");
        return -1;
    }

    return (int)((end - start) * 1000);
}

int speed_test(char *url) {
    struct hostent *host;
    struct sockaddr_in addr;
    int sockfd;
    int nbytes;
    char buff[BUFFSIZE];

    if ((host = gethostbyname(url)) == NULL) {
        perror("gethostbyname");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Send HTTP GET request
    sprintf(buff, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
    nbytes = strlen(buff);
    if (write(sockfd, buff, nbytes) != nbytes) {
        perror("write");
        return -1;
    }

    int download_speed = download_test(url, sockfd);
    int upload_speed = upload_test(url, sockfd);

    close(sockfd);

    return download_speed * upload_speed;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s url\n", argv[0]);
        return -1;
    }

    int speed = speed_test(argv[1]);
    if (speed < 0) {
        fprintf(stderr, "Error: speed test failed\n");
        return -1;
    }

    printf("Download speed: %d kbps\n", speed / 1024);
    printf("Upload speed: %d kbps\n", speed % 1024);

    return 0;
}
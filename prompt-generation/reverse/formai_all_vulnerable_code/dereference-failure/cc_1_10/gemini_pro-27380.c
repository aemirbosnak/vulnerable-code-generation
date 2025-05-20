//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct stat_obj {
    double mean;
    double sd;
    double min;
    double max;
};

typedef struct stat_obj stat_obj;

stat_obj calculate_stats(double *data, int n) {
    stat_obj result;
    int i;

    result.mean = 0;
    result.sd = 0;
    result.min = data[0];
    result.max = data[0];

    for (i = 0; i < n; i++) {
        result.mean += data[i];
        if (data[i] < result.min) {
            result.min = data[i];
        }
        if (data[i] > result.max) {
            result.max = data[i];
        }
    }

    result.mean /= n;

    for (i = 0; i < n; i++) {
        result.sd += pow(data[i] - result.mean, 2);
    }

    result.sd /= n;
    result.sd = sqrt(result.sd);

    return result;
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("accept");
        return EXIT_FAILURE;
    }

    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    double *data = (double *) malloc(sizeof(double) * n);
    int i;
    for (i = 0; i < n; i++) {
        data[i] = atof(buffer + i);
    }

    stat_obj stats = calculate_stats(data, n);

    bzero(buffer, 256);
    sprintf(buffer, "Mean: %.2f\nSD: %.2f\nMin: %.2f\nMax: %.2f\n", stats.mean, stats.sd, stats.min, stats.max);
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    close(newsockfd);
    close(sockfd);

    return EXIT_SUCCESS;
}
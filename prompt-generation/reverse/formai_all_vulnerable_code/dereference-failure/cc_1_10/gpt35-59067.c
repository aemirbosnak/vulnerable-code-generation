//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE_LEN 256
#define SEC_BTWN_SAMPLES 1

int main(int argc, char *argv[]) {
    struct addrinfo  hints, *ai, *p;
    int sockfd, result;
    char line[MAX_LINE_LEN+1], time_str[MAX_LINE_LEN+1];
    time_t now;
    struct tm *now_tm;

    /* Check command line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;    
    hints.ai_socktype = SOCK_STREAM; 
    hints.ai_flags = AI_PASSIVE;    

    result = getaddrinfo(argv[1], "http", &hints, &ai);
    if (result != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
        exit(EXIT_FAILURE);
    }

    /* Try each address until we successfully connect */
    for (p = ai; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        /* We got a connection */
        break;
    }

    /* Convert time to a string */
    while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
        now = time(NULL);
        now_tm = localtime(&now);
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", now_tm);
        printf("%s ", time_str);

        /* Send a query */
        if (send(sockfd, line, strlen(line), 0) != strlen(line)) {
            fprintf(stderr, "send failed\n");
            exit(EXIT_FAILURE);
        }

        /* Sleep for a while */
        sleep(SEC_BTWN_SAMPLES);
    }

    /* Clean up */
    freeaddrinfo(ai);
    close(sockfd);
    exit(EXIT_SUCCESS);
}
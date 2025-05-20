//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>

#define MAX_LEN 1024

struct rule {
    char *src;
    char *dst;
    int sport;
    int dport;
    char *proto;
    char *action;
    struct rule *next;
};

struct rule *rules = NULL;

void add_rule(char *src, char *dst, int sport, int dport, char *proto, char *action) {
    struct rule *new_rule = malloc(sizeof(struct rule));
    if (new_rule == NULL) {
        perror("malloc");
        exit(1);
    }
    new_rule->src = strdup(src);
    new_rule->dst = strdup(dst);
    new_rule->sport = sport;
    new_rule->dport = dport;
    new_rule->proto = strdup(proto);
    new_rule->action = strdup(action);
    new_rule->next = rules;
    rules = new_rule;
}

int check_rule(char *src, char *dst, int sport, int dport, char *proto) {
    struct rule *rule = rules;
    while (rule != NULL) {
        if (strcmp(rule->src, src) == 0 && strcmp(rule->dst, dst) == 0 && rule->sport == sport && rule->dport == dport && strcmp(rule->proto, proto) == 0) {
            return 1;
        }
        rule = rule->next;
    }
    return 0;
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_LEN];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        memset(buffer, 0, MAX_LEN);
        if (read(newsockfd, buffer, MAX_LEN) < 0) {
            perror("read");
            exit(1);
        }

        char *src = strtok(buffer, " ");
        char *dst = strtok(NULL, " ");
        char *sport = strtok(NULL, " ");
        char *dport = strtok(NULL, " ");
        char *proto = strtok(NULL, " ");

        if (check_rule(src, dst, atoi(sport), atoi(dport), proto)) {
            write(newsockfd, "1", 1);
        } else {
            write(newsockfd, "0", 1);
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}
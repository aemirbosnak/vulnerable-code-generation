//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_RULES 100
#define MAX_RULE_SIZE 1024

struct rule {
    char *pattern;
    bool allow;
};

struct firewall {
    struct rule rules[MAX_RULES];
    int num_rules;
};

int load_rules(struct firewall *fw, const char *filename) {
    FILE *fp;
    char line[MAX_RULE_SIZE];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *pattern, *allow;

        pattern = strtok(line, ",");
        allow = strtok(NULL, ",");

        if (pattern == NULL || allow == NULL) {
            fprintf(stderr, "Invalid rule: %s", line);
            fclose(fp);
            return -1;
        }

        fw->rules[i].pattern = strdup(pattern);
        fw->rules[i].allow = strcmp(allow, "allow") == 0;
        i++;
    }

    fw->num_rules = i;

    fclose(fp);

    return 0;
}

bool check_packet(struct firewall *fw, const char *packet) {
    int i;

    for (i = 0; i < fw->num_rules; i++) {
        if (strstr(packet, fw->rules[i].pattern) != NULL) {
            return fw->rules[i].allow;
        }
    }

    return false;
}

int main(int argc, char **argv) {
    struct firewall fw;
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <rules file>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    if (load_rules(&fw, argv[2]) != 0) {
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        memset(buffer, 0, sizeof(buffer));
        recv(newsockfd, buffer, sizeof(buffer), 0);

        if (check_packet(&fw, buffer)) {
            send(newsockfd, "Allowed", strlen("Allowed"), 0);
        } else {
            send(newsockfd, "Denied", strlen("Denied"), 0);
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}
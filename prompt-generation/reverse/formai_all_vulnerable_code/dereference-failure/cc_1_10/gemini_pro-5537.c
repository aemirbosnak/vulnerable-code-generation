//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIGS 100
#define MAX_RULES 100

struct signature {
    char *name;
    char *pattern;
    int offset;
    int length;
};

struct rule {
    char *name;
    char *condition;
    char *action;
};

struct intrusion_detection_system {
    struct signature *sigs;
    int num_sigs;
    struct rule *rules;
    int num_rules;
};

struct intrusion_detection_system *ids;

void init_ids() {
    ids = malloc(sizeof(struct intrusion_detection_system));
    ids->sigs = malloc(sizeof(struct signature) * MAX_SIGS);
    ids->num_sigs = 0;
    ids->rules = malloc(sizeof(struct rule) * MAX_RULES);
    ids->num_rules = 0;
}

void add_sig(char *name, char *pattern, int offset, int length) {
    ids->sigs[ids->num_sigs].name = strdup(name);
    ids->sigs[ids->num_sigs].pattern = strdup(pattern);
    ids->sigs[ids->num_sigs].offset = offset;
    ids->sigs[ids->num_sigs].length = length;
    ids->num_sigs++;
}

void add_rule(char *name, char *condition, char *action) {
    ids->rules[ids->num_rules].name = strdup(name);
    ids->rules[ids->num_rules].condition = strdup(condition);
    ids->rules[ids->num_rules].action = strdup(action);
    ids->num_rules++;
}

void load_sigs(char *filename) {
    FILE *fp;
    char line[1024];
    char *name, *pattern, *offset, *length;

    fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        name = strtok(line, " ");
        pattern = strtok(NULL, " ");
        offset = strtok(NULL, " ");
        length = strtok(NULL, " ");

        add_sig(name, pattern, atoi(offset), atoi(length));
    }

    fclose(fp);
}

void load_rules(char *filename) {
    FILE *fp;
    char line[1024];
    char *name, *condition, *action;

    fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        name = strtok(line, " ");
        condition = strtok(NULL, " ");
        action = strtok(NULL, " ");

        add_rule(name, condition, action);
    }

    fclose(fp);
}

void check_packet(char *packet) {
    int i, j, k, l;
    int found;
    char *ptr;

    for (i = 0; i < ids->num_sigs; i++) {
        ptr = packet + ids->sigs[i].offset;
        found = 1;
        for (j = 0; j < ids->sigs[i].length; j++) {
            if (ptr[j] != ids->sigs[i].pattern[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            for (k = 0; k < ids->num_rules; k++) {
                if (strcmp(ids->rules[k].condition, ids->sigs[i].name) == 0) {
                    for (l = 0; l < ids->num_rules; l++) {
                        if (strcmp(ids->rules[l].name, ids->rules[k].action) == 0) {
                            printf("Rule %s triggered by signature %s\n", ids->rules[l].name, ids->sigs[i].name);
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[2048];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
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

        bzero(buffer, sizeof(buffer));
        read(newsockfd, buffer, sizeof(buffer));
        check_packet(buffer);
        close(newsockfd);
    }

    close(sockfd);

    return 0;
}
//FormAI DATASET v1.0 Category: Firewall ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>

#define MAX_RULES 100
#define BUF_SIZE 1024
#define IP_SIZE 16

typedef struct {
    char src_ip[IP_SIZE];
    char dst_ip[IP_SIZE];
    int src_port;
    int dst_port;
    int action;
} firewall_rule;

int num_rules = 0;
firewall_rule rules[MAX_RULES];

int read_config_file(char* filename) {
    FILE* fp;
    char buf[BUF_SIZE];
    char* token;
    char* delim = ",";
    int line = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return -1;
    }

    while (fgets(buf, BUF_SIZE, fp)) {
        if (line == MAX_RULES) {
            printf("Error: Max number of rules exceeded\n");
            break;
        }

        token = strtok(buf, delim);
        strncpy(rules[line].src_ip, token, IP_SIZE);

        token = strtok(NULL, delim);
        strncpy(rules[line].dst_ip, token, IP_SIZE);

        token = strtok(NULL, delim);
        rules[line].src_port = atoi(token);

        token = strtok(NULL, delim);
        rules[line].dst_port = atoi(token);

        token = strtok(NULL, delim);
        rules[line].action = atoi(token);

        line++;
    }

    num_rules = line;

    fclose(fp);
    return 0;
}

int check_rule(firewall_rule rule, char* src_ip, char* dst_ip, int src_port, int dst_port) {
    if (strcmp(rule.src_ip, "any") != 0 && strcmp(rule.src_ip, src_ip) != 0) {
        return 0;
    }

    if (strcmp(rule.dst_ip, "any") != 0 && strcmp(rule.dst_ip, dst_ip) != 0) {
        return 0;
    }

    if (rule.src_port != 0 && rule.src_port != src_port) {
        return 0;
    }

    if (rule.dst_port != 0 && rule.dst_port != dst_port) {
        return 0;
    }

    return 1;
}

int main(int argc, char** argv) {
    char src_ip[IP_SIZE];
    char dst_ip[IP_SIZE];
    int src_port;
    int dst_port;
    int action = -1;
    int i;

    if (argc < 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return -1;
    }

    if (read_config_file(argv[1]) == -1) {
        return -1;
    }

    srand(time(NULL));

    while (1) {
        printf("Enter source IP address (or 'q' to quit): ");
        scanf("%s", src_ip);

        if (strcmp(src_ip, "q") == 0) {
            break;
        }

        printf("Enter destination IP address: ");
        scanf("%s", dst_ip);

        printf("Enter source port: ");
        scanf("%d", &src_port);

        printf("Enter destination port: ");
        scanf("%d", &dst_port);

        for (i = 0; i < num_rules; i++) {
            if (check_rule(rules[i], src_ip, dst_ip, src_port, dst_port)) {
                action = rules[i].action;
                break;
            }
        }

        if (action == -1) {
            if (rand() % 2 == 0) {
                printf("firewall: Blocking traffic from %s to %s:%d\n", src_ip, dst_ip, dst_port);
            } else {
                printf("firewall: Blocking traffic from %s to %s:%d\n", dst_ip, src_ip, src_port);
            }
        } else {
            if (action == 0) {
                printf("firewall: Dropping traffic from %s to %s:%d\n", src_ip, dst_ip, dst_port);
            } else {
                printf("firewall: Allowing traffic from %s to %s:%d\n", src_ip, dst_ip, dst_port);
            }
        }

        action = -1;
    }

    return 0;
}
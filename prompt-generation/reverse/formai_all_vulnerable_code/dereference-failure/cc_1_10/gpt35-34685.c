//FormAI DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IP_LEN 15
#define MAX_RULES 100

/* Firewall rule structure */
struct Rule {
    char source_ip[MAX_IP_LEN+1];
    char dest_ip[MAX_IP_LEN+1];
    int source_port;
    int dest_port;
    char protocol[10];
};

/* Function to check if a string is a valid IP address */
int is_valid_ip(char* ip) {
    int count = 0;
    char* token = strtok(ip, ".");
    while (token != NULL) {
        count++;
        int num = atoi(token);
        if (num < 0 || num > 255) {
            return 0;
        }
        token = strtok(NULL, ".");
    }
    return (count == 4);
}

/* Function to parse a rule string */
int parse_rule(char* rule_str, struct Rule* rule) {
    char delims[] = " ";
    char* token = strtok(rule_str, delims);

    int count = 0;
    while (token != NULL) {
        count++;
        if (count == 1) {
            if (!is_valid_ip(token)) {
                return 0;
            }
            strcpy(rule->source_ip, token);
        } else if (count == 2) {
            if (!is_valid_ip(token)) {
                return 0;
            }
            strcpy(rule->dest_ip, token);
        } else if (count == 3) {
            rule->source_port = atoi(token);
        } else if (count == 4) {
            rule->dest_port = atoi(token);
        } else if (count == 5) {
            strcpy(rule->protocol, token);
        }

        token = strtok(NULL, delims);
    }

    return (count == 5);
}

/* Function to check if a packet matches a rule */
int match_rule(struct Rule* rule, char* source_ip, char* dest_ip, int source_port, int dest_port, char* protocol) {
    return (strcmp(rule->source_ip, source_ip) == 0 &&
            strcmp(rule->dest_ip, dest_ip) == 0 &&
            rule->source_port == source_port &&
            rule->dest_port == dest_port &&
            strcmp(rule->protocol, protocol) == 0);
}

/* Main function */
int main() {
    char* input = (char*) malloc(256 * sizeof(char));
    struct Rule rules[MAX_RULES];
    int num_rules = 0;

    while (1) {
        printf("Enter a rule (or 'q' to quit): ");
        fgets(input, 256, stdin);
        input[strlen(input)-1] = '\0';

        if (strcmp(input, "q") == 0) {
            break;
        }

        if (num_rules >= MAX_RULES) {
            printf("Maximum number of rules exceeded!\n");
            continue;
        }

        struct Rule rule;
        if (!parse_rule(input, &rule)) {
            printf("Invalid rule!\n");
            continue;
        }

        rules[num_rules] = rule;
        num_rules++;
    }

    while (1) {
        printf("Enter a packet (or 'q' to quit): ");
        fgets(input, 256, stdin);
        input[strlen(input)-1] = '\0';

        if (strcmp(input, "q") == 0) {
            break;
        }

        char source_ip[MAX_IP_LEN+1];
        char dest_ip[MAX_IP_LEN+1];
        int source_port;
        int dest_port;
        char protocol[10];

        int count = sscanf(input, "%s %s %d %d %s", source_ip, dest_ip, &source_port, &dest_port, protocol);
        if (count != 5) {
            printf("Invalid packet!\n");
            continue;
        }

        int matched = 0;
        for (int i = 0; i < num_rules; i++) {
            if (match_rule(&rules[i], source_ip, dest_ip, source_port, dest_port, protocol)) {
                matched = 1;
                printf("Packet matched rule %d!\n", i+1);
                break;
            }
        }

        if (!matched) {
            printf("No matching rule found!\n");
        }
    }

    free(input);
    return 0;
}
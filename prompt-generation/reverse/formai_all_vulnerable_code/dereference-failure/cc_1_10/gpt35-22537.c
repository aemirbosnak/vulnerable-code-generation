//FormAI DATASET v1.0 Category: Firewall ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Define some constants */
#define RULE_SIZE 256
#define MAX_PORT 65535
#define MAX_IP 0xFFFFFFFF

/* Define some structures */
typedef struct {
    uint32_t ip_start;
    uint32_t ip_end;
} ip_range_t;

typedef struct {
    uint32_t start_port;
    uint32_t end_port;
} port_range_t;

typedef struct {
    ip_range_t ip_range;
    port_range_t port_range;
    char action[RULE_SIZE];
} rule_t;

typedef struct node {
    rule_t rule;
    struct node *next;
} node_t;

/* Declare some functions */
void parse_args(int argc, char **argv, int *port);
void init_rules_list(node_t **rules_list);
void read_rules_file(node_t **rules_list, char *filename);
void process_packet(node_t *rules_list, char *packet);

int main(int argc, char **argv) {
    int port;
    node_t *rules_list;

    /* Initialize the rules list */
    init_rules_list(&rules_list);

    /* Parse the command line arguments */
    parse_args(argc, argv, &port);

    /* Read the rules from the file */
    read_rules_file(&rules_list, "rules.txt");

    /* Start the server */
    printf("Starting firewall on port %d...\n", port);

    /* Loop forever, processing packets */
    while (1) {
        char packet[1024];
        if (recvfrom(port, packet, sizeof(packet), 0, NULL, NULL) == -1) {
            perror("recvfrom error");
            exit(EXIT_FAILURE);
        }
        process_packet(rules_list, packet);
    }

    return 0;
}

void parse_args(int argc, char **argv, int *port) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    *port = atoi(argv[1]);
}

void init_rules_list(node_t **rules_list) {
    /* Initialize an empty rules list */
    *rules_list = NULL;
}

void read_rules_file(node_t **rules_list, char *filename) {
    FILE *fp;
    char line[RULE_SIZE];

    /* Open the rules file */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen error");
        exit(EXIT_FAILURE);
    }

    /* Read the rules, line by line */
    while (fgets(line, sizeof(line), fp) != NULL) {
        /* Parse the rule */
        char *ip_start_str, *ip_end_str, *port_start_str, *port_end_str, *action_str;
        ip_start_str = strtok(line, ",");
        ip_end_str = strtok(NULL, ",");
        port_start_str = strtok(NULL, ",");
        port_end_str = strtok(NULL, ",");
        action_str = strtok(NULL, "\n");

        /* Convert the IP range and port range to integers */
        uint32_t ip_start = inet_addr(ip_start_str);
        uint32_t ip_end = inet_addr(ip_end_str);
        uint32_t port_start = atoi(port_start_str);
        uint32_t port_end = atoi(port_end_str);

        /* Create a new rule and add it to the list */
        node_t *new_rule = malloc(sizeof(node_t));
        new_rule->rule.ip_range.ip_start = ip_start;
        new_rule->rule.ip_range.ip_end = ip_end;
        new_rule->rule.port_range.start_port = port_start;
        new_rule->rule.port_range.end_port = port_end;
        strcpy(new_rule->rule.action, action_str);
        new_rule->next = *rules_list;
        *rules_list = new_rule;
    }

    /* Close the file */
    fclose(fp);
}

void process_packet(node_t *rules_list, char *packet) {
    /* Extract the IP address and port number from the packet */
    char ip_str[INET_ADDRSTRLEN];
    uint16_t port;
    struct sockaddr_in *addr = (struct sockaddr_in *)packet;
    inet_ntop(AF_INET, &(addr->sin_addr), ip_str, INET_ADDRSTRLEN);
    port = ntohs(addr->sin_port);

    /* Convert the IP address to an integer */
    uint32_t ip = inet_addr(ip_str);

    /* Check each rule in turn, to see if it matches */
    node_t *current_rule = rules_list;
    while (current_rule != NULL) {
        rule_t rule = current_rule->rule;

        /* Check if the IP address is in range */
        if (ip >= rule.ip_range.ip_start && ip <= rule.ip_range.ip_end) {

            /* Check if the port number is in range */
            if (port >= rule.port_range.start_port && port <= rule.port_range.end_port) {

                /* Apply the action */
                if (strcmp(rule.action, "allow") == 0) {
                    printf("Allowed packet from %s:%d\n", ip_str, port);
                    return;
                } else if (strcmp(rule.action, "deny") == 0) {
                    printf("Denied packet from %s:%d\n", ip_str, port);
                    return;
                } else {
                    printf("Invalid action in rule: %s\n", rule.action);
                    return;
                }
            }
        }

        /* Move on to the next rule */
        current_rule = current_rule->next;
    }

    /* No rule matched, so deny the packet */
    printf("Denied packet from %s:%d\n", ip_str, port);
}
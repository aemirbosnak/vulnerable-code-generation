//FormAI DATASET v1.0 Category: Firewall ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100

struct rule {
    char src_ip[16];
    char dest_ip[16];
    int src_port;
    int dest_port;
    char protocol[5];
    bool allowed;
};

int num_rules = 0;
struct rule rules[MAX_RULES];

// Function to print a rule
void print_rule(struct rule r) {
    printf("%s %s %d %d %s %s\n", r.src_ip, r.dest_ip, r.src_port, r.dest_port, r.protocol, r.allowed ? "ALLOWED" : "DENIED");
}

// Function to add a rule to the firewall
void add_rule(char* src_ip, char* dest_ip, int src_port, int dest_port, char* protocol, bool allowed) {
    // Check if maximum number of rules has been reached
    if (num_rules >= MAX_RULES) {
        printf("Error: maximum number of firewall rules reached.\n");
        return;
    }

    // Create a new rule
    struct rule r;
    strncpy(r.src_ip, src_ip, 16);
    strncpy(r.dest_ip, dest_ip, 16);
    r.src_port = src_port;
    r.dest_port = dest_port;
    strncpy(r.protocol, protocol, 5);
    r.allowed = allowed;

    // Add the rule to the rules list
    rules[num_rules++] = r;

    printf("Rule added successfully.\n");
}

// Function to check if a packet matches any of the firewall rules
bool check_packet(char* src_ip, char* dest_ip, int src_port, int dest_port, char* protocol) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].protocol, protocol) == 0) {
            if (strcmp(rules[i].src_ip, src_ip) == 0 || strcmp(rules[i].src_ip, "*") == 0) {
                if (strcmp(rules[i].dest_ip, dest_ip) == 0 || strcmp(rules[i].dest_ip, "*") == 0) {
                    if (rules[i].src_port == src_port || rules[i].src_port == 0) {
                        if (rules[i].dest_port == dest_port || rules[i].dest_port == 0) {
                            return rules[i].allowed;
                        }
                    }
                }
            }
        }
    }
    return true;
}

// Function to print all the firewall rules
void print_rules() {
    for (int i = 0; i < num_rules; i++) {
        print_rule(rules[i]);
    }
}

// Function to parse a string into a packet
void parse_packet(char* packet_str, char* src_ip, char* dest_ip, int* src_port, int* dest_port, char* protocol) {
    char* token = strtok(packet_str, " ");
    strcpy(src_ip, token);

    token = strtok(NULL, " ");
    strcpy(dest_ip, token);

    token = strtok(NULL, " ");
    *src_port = atoi(token);

    token = strtok(NULL, " ");
    *dest_port = atoi(token);

    token = strtok(NULL, " ");
    strcpy(protocol, token);
}

int main() {
    char input[100];
    while (1) {
        // Read user input
        printf("Enter a command: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Parse command
        char* command = strtok(input, " ");
        if (strcmp(command, "add") == 0) {
            char* src_ip = strtok(NULL, " ");
            char* dest_ip = strtok(NULL, " ");
            int src_port = atoi(strtok(NULL, " "));
            int dest_port = atoi(strtok(NULL, " "));
            char* protocol = strtok(NULL, " ");
            bool allowed = strcmp(strtok(NULL, " "), "ALLOWED") == 0;

            add_rule(src_ip, dest_ip, src_port, dest_port, protocol, allowed);
        } else if (strcmp(command, "check") == 0) {
            char packet_str[50];
            fgets(packet_str, 50, stdin);
            packet_str[strcspn(packet_str, "\n")] = 0; // Remove newline character

            char src_ip[16];
            char dest_ip[16];
            int src_port, dest_port;
            char protocol[5];
            parse_packet(packet_str, src_ip, dest_ip, &src_port, &dest_port, protocol);

            bool allowed = check_packet(src_ip, dest_ip, src_port, dest_port, protocol);
            printf("%s\n", allowed ? "ALLOWED" : "DENIED");
        } else if (strcmp(command, "list") == 0) {
            print_rules();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
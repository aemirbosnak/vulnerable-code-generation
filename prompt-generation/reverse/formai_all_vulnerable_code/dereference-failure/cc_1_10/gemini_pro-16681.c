//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// Struct to store intrusion detection rules
typedef struct {
    char *pattern;
    int severity;
} Rule;

// Function to parse intrusion detection rules from a file
Rule *parse_rules(char *filename, int *num_rules) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    Rule *rules = NULL;
    int i = 0;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    // Get the number of rules
    *num_rules = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        (*num_rules)++;
    }
    rewind(fp);

    // Allocate memory for the rules
    rules = malloc(*num_rules * sizeof(Rule));
    if (rules == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Parse the rules
    while ((read = getline(&line, &len, fp)) != -1) {
        // Split the line into the pattern and severity
        char *pattern = strtok(line, ":");
        int severity = atoi(strtok(NULL, ":"));

        // Store the rule
        rules[i].pattern = strdup(pattern);
        rules[i].severity = severity;
        i++;
    }

    // Close the file
    fclose(fp);

    // Return the rules
    return rules;
}

// Function to check if a packet matches an intrusion detection rule
int check_rule(Rule *rule, char *packet) {
    // Compare the packet to the rule's pattern
    if (strstr(packet, rule->pattern) != NULL) {
        return rule->severity;
    }

    // No match
    return 0;
}

// Function to monitor network traffic for intrusions
void monitor_traffic(int port) {
    int sockfd, newsockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[256];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Parse the intrusion detection rules
    int num_rules;
    Rule *rules = parse_rules("rules.txt", &num_rules);
    if (rules == NULL) {
        perror("parse_rules");
        exit(1);
    }

    // Main loop
    while (1) {
        // Accept an incoming connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Receive data from the client
        memset(buffer, 0, sizeof(buffer));
        n = recv(newsockfd, buffer, sizeof(buffer) - 1, 0);
        if (n < 0) {
            perror("recv");
            close(newsockfd);
            continue;
        }

        // Check the data for intrusions
        int severity = 0;
        for (int i = 0; i < num_rules; i++) {
            int rule_severity = check_rule(&rules[i], buffer);
            if (rule_severity > severity) {
                severity = rule_severity;
            }
        }

        // Log the intrusion
        if (severity > 0) {
            printf("Intrusion detected! Severity: %d\n", severity);
        }

        // Close the connection
        close(newsockfd);
    }

    // Free the memory allocated for the rules
    for (int i = 0; i < num_rules; i++) {
        free(rules[i].pattern);
    }
    free(rules);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the port number was specified
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Start monitoring network traffic
    monitor_traffic(atoi(argv[1]));

    return 0;
}
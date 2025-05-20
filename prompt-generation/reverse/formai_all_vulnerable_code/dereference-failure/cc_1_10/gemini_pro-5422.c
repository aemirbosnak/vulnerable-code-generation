//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_RULES 100
#define MAX_CONNECTIONS 100
#define MAX_BUFFER_SIZE 1024

// Firewall rule structure
typedef struct firewall_rule {
    char *source_ip;
    char *destination_ip;
    char *protocol;
    int source_port;
    int destination_port;
    char *action;
} firewall_rule;

// Connection structure
typedef struct connection {
    char *source_ip;
    char *destination_ip;
    char *protocol;
    int source_port;
    int destination_port;
} connection;

// Firewall state
typedef struct firewall_state {
    firewall_rule rules[MAX_RULES];
    int num_rules;
    connection connections[MAX_CONNECTIONS];
    int num_connections;
} firewall_state;

// Create a new firewall state
firewall_state *firewall_state_new() {
    firewall_state *state = malloc(sizeof(firewall_state));
    state->num_rules = 0;
    state->num_connections = 0;
    return state;
}

// Free a firewall state
void firewall_state_free(firewall_state *state) {
    for (int i = 0; i < state->num_rules; i++) {
        free(state->rules[i].source_ip);
        free(state->rules[i].destination_ip);
        free(state->rules[i].protocol);
        free(state->rules[i].action);
    }
    for (int i = 0; i < state->num_connections; i++) {
        free(state->connections[i].source_ip);
        free(state->connections[i].destination_ip);
        free(state->connections[i].protocol);
    }
    free(state);
}

// Add a firewall rule to the state
int firewall_state_add_rule(firewall_state *state, firewall_rule *rule) {
    if (state->num_rules >= MAX_RULES) {
        return -1;
    }
    state->rules[state->num_rules++] = *rule;
    return 0;
}

// Add a connection to the state
int firewall_state_add_connection(firewall_state *state, connection *connection) {
    if (state->num_connections >= MAX_CONNECTIONS) {
        return -1;
    }
    state->connections[state->num_connections++] = *connection;
    return 0;
}

// Check if a connection is allowed by the firewall
int firewall_state_check_connection(firewall_state *state, connection *connection) {
    for (int i = 0; i < state->num_rules; i++) {
        firewall_rule *rule = &state->rules[i];
        if (!strcmp(rule->source_ip, connection->source_ip) &&
            !strcmp(rule->destination_ip, connection->destination_ip) &&
            !strcmp(rule->protocol, connection->protocol) &&
            rule->source_port == connection->source_port &&
            rule->destination_port == connection->destination_port) {
            return !strcmp(rule->action, "allow");
        }
    }
    return 0;
}

// Print the firewall state
void firewall_state_print(firewall_state *state) {
    for (int i = 0; i < state->num_rules; i++) {
        firewall_rule *rule = &state->rules[i];
        printf("Rule %d: %s %s %s %d %d %s\n", i, rule->source_ip, rule->destination_ip, rule->protocol, rule->source_port, rule->destination_port, rule->action);
    }
    for (int i = 0; i < state->num_connections; i++) {
        connection *connection = &state->connections[i];
        printf("Connection %d: %s %s %s %d %d\n", i, connection->source_ip, connection->destination_ip, connection->protocol, connection->source_port, connection->destination_port);
    }
}

// Main function
int main() {
    // Create a new firewall state
    firewall_state *state = firewall_state_new();

    // Add some firewall rules to the state
    firewall_rule rule1 = {
        "192.168.1.1",
        "192.168.1.2",
        "tcp",
        80,
        80,
        "allow"
    };
    firewall_state_add_rule(state, &rule1);

    firewall_rule rule2 = {
        "192.168.1.2",
        "192.168.1.1",
        "tcp",
        80,
        80,
        "allow"
    };
    firewall_state_add_rule(state, &rule2);

    firewall_rule rule3 = {
        "192.168.1.3",
        "192.168.1.4",
        "tcp",
        22,
        22,
        "allow"
    };
    firewall_state_add_rule(state, &rule3);

    firewall_rule rule4 = {
        "192.168.1.4",
        "192.168.1.3",
        "tcp",
        22,
        22,
        "allow"
    };
    firewall_state_add_rule(state, &rule4);

    // Add some connections to the state
    connection connection1 = {
        "192.168.1.1",
        "192.168.1.2",
        "tcp",
        80,
        80
    };
    firewall_state_add_connection(state, &connection1);

    connection connection2 = {
        "192.168.1.2",
        "192.168.1.1",
        "tcp",
        80,
        80
    };
    firewall_state_add_connection(state, &connection2);

    connection connection3 = {
        "192.168.1.3",
        "192.168.1.4",
        "tcp",
        22,
        22
    };
    firewall_state_add_connection(state, &connection3);

    connection connection4 = {
        "192.168.1.4",
        "192.168.1.3",
        "tcp",
        22,
        22
    };
    firewall_state_add_connection(state, &connection4);

    // Print the firewall state
    firewall_state_print(state);

    // Free the firewall state
    firewall_state_free(state);

    return 0;
}
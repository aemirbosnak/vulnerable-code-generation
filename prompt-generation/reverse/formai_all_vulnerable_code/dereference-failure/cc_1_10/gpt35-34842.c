//FormAI DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define maximum length for IP addresses and ports */
#define MAX_IP_LEN 16 // IPv4 address has 4 bytes i.e. length of 4 digits and 3 dots 
#define MAX_PORT_LEN 5 // Port string length is 5 (including null terminator)

/* Define a structure for our firewall rule */
typedef struct {
    char src_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    char src_port[MAX_PORT_LEN];
    char dest_port[MAX_PORT_LEN];
    int action; // 0 for block, 1 for allow
} firewall_rule;

/* Define a function to parse an IP/port string and extract the individual pieces */
void parse_ip_port_string(char *ip_port_str, char *ip, char *port) {
    char *colon_pos = strchr(ip_port_str, ':'); // Find colon separator between IP and port portions
    if (colon_pos == NULL) { // Invalid string format
        printf("Error: Invalid IP/port string: %s\n", ip_port_str);
        exit(1);
    }
    strncpy(ip, ip_port_str, colon_pos - ip_port_str); // Extract IP portion
    ip[colon_pos - ip_port_str] = '\0'; // Null-terminate IP string
    strcpy(port, colon_pos + 1); // Extract port portion
}

int main() {
    int num_rules;
    printf("Enter number of firewall rules: ");
    scanf("%d", &num_rules);

    /* Allocate memory for firewall rules array */
    firewall_rule *rules = (firewall_rule*) malloc(num_rules * sizeof(firewall_rule)); 

    /* Read in firewall rules from user input */ 
    for (int i = 0; i < num_rules; i++) {
        printf("Enter firewall rule #%d:\n", i + 1);

        /* Source IP/Port */
        char *src_ip_port_str = (char*) malloc(MAX_IP_LEN + MAX_PORT_LEN + 1); // Allocate enough space for full IP/port string
        printf("Source IP/port: ");
        scanf("%s", src_ip_port_str);
        parse_ip_port_string(src_ip_port_str, rules[i].src_ip, rules[i].src_port);
        free(src_ip_port_str);

        /* Destination IP/Port */
        char *dest_ip_port_str = (char*) malloc(MAX_IP_LEN + MAX_PORT_LEN + 1); // Allocate enough space for full IP/port string
        printf("Destination IP/port: ");
        scanf("%s", dest_ip_port_str);
        parse_ip_port_string(dest_ip_port_str, rules[i].dest_ip, rules[i].dest_port);
        free(dest_ip_port_str);

        /* Action */
        printf("Action (0 = block, 1 = allow): ");
        scanf("%d", &rules[i].action);
    }

    /* Simulate incoming packets and apply firewall rules */
    while (1) { // Loop forever
        char *packet_ip_port_str = (char*) malloc(MAX_IP_LEN + MAX_PORT_LEN + 1); // Allocate enough space for full IP/port string
        printf("Enter incoming packet IP/port (or type 'quit' to end): ");
        scanf("%s", packet_ip_port_str);
        if (strcmp(packet_ip_port_str, "quit") == 0) {
            break; // Exit loop if user types 'quit'
        }

        /* Parse packet IP/port string */
        char packet_ip[MAX_IP_LEN];
        char packet_port[MAX_PORT_LEN];
        parse_ip_port_string(packet_ip_port_str, packet_ip, packet_port);
        free(packet_ip_port_str);

        /* Check if packet matches any firewall rule */
        int rule_match = 0;
        for (int i = 0; i < num_rules; i++) {
            if (strcmp(packet_ip, rules[i].dest_ip) == 0 &&
                strcmp(packet_port, rules[i].dest_port) == 0) {
                rule_match = 1;
                printf("Packet matched firewall rule #%d\n", i + 1);
                if (rules[i].action == 0) {
                    printf("Packet blocked\n");
                } else {
                    printf("Packet allowed\n");
                }
                break; // Stop checking rules if a match is found
            }
        }
        if (!rule_match) {
            printf("No firewall rule match found, packet allowed\n");
        }
    }

    /* Free memory for firewall rules array */
    free(rules);

    return 0;
}
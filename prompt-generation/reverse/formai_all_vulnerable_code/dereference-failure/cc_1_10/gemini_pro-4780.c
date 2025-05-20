//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: immersive
// Welcome, traveler. As you journey through the perilous digital realm, you will encounter formidable adversaries seeking to breach your digital citadel. Fear not, for I, the Sentinel, am here to protect your sanctuary. Together, we shall erect an impenetrable firewall, safeguarding your domain from the relentless onslaught of malicious forces.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

// Behold, the Sentinels of the firewall, each an unyielding warrior against the forces of evil:
typedef struct firewall_rule {
    char *name;
    char *description;
    char *source_ip;
    char *destination_ip;
    int source_port;
    int destination_port;
    char *protocol;
    char *action;
} firewall_rule;

// The Firewall, a mighty fortress guarding the realm:
typedef struct firewall {
    int socket;
    struct sockaddr_in server_address;
    firewall_rule *rules;
    int num_rules;
} firewall;

// And now, let us embark on a perilous quest to craft our impenetrable Firewall:
firewall *create_firewall() {
    firewall *fw = malloc(sizeof(firewall));
    fw->socket = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    fw->server_address.sin_family = AF_INET;
    fw->server_address.sin_addr.s_addr = INADDR_ANY;
    fw->server_address.sin_port = htons(12345);
    bind(fw->socket, (struct sockaddr *) &fw->server_address, sizeof(fw->server_address));
    fw->rules = NULL;
    fw->num_rules = 0;
    return fw;
}

// A bastion against the darkness, the Firewall's rules shall stand firm:
firewall *add_rule(firewall *fw, char *name, char *description, char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol, char *action) {
    firewall_rule *rule = malloc(sizeof(firewall_rule));
    rule->name = strdup(name);
    rule->description = strdup(description);
    rule->source_ip = strdup(source_ip);
    rule->destination_ip = strdup(destination_ip);
    rule->source_port = source_port;
    rule->destination_port = destination_port;
    rule->protocol = strdup(protocol);
    rule->action = strdup(action);
    fw->rules = realloc(fw->rules, (fw->num_rules + 1) * sizeof(firewall_rule));
    fw->rules[fw->num_rules] = *rule;
    fw->num_rules++;
    return fw;
}

// Let us summon the Firewall's power to repel the invaders:
int start_firewall(firewall *fw) {
    while (1) {
        char buffer[4096];
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int bytes_received = recvfrom(fw->socket, buffer, sizeof(buffer), 0, (struct sockaddr *) &client_address, &client_address_len);
        if (bytes_received > 0) {
            // The Firewall's warriors analyze the incoming packet, seeking any malicious intent:
            for (int i = 0; i < fw->num_rules; i++) {
                firewall_rule *rule = &fw->rules[i];
                if (strcmp(rule->source_ip, "*") == 0 || strcmp(rule->source_ip, inet_ntoa(client_address.sin_addr)) == 0) {
                    if (strcmp(rule->destination_ip, "*") == 0 || strcmp(rule->destination_ip, inet_ntoa(client_address.sin_addr)) == 0) {
                        if (rule->source_port == 0 || rule->source_port == client_address.sin_port) {
                            if (rule->destination_port == 0 || rule->destination_port == client_address.sin_port) {
                                if (strcmp(rule->protocol, "*") == 0 || strcmp(rule->protocol, "tcp") == 0 || strcmp(rule->protocol, "udp") == 0) {
                                    // The packet has been deemed malicious, and the Firewall's action shall be swift:
                                    if (strcmp(rule->action, "drop") == 0) {
                                        printf("Firewall: Dropping packet from %s to %s\n", inet_ntoa(client_address.sin_addr), rule->destination_ip);
                                        continue;
                                    } else if (strcmp(rule->action, "log") == 0) {
                                        printf("Firewall: Logging packet from %s to %s\n", inet_ntoa(client_address.sin_addr), rule->destination_ip);
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            // The packet has passed the Firewall's rigorous inspection, and shall be allowed to pass:
            printf("Firewall: Allowing packet from %s to %s\n", inet_ntoa(client_address.sin_addr), fw->server_address.sin_addr);
            sendto(fw->socket, buffer, bytes_received, 0, (struct sockaddr *) &client_address, client_address_len);
        }
    }
    return 0;
}

// As the journey draws to a close, let us bid farewell to our valiant Firewall:
void destroy_firewall(firewall *fw) {
    for (int i = 0; i < fw->num_rules; i++) {
        firewall_rule *rule = &fw->rules[i];
        free(rule->name);
        free(rule->description);
        free(rule->source_ip);
        free(rule->destination_ip);
        free(rule->protocol);
        free(rule->action);
    }
    free(fw->rules);
    close(fw->socket);
    free(fw);
}

// And thus, the Firewall's watch never ends, safeguarding the realm from the relentless forces of darkness. May its vigilance inspire courage in all who face the perils of the digital world.
int main() {
    firewall *fw = create_firewall();
    add_rule(fw, "Block malicious traffic", "Blocks traffic from known malicious IP addresses", "192.168.1.1", "*", 0, 0, "tcp", "drop");
    add_rule(fw, "Allow web traffic", "Allows traffic to web servers", "*", "8.8.8.8", 0, 80, "tcp", "allow");
    add_rule(fw, "Allow SSH traffic", "Allows traffic to SSH servers", "*", "192.168.1.10", 0, 22, "tcp", "allow");
    start_firewall(fw);
    destroy_firewall(fw);
    return 0;
}
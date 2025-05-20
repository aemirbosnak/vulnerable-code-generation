//Gemma-7B DATASET v1.0 Category: Firewall ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Firewall {
    char **rules;
    int size;
} Firewall;

Firewall *firewall_create(int size) {
    Firewall *firewall = malloc(sizeof(Firewall));
    firewall->rules = malloc(sizeof(char *) * size);
    firewall->size = size;
    return firewall;
}

void firewall_add_rule(Firewall *firewall, char *rule) {
    firewall->rules[firewall->size++] = strdup(rule);
}

int firewall_check(Firewall *firewall, char *request) {
    for (int i = 0; i < firewall->size; i++) {
        if (strstr(firewall->rules[i], request) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Firewall *firewall = firewall_create(10);
    firewall_add_rule(firewall, "allow all traffic from 192.168.1.1");
    firewall_add_rule(firewall, "deny all traffic from 192.168.1.2");
    firewall_add_rule(firewall, "allow all traffic from 192.168.1.3");

    if (firewall_check(firewall, "192.168.1.1:80")) {
        printf("Allow\n");
    } else {
        printf("Deny\n");
    }

    if (firewall_check(firewall, "192.168.1.2:80")) {
        printf("Allow\n");
    } else {
        printf("Deny\n");
    }

    if (firewall_check(firewall, "192.168.1.3:80")) {
        printf("Allow\n");
    } else {
        printf("Deny\n");
    }

    return 0;
}
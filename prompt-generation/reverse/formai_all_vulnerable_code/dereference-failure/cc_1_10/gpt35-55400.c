//FormAI DATASET v1.0 Category: Firewall ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct rule {
    char dir[5];
    char proto[5];
    char src_ip[20];
    char dest_ip[20];
    int src_port;
    int dest_port;
};

struct node {
    struct rule r;
    struct node *next;
};

typedef struct node NODE;
NODE *head = NULL;

void add_rule(struct rule r) {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->r = r;
    new_node->next = head;
    head = new_node;
}

void print_rules() {
    NODE *current = head;
    while(current != NULL) {
        printf("%s %s %s %s %d %d\n", current->r.dir, current->r.proto, current->r.src_ip, current->r.dest_ip, current->r.src_port, current->r.dest_port);
        current = current->next;
    }
}

int check_rule(struct rule r) {
    NODE *current = head;
    while(current != NULL) {
        if(strcmp(current->r.dir, r.dir) == 0) {
            if(strcmp(current->r.proto, r.proto) == 0) {
                if(strcmp(current->r.src_ip, r.src_ip) == 0 || strcmp(current->r.src_ip, "*") == 0) {
                    if(strcmp(current->r.dest_ip, r.dest_ip) == 0 || strcmp(current->r.dest_ip, "*") == 0) {
                        if(current->r.src_port == r.src_port || current->r.src_port == 0) {
                            if(current->r.dest_port == r.dest_port || current->r.dest_port == 0) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        current = current->next;
    }
    return 0;
}

int main() {
    struct rule r1 = {.dir = "in", .proto = "udp", .src_ip = "*", .dest_ip = "192.168.1.1", .src_port = 0, .dest_port = 53};
    struct rule r2 = {.dir = "out", .proto = "tcp", .src_ip = "192.168.1.2", .dest_ip = "*", .src_port = 80, .dest_port = 0};
    
    add_rule(r1);
    add_rule(r2);
    
    print_rules();
    
    struct rule test_rule = {.dir = "out", .proto = "tcp", .src_ip = "192.168.1.2", .dest_ip = "8.8.8.8", .src_port = 80, .dest_port = 0};
    
    if(check_rule(test_rule)) {
        printf("Rule exists\n");
    } else {
        printf("Rule does not exist\n");
    }
    
    return 0;
}
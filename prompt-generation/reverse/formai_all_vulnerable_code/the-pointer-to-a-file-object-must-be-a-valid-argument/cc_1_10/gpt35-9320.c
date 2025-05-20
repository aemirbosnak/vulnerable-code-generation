//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

// Structure for storing the network topology map
typedef struct node {
    char* name;
    char* ip;
    struct node* next;
} Node;

// Parses the nmap output file and creates a network topology map
Node* parse_nmap_output(const char* filename) {
    FILE* file = fopen(filename, "r");
    char buf[BUF_SIZE];
    Node* head = NULL;
    Node* curr = NULL;

    while (fgets(buf, sizeof(buf), file) != NULL) {
        // Ignore comments and lines that don't contain IP addresses
        if (buf[0] == '#') {
            continue;
        }
        char* ip_start = strstr(buf, "Nmap scan report for ");
        if (ip_start == NULL) {
            continue;
        }
        ip_start += strlen("Nmap scan report for ");
        char* ip_end = strstr(ip_start, "\n");
        *ip_end = '\0';
        char* name_start = strstr(buf, "(");
        if (name_start == NULL) {
            continue;
        }
        name_start += strlen("(");
        char* name_end = strstr(name_start, ")");
        *name_end = '\0';
        // Create a new node and add it to the linked list
        Node* node = (Node*) malloc(sizeof(Node));
        node->name = strdup(name_start);
        node->ip = strdup(ip_start);
        node->next = NULL;
        if (head == NULL) {
            head = node;
            curr = node;
        } else {
            curr->next = node;
            curr = node;
        }
    }
    fclose(file);
    return head;
}

// Prints the network topology map to the console
void print_topology_map(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%s (%s)\n", curr->name, curr->ip);
        curr = curr->next;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <nmap_output_file>\n", argv[0]);
        return 1;
    }
    Node* head = parse_nmap_output(argv[1]);
    print_topology_map(head);
    return 0;
}
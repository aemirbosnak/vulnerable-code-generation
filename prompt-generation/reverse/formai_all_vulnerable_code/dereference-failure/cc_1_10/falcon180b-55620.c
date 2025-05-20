//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 1000
#define MAX_LINES 10000

typedef struct {
    char name[20];
    int connections[MAX_NODES];
    int num_connections;
} Node;

typedef struct {
    char source;
    char destination;
} Line;

Node nodes[MAX_NODES];
Line lines[MAX_LINES];
int num_nodes;
int num_lines;

void add_node(char* name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return;
        }
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].num_connections = 0;
    num_nodes++;
}

void add_line(char source, char destination) {
    int i;
    for (i = 0; i < num_lines; i++) {
        if (lines[i].source == source && lines[i].destination == destination) {
            return;
        }
    }
    strcpy(lines[num_lines].source, source);
    strcpy(lines[num_lines].destination, destination);
    num_lines++;
}

void print_nodes() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("%s\n", nodes[i].name);
    }
}

void print_lines() {
    int i;
    for (i = 0; i < num_lines; i++) {
        printf("%c -> %c\n", lines[i].source, lines[i].destination);
    }
}

int main() {
    char input[100];
    while (fgets(input, 100, stdin)!= NULL) {
        if (input[0] == 'A') {
            char* name = strtok(input, " ");
            add_node(name);
        } else if (input[0] == 'C') {
            char source = input[2];
            char destination = input[4];
            add_line(source, destination);
        }
    }
    print_nodes();
    print_lines();
    return 0;
}
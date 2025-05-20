//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

// Function prototypes
int is_valid_ip(char *ip);
void print_usage(char *program);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    if (!is_valid_ip(ip)) {
        printf("Invalid IP address: %s\n", ip);
        return 1;
    }

    // TODO: Implement QoS monitoring logic here

    return 0;
}

int is_valid_ip(char *ip) {
    int i, j;
    int dot_count = 0;
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            dot_count++;
        } else if (!isdigit(ip[i])) {
            return 0;
        }
    }
    if (dot_count!= 3) {
        return 0;
    }
    return 1;
}

void print_usage(char *program) {
    printf("Usage: %s <IP address> <port>\n", program);
}
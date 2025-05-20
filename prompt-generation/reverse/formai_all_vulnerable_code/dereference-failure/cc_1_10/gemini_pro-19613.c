//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

// A mind-boggling array of rules
const char* rules[] = {
    "Thou shalt not pass without a password",
    "The forbidden fruit is not an apple",
    "The key to the kingdom is not under the rug",
    "The Trojan horse is not a gift",
    "The serpent's tongue is not to be trusted",
    "The vampire's kiss is not an invitation",
    "The wolf in sheep's clothing is not a shepherd",
    "The siren's song is not a lullaby",
    "The phoenix's fire is not a campfire",
    "The basilisk's gaze is not a compliment"
};

// A bewildering array of patterns
const char* patterns[] = {
    "^[a-zA-Z0-9]+$",
    "^[-a-zA-Z0-9@#$%^&*()_]+$",
    "^[a-zA-Z0-9]{8,16}$",
    "^[a-zA-Z0-9]{8,16}[!@#$%^&*()_]+$",
    "^[a-zA-Z0-9]{3,8}$",
    "^[a-zA-Z0-9]{3,8}[!@#$%^&*()_]+$",
    "^[a-zA-Z0-9]{1,8}$",
    "^[a-zA-Z0-9]{1,8}[!@#$%^&*()_]+$",
    "^[()<>\\[\\]{}]+$",
    "^[!~@#$%^&*()_-]+$"
};

// An enigmatic function to check for patterns
int check_pattern(const char* pattern, const char* input) {
    int matches = 0;
    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < strlen(pattern); j++) {
            if (input[i] == pattern[j]) {
                matches++;
            }
        }
    }
    return matches;
}

// A mystifying function to check for rules
int check_rule(const char* rule, const char* input) {
    int violations = 0;
    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < strlen(rule); j++) {
            if (input[i] == rule[j]) {
                violations++;
            }
        }
    }
    return violations;
}

// A labyrinthine function to process packets
void* process_packet(void* arg) {
    char* packet = (char*)arg;
    int matches = 0;
    int violations = 0;
    for (int i = 0; i < strlen(packet); i++) {
        for (int j = 0; j < 10; j++) {
            matches += check_pattern(patterns[j], packet);
            violations += check_rule(rules[j], packet);
        }
    }
    if (matches > 5 || violations > 3) {
        printf("\n***************************************\n");
        printf("Intrusion detected: Packet discarded\n");
        printf("***************************************\n\n");
    }
    free(packet);
    return NULL;
}

// The enigmatic main function
int main() {
    // Create a socket to listen on
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(5555);
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Create a thread to process each packet
    pthread_t tid;
    while (1) {
        // Receive a packet
        char* packet = malloc(1024);
        socklen_t addr_len = sizeof(addr);
        if (recvfrom(sockfd, packet, 1024, 0, (struct sockaddr*)&addr, &addr_len) == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Create a thread to process the packet
        pthread_create(&tid, NULL, process_packet, packet);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
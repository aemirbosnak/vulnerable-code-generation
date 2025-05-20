//FormAI DATASET v1.0 Category: Firewall ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_LEN 50

typedef struct {
	char protocol[MAX_LEN];
	char sourceIP[MAX_LEN];
	char sourcePort[MAX_LEN];
	char destIP[MAX_LEN];
	char destPort[MAX_LEN];
} Rule;

int numRules = 0;
Rule rules[MAX_RULES];

int checkPacket(char* protocol, char* sourceIP, char* sourcePort, char* destIP, char* destPort) {
	for (int i = 0; i < numRules; i++) {
		if (strcmp(protocol, rules[i].protocol) == 0 &&
			(strcmp(sourceIP, rules[i].sourceIP) == 0 || strcmp(rules[i].sourceIP, "*") == 0) &&
			(strcmp(sourcePort, rules[i].sourcePort) == 0 || strcmp(rules[i].sourcePort, "*") == 0) &&
			(strcmp(destIP, rules[i].destIP) == 0 || strcmp(rules[i].destIP, "*") == 0) &&
			(strcmp(destPort, rules[i].destPort) == 0 || strcmp(rules[i].destPort, "*") == 0)) {
			return 1; // packet is allowed
		}
	}
	return 0; // packet is not allowed
}

int main() {
	char input[MAX_LEN];

	while (1) {
		printf("Enter a rule (or exit to quit): ");
		scanf("%s", input);
		if (strcmp(input, "exit") == 0) {
			break;
		}
		char* protocol = strtok(input, ",");
		char* sourceIP = strtok(NULL, ",");
		char* sourcePort = strtok(NULL, ",");
		char* destIP = strtok(NULL, ",");
		char* destPort = strtok(NULL, ",");
		Rule rule;
		strcpy(rule.protocol, protocol);
		strcpy(rule.sourceIP, sourceIP);
		strcpy(rule.sourcePort, sourcePort);
		strcpy(rule.destIP, destIP);
		strcpy(rule.destPort, destPort);
		rules[numRules++] = rule;
	}

	char packet[MAX_LEN];
	strcpy(packet, "tcp,192.168.1.1,80,192.168.2.2,443");
	if (checkPacket(strtok(packet, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","))) {
		printf("Packet allowed.\n");
	} else {
		printf("Packet NOT allowed.\n");
	}
	
	return 0;
}
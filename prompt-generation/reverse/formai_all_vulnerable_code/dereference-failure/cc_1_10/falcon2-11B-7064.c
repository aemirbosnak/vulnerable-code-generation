//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_IP_SIZE 32
#define MAX_PORT_SIZE 6
#define MAX_ACTION_SIZE 100

// Define the allowed IP addresses
char* allowed_ips[MAX_IP_SIZE] = {
	"192.168.0.1", // Add more IP addresses here
};

// Define the allowed port numbers
int allowed_ports[MAX_PORT_SIZE] = {
	80, // Add more port numbers here
};

// Define the allowed actions
char* allowed_actions[MAX_ACTION_SIZE] = {
	"allow", // Add more actions here
};

// Function to check if an IP address is in the allowed list
int check_ip_address(char* ip) {
	int i;

	for (i = 0; i < MAX_IP_SIZE; i++) {
		if (strcmp(ip, allowed_ips[i]) == 0) {
			return 1;
		}
	}

	return 0;
}

// Function to check if a port number is in the allowed list
int check_port_number(int port) {
	int i;

	for (i = 0; i < MAX_PORT_SIZE; i++) {
		if (port == allowed_ports[i]) {
			return 1;
		}
	}

	return 0;
}

// Function to check if an action is in the allowed list
int check_action(char* action) {
	int i;

	for (i = 0; i < MAX_ACTION_SIZE; i++) {
		if (strcmp(action, allowed_actions[i]) == 0) {
			return 1;
		}
	}

	return 0;
}

// Function to parse command line arguments
int parse_args(int argc, char** argv) {
	int i, j;

	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0) {
			i++;
			for (j = 0; j < MAX_IP_SIZE; j++) {
				if (strcmp(argv[i], allowed_ips[j]) == 0) {
					return j;
				}
			}
		} else if (strcmp(argv[i], "-p") == 0) {
			i++;
			for (j = 0; j < MAX_PORT_SIZE; j++) {
				if (argv[i][0] == '0' && atoi(argv[i]) == allowed_ports[j]) {
					return j;
				}
			}
		} else if (strcmp(argv[i], "-a") == 0) {
			i++;
			for (j = 0; j < MAX_ACTION_SIZE; j++) {
				if (strcmp(argv[i], allowed_actions[j]) == 0) {
					return j;
				}
			}
		}
	}

	return -1;
}

int main(int argc, char** argv) {
	int i, j;
	int action = parse_args(argc, argv);

	if (action >= 0) {
		char ip[MAX_IP_SIZE];
		int port;
		char action[MAX_ACTION_SIZE];

		if (argc > action) {
			fgets(ip, MAX_IP_SIZE, stdin);
			sscanf(ip, "%d", &port);
			fgets(action, MAX_ACTION_SIZE, stdin);

			if (check_ip_address(ip) && check_port_number(port) && check_action(action)) {
				printf("Connection allowed.\n");
			} else {
				printf("Connection denied.\n");
			}
		} else {
			printf("Error: missing arguments.\n");
		}
	} else {
		printf("Error: invalid arguments.\n");
	}

	return 0;
}
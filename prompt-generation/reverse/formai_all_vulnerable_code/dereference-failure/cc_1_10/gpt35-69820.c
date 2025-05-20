//FormAI DATASET v1.0 Category: Firewall ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This is an exciting example of a C Firewall! 
 * With the power of this program, you can control the flow of data in and out of your computer.
 * Whether it's blocking unwanted traffic or allowing access to authorized applications, this firewall does it all!
 */

int main(int argc, char **argv) {
    char input[256]; // buffer for user input
    int port; // the port number to block or allow
    int action; // 1 = allow, 0 = block
    FILE *config; // file pointer for config file

    // read in configuration file
    config = fopen("firewall.conf", "r");
    if (config == NULL) {
        printf("Error opening configuration file!\n");
        exit(1);
    }

    // display welcome message

    printf("Welcome to the C Firewall!\n");
    printf("======================================\n");

    // read user input and parse commands
    while (1) {
        printf("\nEnter command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // parse input string into parts
        char *token = strtok(input, " ");

        // check for exit command
        if (strcmp(token, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // check for allow command
        if (strcmp(token, "allow") == 0) {
            token = strtok(NULL, " ");
            port = atoi(token);

            // add port to allow list in config file
            fprintf(config, "allow %d\n", port);

            printf("Port %d has been added to the allow list.\n", port);
        }

        // check for block command
        if (strcmp(token, "block") == 0) {
            token = strtok(NULL, " ");
            port = atoi(token);

            // add port to block list in config file
            fprintf(config, "block %d\n", port);

            printf("Port %d has been added to the block list.\n", port);
        }

        // check for status command
        if (strcmp(token, "status") == 0) {
            token = strtok(NULL, " ");
            port = atoi(token);

            // check if port is allowed or blocked
            action = check_port_status(port);

            if (action) {
                printf("Port %d is allowed.\n", port);
            } else {
                printf("Port %d is blocked.\n", port);
            }
        }

        // display help message
        if (strcmp(token, "help") == 0) {
            printf("Commands:\n");
            printf("allow [port] - add port to allow list\n");
            printf("block [port] - add port to block list\n");
            printf("status [port] - check if port is allowed or blocked\n");
            printf("exit - quit program\n");
        }
    }

    return 0;
}

/* check_port_status - check if specified port is allowed or blocked
 * param port: the port number to check
 * return: 1 = allow, 0 = block
 */
int check_port_status(int port) {
    FILE *config;
    char line[256];
    char *token;
    int action;

    config = fopen("firewall.conf", "r");

    // read each line of config file and check if port is allowed or blocked
    while (fgets(line, sizeof(line), config)) {
        token = strtok(line, " ");
        if (strcmp(token, "allow") == 0) {
            token = strtok(NULL, " ");
            if (atoi(token) == port) {
                action = 1;
                break;
            }
        } else if (strcmp(token, "block") == 0) {
            token = strtok(NULL, " ");
            if (atoi(token) == port) {
                action = 0;
                break;
            }
        }
    }

    fclose(config);

    return action;
}
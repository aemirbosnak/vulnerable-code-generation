//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define LOG_FILE "log.txt"
#define CONFIG_FILE "config.ini"
#define MAX_IP_LENGTH 16
#define MAX_LINE_LENGTH 100

// Structs
typedef struct Config {
    char ip[MAX_IP_LENGTH];
    int port;
    int block_duration;
} Config;

// Global variables
Config config;

// Function declarations
void read_config_file();
void log_info(char* message);
void log_warning(char* message);
void log_error(char* message);
void block_ip(char* ip);

int main() {
    // Read configuration file
    read_config_file();

    // Listen for incoming connections
    while (1) {
        char msg[MAX_LINE_LENGTH];
        scanf("%s", msg);

        // Check for potential attack
        if (strstr(msg, "drop") != NULL) {
            log_warning("Potential attack detected");
            block_ip(config.ip);
        }
    }

    return 0;
}

void read_config_file() {
    FILE* file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        log_error("Cannot open configuration file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* name = strtok(line, "=");
        char* value = strtok(NULL, "=");

        if (strcmp(name, "ip") == 0) {
            strncpy(config.ip, value, MAX_IP_LENGTH);
        } else if (strcmp(name, "port") == 0) {
            config.port = atoi(value);
        } else if (strcmp(name, "block_duration") == 0) {
            config.block_duration = atoi(value);
        }
    }

    fclose(file);
    log_info("Configuration file loaded");
}

void log_info(char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    fprintf(file, "[INFO] %s\n", message);
    fclose(file);
}

void log_warning(char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    fprintf(file, "[WARNING] %s\n", message);
    fclose(file);
}

void log_error(char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    fprintf(file, "[ERROR] %s\n", message);
    fclose(file);
}

void block_ip(char* ip) {
    char command[MAX_LINE_LENGTH];
    sprintf(command, "iptables -A INPUT -s %s -j DROP", ip);
    system(command);

    char message[MAX_LINE_LENGTH];
    sprintf(message, "%s blocked for %d seconds", ip, config.block_duration);
    log_warning(message);

    sleep(config.block_duration);

    sprintf(command, "iptables -D INPUT -s %s -j DROP", ip);
    system(command);

    sprintf(message, "%s unblocked", ip);
    log_warning(message);
}
//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

// Function to execute shell commands and capture their output
void exec_cmd(const char* cmd, char* output, size_t size) {
    FILE* fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", cmd);
        exit(EXIT_FAILURE);
    }
    
    fread(output, sizeof(char), size, fp);
    pclose(fp);
}

// Function to strip unnecessary whitespace from a string
void strip_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    if (*str == 0)  // All spaces?
        return;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

// Main function to scan networks
int main() {
    char output[4096];
    exec_cmd("iwlist scanning 2>/dev/null | grep -E 'Cell|ESSID|Quality|Encryption'", output, sizeof(output));

    char* line;
    char* save_ptr;
    line = strtok_r(output, "\n", &save_ptr);

    if (line == NULL) {
        printf("SHOCKING: No wireless networks found!\n");
        return 1;
    }

    printf("SHOCKING: Discovering wireless networks...\n");
    printf("=================================================================\n");

    while (line != NULL) {
        char ssid[100] = {0};
        char quality[50] = {0};
        char encryption[50] = {0};
        
        if (strstr(line, "Cell")) {
            printf("\n");
        }
        if ((line[0] == 'E') && (strstr(line, "ESSID"))) {
            sscanf(line, " ESSID:\"%[^\"]\"", ssid);
            strip_whitespace(ssid);
            printf("Network SSID: %s\n", ssid);
        }
        if ((line[0] == 'Q') && (strstr(line, "Quality"))) {
            sscanf(line, " Quality=%s", quality);
            strip_whitespace(quality);
            printf("Signal Quality: %s\n", quality);
        }
        if ((line[0] == 'E') && (strstr(line, "Encryption"))) {
            sscanf(line, " Encryption key:%s", encryption);
            strip_whitespace(encryption);
            printf("Encryption: %s\n", (strcmp(encryption, "on") == 0) ? "Enabled" : "Not Enabled");
        }
        line = strtok_r(NULL, "\n", &save_ptr);
    }

    printf("=================================================================\n");
    printf("SHOCKING: Scan completed! Are you ready to connect?\n");

    return 0;
}
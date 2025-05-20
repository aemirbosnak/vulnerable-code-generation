//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

// Function to execute system commands and return the output
char* execute_command(const char *cmd) {
    char buffer[128];
    char *result = malloc(1024); // Allocate memory for result
    result[0] = '\0'; // Initialize result to an empty string

    FILE *pipe = popen(cmd, "r");
    if (pipe == NULL) {
        perror("popen failed");
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        strcat(result, buffer);
    }

    pclose(pipe);
    return result;
}

// Function to parse the signal strength from the output
float parse_signal_strength(const char *output) {
    regex_t regex;
    regcomp(&regex, "Signal level=(-?\\d+) dBm", REG_EXTENDED);
    regmatch_t matches[2];

    if (regexec(&regex, output, 2, matches, 0) == 0) {
        char level[10];
        strncpy(level, output + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
        level[matches[1].rm_eo - matches[1].rm_so] = '\0';
        regfree(&regex);
        return atof(level);
    }

    regfree(&regex);
    return -999; // Return an invalid value if not found
}

// Function to analyze Wi-Fi signal strength
void analyze_wifi_signal() {
    const char *cmd = "iwconfig 2>/dev/null"; // Execute iwconfig command
    char *output = execute_command(cmd);

    if (output == NULL) {
        printf("Could not retrieve Wi-Fi signal strength.\n");
        return;
    }

    // Parse the output to find signal strength
    float signal_strength = parse_signal_strength(output);
    free(output); // Free the output buffer

    if (signal_strength == -999) {
        printf("No Wi-Fi information found.\n");
    } else {
        printf("Current Wi-Fi Signal Strength: %.2f dBm\n", signal_strength);
        if (signal_strength > -50) {
            printf("Excellent signal strength!\n");
        } else if (signal_strength > -70) {
            printf("Good signal strength.\n");
        } else if (signal_strength > -85) {
            printf("Weak signal strength.\n");
        } else {
            printf("Very weak signal strength. Consider moving closer to the router!\n");
        }
    }
}

// Main function
int main() {
    int refresh_rate = 5; // Refresh every 5 seconds
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("Monitoring signal strength every %d seconds...\n", refresh_rate);
  
    while (1) {
        analyze_wifi_signal();
        sleep(refresh_rate); // Wait for the defined refresh rate
    }

    return 0; // Return success
}
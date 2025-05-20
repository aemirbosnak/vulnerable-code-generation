//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 15
#define MAX_LINE_LEN 1000

int count_logs_with_ip_address(char *file_name, char *ip_address) {
    FILE *file = fopen(file_name, "r");
    char *line = malloc(MAX_LINE_LEN);
    char *ip;

    int count = 0;

    while (fgets(line, MAX_LINE_LEN, file)) {
        ip = strstr(line, ip_address);

        if (ip != NULL) {
            count++;
        }

        memset(line, 0, MAX_LINE_LEN);
    }

    fclose(file);
    free(line);

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid arguments. Usage: %s <logfile> <ip_address>", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *ip_address = argv[2];

    printf("Analyzing log file \"%s\" for connections from IP address \"%s\"...", file_name, ip_address);

    int num_logs = count_logs_with_ip_address(file_name, ip_address);

    if (num_logs == 0) {
        printf("\n\nNo connections found from IP address \"%s\".\n", ip_address);
        return 0;
    }

    printf("\n\n%d connections found from IP address \"%s\".\n", num_logs, ip_address);
    printf("\n\nPlease note: It is possible that this IP address is being used by a hacker to attempt to breach your system.\n");

    return 0;
}
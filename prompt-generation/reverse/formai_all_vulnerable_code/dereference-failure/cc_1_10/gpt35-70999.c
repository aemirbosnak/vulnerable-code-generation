//FormAI DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 500
#define MAX_IP 100

typedef struct {
    char ip[20];
    int visits;
} entry;

int main() {
    FILE *fp = fopen("access.log", "r");
    char line[MAX_LEN];
    char *token;
    char delimiter[] = " []\"\r\n";
    int count = 0;
    entry *ip_table = malloc(MAX_IP * sizeof(entry));
    int ip_count = 0;

    if (fp == NULL) {
        printf("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LEN, fp)) {
        token = strtok(line, delimiter); // get IP
        int found = 0;
        for (int i = 0; i < ip_count; i++) {
            if (strcmp(token, ip_table[i].ip) == 0) {
                ip_table[i].visits++;
                found = 1;
                break;
            }
        }
        if (!found) { // IP not found in table
            strcpy(ip_table[ip_count].ip, token);
            ip_table[ip_count].visits = 1;
            ip_count++;
        }
        
        count++; // count number of lines read
    }

    fclose(fp);

    printf("Total number of lines read: %d\n", count);
    printf("Number of unique IP addresses: %d\n", ip_count);
    printf("IP addresses and number of visits:\n");
    for (int i = 0; i < ip_count; i++) {
        printf("%s: %d\n", ip_table[i].ip, ip_table[i].visits);
    }

    free(ip_table);
    return 0;
}
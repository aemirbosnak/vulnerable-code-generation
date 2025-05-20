//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define TRUE 1
#define FALSE 0
#define PORT "80"
#define WIFI_STRENGTH_FILE "wifi_strength.txt"

typedef struct {
    char ip[16];
    int strength;
} wifi_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_DATA_SIZE];
    char *token;
    wifi_t *wifi;
    int i, count = 0;

    wifi = (wifi_t *) malloc(sizeof(wifi_t));

    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_DATA_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(wifi->ip, token);
        wifi->strength = atoi(strtok(NULL, ","));
        if (count == 0) {
            printf("IP Address\tSignal Strength\n");
            printf("-------------------------------------------------\n");
        }
        printf("%s\t\t%d\n", wifi->ip, wifi->strength);
        count++;
    }

    fclose(fp);

    return 0;
}
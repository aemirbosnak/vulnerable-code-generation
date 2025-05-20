//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_SSIDS 10

typedef struct {
    char ssid[32];
    int strength;
    time_t last_seen;
} SSID_t;

SSID_t ssids[MAX_SSIDS];
int num_ssids = 0;

void print_ssids() {
    printf("SSIDs:\n");
    for (int i = 0; i < num_ssids; i++) {
        printf("%s (%d): %s\n", ssids[i].ssid, ssids[i].strength, ctime(&ssids[i].last_seen));
    }
}

int compare_ssids(const void *a, const void *b) {
    SSID_t *ssid_a = (SSID_t *)a;
    SSID_t *ssid_b = (SSID_t *)b;

    if (ssid_a->strength > ssid_b->strength) {
        return -1;
    } else if (ssid_a->strength < ssid_b->strength) {
        return 1;
    } else {
        return 0;
    }
}

void update_ssid(char *ssid, int strength) {
    for (int i = 0; i < num_ssids; i++) {
        if (strcmp(ssid, ssids[i].ssid) == 0) {
            ssids[i].strength = strength;
            ssids[i].last_seen = time(NULL);
            return;
        }
    }

    if (num_ssids >= MAX_SSIDS) {
        return;
    }

    strcpy(ssids[num_ssids].ssid, ssid);
    ssids[num_ssids].strength = strength;
    ssids[num_ssids].last_seen = time(NULL);
    num_ssids++;

    qsort(ssids, num_ssids, sizeof(SSID_t), compare_ssids);
}

int main() {
    char input[1024];
    while (fgets(input, sizeof(input), stdin)) {
        char *ssid = strtok(input, " ");
        int strength = atoi(strtok(NULL, " "));
        update_ssid(ssid, strength);
    }

    print_ssids();

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SSID_MAX 32
#define PASSPHRASE_MAX 64
#define NETWORK_MAX 10

typedef struct {
    char ssid[SSID_MAX];
    char passphrase[PASSPHRASE_MAX];
} network_t;

network_t networks[NETWORK_MAX];
int num_networks = 0;

void add_network() {
    if (num_networks >= NETWORK_MAX) {
        printf("Error: Maximum number of networks reached.\n");
        return;
    }

    printf("Enter SSID: ");
    scanf("%s", networks[num_networks].ssid);

    printf("Enter passphrase: ");
    scanf("%s", networks[num_networks].passphrase);

    num_networks++;
}

void remove_network(int index) {
    if (index < 0 || index >= num_networks) {
        printf("Error: Invalid network index.\n");
        return;
    }

    memset(&networks[index], 0, sizeof(network_t));
    num_networks--;
}

void list_networks() {
    printf("Networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%d. %s (%s)\n", i+1, networks[i].ssid, networks[i].passphrase);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        printf("Commands:\n");
        printf("  add <SSID> <passphrase>\n");
        printf("  remove <index>\n");
        printf("  list\n");
        return 1;
    }

    char *command = argv[1];

    if (strcmp(command, "add") == 0) {
        if (argc < 4) {
            printf("Usage: %s add <SSID> <passphrase>\n", argv[0]);
            return 1;
        }
        add_network();
    } else if (strcmp(command, "remove") == 0) {
        if (argc < 3) {
            printf("Usage: %s remove <index>\n", argv[0]);
            return 1;
        }
        int index = atoi(argv[2]) - 1;
        remove_network(index);
    } else if (strcmp(command, "list") == 0) {
        list_networks();
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
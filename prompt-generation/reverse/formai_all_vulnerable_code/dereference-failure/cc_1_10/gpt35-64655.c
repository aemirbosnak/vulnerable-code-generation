//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define WIFI_INTERFACE "wlan0"
#define WIFI_PROC_FILE "/proc/net/wireless"

typedef struct {
    char ssid[32];
    int signal;
} ap_t;

typedef struct {
    ap_t* aps;
    int count;
} ap_list_t;

int get_wifi_signal(char* ssid);
ap_list_t* scan_wifi_networks();
void sort_networks_by_signal(ap_list_t* ap_list);
bool validate_mac_address_format(char* mac);

int main() {
    ap_list_t* ap_list = scan_wifi_networks();
    if (ap_list == NULL) {
        fprintf(stderr, "Could not scan wireless networks.\n");
        return 1;
    }

    sort_networks_by_signal(ap_list);

    printf("List of wifi networks sorted by signal strength:\n");
    printf("--------------------------------------------------\n");
    printf("%-32s %-8s\n", "SSID", "Signal");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < ap_list->count; i++) {
        printf("%-32s %-8d\n", ap_list->aps[i].ssid,
            ap_list->aps[i].signal);
    }

    free(ap_list->aps);
    free(ap_list);

    return 0;
}

int get_wifi_signal(char* ssid) {
    char path[64];
    char line[256];
    FILE* f;
    int signal;

    sprintf(path, "/proc/net/wireless");
    f = fopen(path, "r");

    if (f == NULL) {
        fprintf(stderr, "Could not open %s: %s\n", path, strerror(errno));
        return -999;
    }

    fgets(line, sizeof(line), f);
    fgets(line, sizeof(line), f);

    while (fgets(line, sizeof(line), f) != NULL) {
        char *tok = strtok(line, ":");
        if (strlen(tok) < 2)
            continue;

        char* ssid_token = strtok(NULL, ":");
        if (strlen(ssid_token) < 2)
            continue;

        if (strncmp(ssid_token + 1, ssid, strlen(ssid)) != 0)
            continue;

        char* signal_token = strtok(NULL, " ");
        if (strlen(signal_token) < 2)
            continue;

        signal = atoi(signal_token);

        fclose(f);

        return signal;
    }

    fclose(f);

    return -999;
}

ap_list_t* scan_wifi_networks() {
    DIR* dir;
    struct dirent* ent;
    FILE* f;
    char path[64];
    char line[256];
    ap_list_t* ap_list = NULL;
    ap_t* aps;
    int ap_count = 0;

    dir = opendir("/sys/class/net");
    if (dir == NULL) {
        fprintf(stderr, "Could not open directory /sys/class/net: %s\n",
            strerror(errno));
        return NULL;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, WIFI_INTERFACE) == 0) {
            sprintf(path, "/sys/class/net/%s/wireless/phy%d/device/net",
                WIFI_INTERFACE, 0);

            dir = opendir(path);
            if (dir == NULL) {
                fprintf(stderr, "Could not open directory %s: %s\n",
                    path, strerror(errno));
                return NULL;
            }

            while ((ent = readdir(dir)) != NULL) {
                if (strcmp(ent->d_name, "..") == 0 ||
                    strcmp(ent->d_name, ".") == 0)
                    continue;

                memset(path, 0, sizeof(path));
                snprintf(path, sizeof(path), "/sys/class/net/%s/wireless/%s"
                    "/device/net/%s/address", WIFI_INTERFACE, ent->d_name,
                    ent->d_name);

                f = fopen(path, "r");
                if (f != NULL) {
                    memset(line, 0, sizeof(line));
                    fgets(line, sizeof(line), f);
                    fclose(f);

                    if (!validate_mac_address_format(line))
                        continue;

                    char ssid[32];
                    sprintf(path, "/proc/net/dev");
                    f = fopen(path, "r");
                    if (f != NULL) {
                        fgets(line, sizeof(line), f);
                        fgets(line, sizeof(line), f);

                        while (fgets(line, sizeof(line), f) != NULL) {
                            char* tok = strtok(line, ":");
                            if (strlen(tok) < 2)
                                continue;

                            char* ssid_token = strtok(NULL, ":");
                            if (strlen(ssid_token) < 2)
                                continue;

                            sscanf(ssid_token + 1, "%[^ ]", ssid);

                            aps = realloc(aps, (ap_count + 1) * sizeof(ap_t));
                            strncpy(aps[ap_count].ssid, ssid, sizeof(aps[ap_count].ssid) - 1);
                            aps[ap_count].signal = get_wifi_signal(ssid);

                            ap_count++;
                        }

                        fclose(f);
                    }
                }
            }

            closedir(dir);

            ap_list = malloc(sizeof(ap_list_t));
            ap_list->aps = aps;
            ap_list->count = ap_count;

            return ap_list;
        }
    }

    closedir(dir);

    fprintf(stderr, "Could not find wifi interface %s\n", WIFI_INTERFACE);

    return NULL;
}

void sort_networks_by_signal(ap_list_t* ap_list) {
    ap_t temp;

    for (int i = 0; i < ap_list->count; i++) {
        for (int j = i + 1; j < ap_list->count; j++) {
            if (ap_list->aps[i].signal < ap_list->aps[j].signal) {
                temp = ap_list->aps[i];
                ap_list->aps[i] = ap_list->aps[j];
                ap_list->aps[j] = temp;
            }
        }
    }
}

bool validate_mac_address_format(char* mac) {
    int len = strlen(mac);
    int count = 0;

    if (len != 17)
        return false;

    for (int i = 0; i < len; i++) {
        if (i % 3 == 2) {
            if (mac[i] != ':')
                return false;
            count++;
        } else if ((mac[i] >= '0' && mac[i] <= '9') ||
                   (mac[i] >= 'a' && mac[i] <= 'f') ||
                   (mac[i] >= 'A' && mac[i] <= 'F')) {
            continue;
        } else {
            return false;
        }
    }

    if (count != 5)
        return false;

    return true;
}
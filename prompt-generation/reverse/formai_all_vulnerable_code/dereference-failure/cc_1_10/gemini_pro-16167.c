//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <net/if.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <time.h>

#define ETHTOOL_GET_LINK "ethtool %s ethtool_glinkinfo"

#define TRUE 1
#define FALSE 0

static volatile int g_exit_flag = FALSE;

static void signal_handler(int signal) {
    g_exit_flag = TRUE;
}

static int get_link_status(char *interface) {
    FILE *fp;
    char command[256];
    char buffer[256];

    sprintf(command, ETHTOOL_GET_LINK, interface);
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: popen() failed: %s\n", strerror(errno));
        return -1;
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, "Link detected: no") != NULL) {
            pclose(fp);
            return FALSE;
        }
        if (strstr(buffer, "Link detected: yes") != NULL) {
            pclose(fp);
            return TRUE;
        }
    }
    pclose(fp);
    return -1;
}

static int get_signal_strength(char *interface) {
    FILE *fp;
    char command[256];
    char buffer[256];

    sprintf(command, ETHTOOL_GET_LINK, interface);
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: popen() failed: %s\n", strerror(errno));
        return -1;
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, "Signal level:") != NULL) {
            char *p = strstr(buffer, "Signal level:");
            p = strchr(p, ':');
            p++;
            while (*p == ' ') {
                p++;
            }
            pclose(fp);
            return atoi(p);
        }
    }
    pclose(fp);
    return -1;
}

static void print_usage(char *program_name) {
    printf("Usage: %s <interface>\n", program_name);
    printf("Example: %s wlan0\n", program_name);
}

int main(int argc, char *argv[]) {
    char *interface;
    int link_status;
    int signal_strength;
    time_t last_update_time;

    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    interface = argv[1];

    signal(SIGINT, signal_handler);

    last_update_time = time(NULL);

    while (!g_exit_flag) {
        link_status = get_link_status(interface);
        if (link_status == FALSE) {
            printf("Wi-Fi link is down.\n");
        } else if (link_status == TRUE) {
            printf("Wi-Fi link is up.\n");
            signal_strength = get_signal_strength(interface);
            if (signal_strength == -1) {
                printf("Error: Failed to get Wi-Fi signal strength.\n");
            } else {
                printf("Wi-Fi signal strength: %d dBm\n", signal_strength);
            }
        } else {
            printf("Error: Failed to get Wi-Fi link status.\n");
        }

        time_t current_time = time(NULL);
        if (current_time - last_update_time >= 1) {
            last_update_time = current_time;
        }
    }

    return EXIT_SUCCESS;
}
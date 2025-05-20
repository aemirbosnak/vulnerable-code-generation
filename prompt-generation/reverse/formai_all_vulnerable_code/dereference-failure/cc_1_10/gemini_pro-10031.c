//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <arpa/inet.h>

struct wifi_data {
    char    interface_name[32];
    char    ssid[32];
    int     strength;
};

/*
 * Desc:   Parse the output of the "iwlist" command to extract the signal strength
 *         data for the specified interface.
 *
 * Args:   interface_name - the name of the wireless interface to parse data for
 *         data - a pointer to the wifi_data structure to populate with the parsed data
 *
 * Returns: true if the signal strength data was successfully parsed, false otherwise
 */
bool parse_iwlist_output(const char *interface_name, struct wifi_data *data)
{
    char    command[256];
    char    line[256];
    FILE    *fp;
    char    *p;
    char    *s;
    int     found_signal_strength = 0;
    bool    found_ssid = 0;
    bool    found_interface = 0;

    /* Build the command to execute */
    snprintf(command, sizeof(command), "iwlist %s scan", interface_name);

    /* Execute the command and open the output stream */
    if ((fp = popen(command, "r")) == NULL) {
        perror("popen");
        return false;
    }

    /* Parse the output of the command */
    while (fgets(line, sizeof(line), fp) != NULL) {
        /* Check if the line contains the SSID */
        if (strncmp(line, "ESSID:\"", strlen("ESSID:\"")) == 0) {
            /* Check if the value is wrapped in quotes */
            if (line[strlen(line) - 1] == '"') {
                line[strlen(line) - 1] = '\0';
            }

            /* Extract the SSID */
            s = line + strlen("ESSID:\"");
            strncpy(data->ssid, s, sizeof(data->ssid) - 1);
            data->ssid[sizeof(data->ssid) - 1] = '\0';

            found_ssid = true;
        }

        /* Check if the line contains the signal strength */
        if (strncmp(line, "Signal level:", strlen("Signal level:")) == 0) {
            /* Check if the value is wrapped in quotes */
            if (line[strlen(line) - 1] == 'd') {
                line[strlen(line) - 1] = '\0';
            }

            /* Extract the signal strength */
            p = strstr(line, "=");
            if (p != NULL) {
                p++;
                data->strength = atoi(p);
                found_signal_strength = true;
            }
        }

        /* Check if the line contains the interface name */
        if (strncmp(line, "Interface ", strlen("Interface ")) == 0) {
            /* Check if the value is wrapped in quotes */
            if (line[strlen(line) - 1] == '\n') {
                line[strlen(line) - 1] = '\0';
            }

            /* Extract the interface name */
            s = line + strlen("Interface ");
            strncpy(data->interface_name, s, sizeof(data->interface_name) - 1);
            data->interface_name[sizeof(data->interface_name) - 1] = '\0';

            found_interface = true;
        }

        /* Check if we have found all the data we need */
        if (found_signal_strength && found_ssid && found_interface) {
            break;
        }
    }

    /* Close the output stream */
    pclose(fp);

    /* Return true if we found all the data we need */
    return (found_signal_strength && found_ssid && found_interface);
}

/*
 * Desc:   Print the signal strength data for the specified interface.
 *
 * Args:   interface_name - the name of the wireless interface to print data for
 *         data - a pointer to the wifi_data structure containing the parsed data
 */
void print_data(const char *interface_name, struct wifi_data *data)
{
    printf("Interface: %s\n", interface_name);
    printf("SSID: %s\n", data->ssid);
    printf("Strength: %d\n", data->strength);
}

int main(int argc, char **argv)
{
    char            interface_name[32];
    struct wifi_data data;

    /* Get the interface name from the command line */
    if (argc < 2) {
        printf("Usage: %s <interface_name>\n", argv[0]);
        return EXIT_FAILURE;
    }
    strncpy(interface_name, argv[1], sizeof(interface_name) - 1);
    interface_name[sizeof(interface_name) - 1] = '\0';

    /* Parse the iwlist output */
    if (!parse_iwlist_output(interface_name, &data)) {
        printf("Error: could not parse iwlist output\n");
        return EXIT_FAILURE;
    }

    /* Print the signal strength data */
    print_data(interface_name, &data);

    return EXIT_SUCCESS;
}
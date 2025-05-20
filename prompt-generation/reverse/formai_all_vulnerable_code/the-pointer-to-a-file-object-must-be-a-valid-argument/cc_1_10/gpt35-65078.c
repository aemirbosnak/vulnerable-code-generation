//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ssid[100], cmd[200];
    int signal_strength, num_networks, i;

    printf("Enter the name of the Wi-Fi network (SSID): ");
    scanf("%s", ssid);

    sprintf(cmd, "sudo iwlist wlan0 scan | grep -ioE '\"%s\".*(-[0-9]+)+.*dBm' | awk '{print $NF}'", ssid);

    FILE *fp;
    char output[10];
    fp = popen(cmd, "r");
    fgets(output, sizeof(output), fp);
    pclose(fp);

    if(strcmp(output, "") == 0)
    {
        printf("\nCould not find the specified network. Please try again.\n");
        return 0;
    }

    signal_strength = atoi(output);
    printf("\nThe signal strength of %s is %ddBm.\n", ssid, signal_strength);

    printf("\nWould you like to get signal strengths of other nearby networks? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if(choice == 'y')
    {
        sprintf(cmd, "sudo iwlist wlan0 scan | grep -ioE 'ssid:\".*\"|signal level.*dBm'");

        fp = popen(cmd, "r");
        num_networks = 0;

        char network[20], level[10];
        int strength;

        printf("\n\n%-20s %-10s\n", "Network", "Strength");
        printf("----------------------------------------------\n");

        while(fgets(output, sizeof(output), fp))
        {
            if(strncmp(output, "SSID", 4) == 0)
            {
                num_networks++;
                strcpy(network, output+6);
                network[strlen(network)-2] = '\0';
            }
            else if(strncmp(output, "Signal", 6) == 0)
            {
                strncpy(level, output+20, strlen(output)-21);
                level[strlen(level)-2] = '\0';
                strength = atoi(level);
                printf("%-20s %-10d\n", network, strength);
            }
        }

        pclose(fp);

        if(num_networks == 0)
            printf("No networks found.\n");
        else
            printf("\nNumber of networks found: %d\n", num_networks);
    }

    return 0;
}
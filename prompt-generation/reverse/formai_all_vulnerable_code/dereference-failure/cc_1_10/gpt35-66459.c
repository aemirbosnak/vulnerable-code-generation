//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

/* Signal handler for SIGINT and SIGTERM */
static void sig_handler(int sig)
{
    printf("\nReceived signal %d. Exiting...\n", sig);
    exit(0);
}

/* Main function */
int main(int argc, char *argv[])
{
    /* Install signal handler for SIGINT and SIGTERM */
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    /* Variables */
    char *ip_address;
    int port_number;
    FILE *fp;
    char line[256];
    int packets_sent = 0;
    int packets_received = 0;
    int lost_packets = 0;
    float packet_loss_percentage;

    /* Check command line arguments */
    if (argc != 3)
    {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    /* Get IP address and port number from command line arguments */
    ip_address = argv[1];
    port_number = atoi(argv[2]);

    /* Open pipe to ping command */
    fp = popen("ping -c 10 -i 0.2 -q -n -W 1 -p 0000", "r");
    if (fp == NULL)
    {
        printf("Error opening pipe to ping command.\n");
        return 1;
    }

    /* Read output from ping command */
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        /* Extract packet loss percentage from output */
        if (strstr(line, "packet loss"))
        {
            sscanf(line, "%d packets transmitted, %d received, %d%% packet loss",
                &packets_sent, &packets_received, &lost_packets);
        }
    }

    /* Calculate packet loss percentage */
    packet_loss_percentage = (float) lost_packets * 100 / packets_sent;

    /* Close pipe */
    pclose(fp);

    /* Print results */
    printf("IP address: %s\n", ip_address);
    printf("Port number: %d\n", port_number);
    printf("Packets sent: %d\n", packets_sent);
    printf("Packets received: %d\n", packets_received);
    printf("Packet loss: %d (%.2f%%)\n", lost_packets, packet_loss_percentage);

    return 0;
}
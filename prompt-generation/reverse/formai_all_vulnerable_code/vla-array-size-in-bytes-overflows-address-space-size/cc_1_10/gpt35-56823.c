//FormAI DATASET v1.0 Category: Firewall ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the structure to store the packet details
struct Packet {
    int source_port;
    char source_ip[20];
    int destination_port;
    char destination_ip[20];
};

int main() {
    FILE *fp; //File pointer
    char packet_file[50]; //Packet file name
    printf("Enter the name of the packet file: ");
    scanf("%s", packet_file);
    fp = fopen(packet_file, "r"); //Opening the packet file in read mode
    if(fp == NULL) { //Checking if file exists or not
        printf("File does not exist!\n");
        exit(0);
    }
    int num_of_packets; //Number of packets present in the file
    fscanf(fp, "%d", &num_of_packets);
    struct Packet packets[num_of_packets]; //Array of packets
    for(int i=0; i<num_of_packets; i++) {
        fscanf(fp, "%d", &packets[i].source_port);
        fscanf(fp, "%s", packets[i].source_ip);
        fscanf(fp, "%d", &packets[i].destination_port);
        fscanf(fp, "%s", packets[i].destination_ip);
    }
    fclose(fp); //Closing the packet file

    int port_count[65536] = {0}; //Array to store the count of packets sent to each port
    char ip_list[100][20]; //2D array to store unique IP addresses
    int ip_count = 0; //Number of unique IP addresses
    for(int i=0; i<num_of_packets; i++) {
        port_count[packets[i].destination_port]++; //Incrementing count for the port
        int flag = 1;
        for(int j=0; j<ip_count; j++) {
            if(strcmp(ip_list[j], packets[i].source_ip) == 0) { //Checking if IP address already exists
                flag = 0;
                break;
            }
        }
        if(flag) { //If IP address does not exist, add it to the list of unique IP addresses
            strcpy(ip_list[ip_count], packets[i].source_ip);
            ip_count++;
        }
    }

    printf("\nFirewall Statistics\n");
    printf("--------------------\n");
    printf("Total number of packets processed: %d\n", num_of_packets);
    printf("Number of unique IP addresses: %d\n", ip_count);
    printf("Ports and number of packets received at each port:\n");
    for(int i=0; i<65536; i++) {
        if(port_count[i] != 0) {
            printf("%d: %d packets\n", i, port_count[i]);
        }
    }

    return 0;
}
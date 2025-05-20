//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

//-------------WIRELESS NETWORK SCANNER-------------------//

//Function to randomly generate MAC address for access points
void generate_mac_address(char* s) {
    const char hex[] = "0123456789ABCDEF";
    int i;
    for(i=0;i<17;++i) {
        if(i==2 || i==5 || i==8 || i==11 || i==14) {
            s[i]=':';
        } else {
            s[i]=hex[rand()%16];
        }
    }
    s[i]='\0';
}

//Function to display the nearby Wi-Fi networks and their details
void display_wifi_networks(char** ssid_list, char** bssid_list, int* signal_strength_list, int num_networks) {
    printf("\n------Wi-Fi Networks Found------\n\n");
    printf("SSID\t\tBSSID\t\tSIGNAL STRENGTH\n");
    printf("-----\t\t-----\t\t---------------\n");

    int i;
    for(i=0;i<num_networks;++i) {
        printf("%-16s%-18s%-4d dBm\n",ssid_list[i],bssid_list[i],signal_strength_list[i]);
    }

    printf("\n------------------------------\n");
}

//Function to scan for nearby Wi-Fi networks and store their details
void scan_wifi_networks(char*** ssid_list, char*** bssid_list, int** signal_strength_list, int* num_networks) {
    int max_num_networks=20;
    *num_networks=0;

    *ssid_list=(char**)malloc(sizeof(char*)*max_num_networks);
    *bssid_list=(char**)malloc(sizeof(char*)*max_num_networks);
    *signal_strength_list=(int*)malloc(sizeof(int)*max_num_networks);

    time_t t;
    srand((unsigned) time(&t));

    int i;
    for(i=0;i<max_num_networks;++i) {
        char* ssid=(char*)malloc(sizeof(char)*25);
        sprintf(ssid,"Network%d",i+1);
        (*ssid_list)[i]=ssid;

        char* bssid=(char*)malloc(sizeof(char)*18);
        generate_mac_address(bssid);
        (*bssid_list)[i]=bssid;

        (*signal_strength_list)[i]=-rand()%21-50;
    }

    *num_networks=max_num_networks;
}

int main() {
    char** ssid_list;
    char** bssid_list;
    int* signal_strength_list;
    int num_networks=0;

    int choice;
    do {
        printf("\n######### WLAN Scanner #########\n");
        printf("# 1. Scan wireless networks     #\n");
        printf("# 2. Display Wi-Fi networks     #\n");
        printf("# 3. Exit                       #\n");
        printf("#################################\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: scan_wifi_networks(&ssid_list,&bssid_list,&signal_strength_list,&num_networks);
                    break;

            case 2: if(num_networks>0) {
                        display_wifi_networks(ssid_list,bssid_list,signal_strength_list,num_networks);
                    } else {
                        printf("\nNo Wi-Fi networks found. Please scan for networks first.\n");
                    }
                    break;

            case 3: printf("\nExiting the program. Thank you for using WLAN Scanner.\n");
                    break;

            default: printf("\nInvalid choice. Please enter a valid choice.\n");
        }

    } while(choice!=3);

    int i;
    for(i=0;i<num_networks;++i) {
        free(ssid_list[i]);
        free(bssid_list[i]);
    }

    free(ssid_list);
    free(bssid_list);
    free(signal_strength_list);

    return 0;
}
//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct access_point{
    char *ssid;
    char *bssid;
    int channel;
    float signal_strength;
    struct access_point *next;
};

void add_access_point(struct access_point **list, char *ssid, char *bssid, int channel, float signal_strength){
    struct access_point *new_entry = (struct access_point*)malloc(sizeof(struct access_point));
    new_entry->ssid = strdup(ssid);
    new_entry->bssid = strdup(bssid);
    new_entry->channel = channel;
    new_entry->signal_strength = signal_strength;
    new_entry->next = NULL;
    if(*list == NULL){
        *list = new_entry;
        return;
    }
    struct access_point *temp = *list;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_entry;
}

void clear_access_points(struct access_point **list){
    if(*list == NULL){
        return;
    }
    struct access_point *temp = *list;
    struct access_point *next;
    while(temp != NULL){
        next = temp->next;
        free(temp->ssid);
        free(temp->bssid);
        free(temp);
        temp = next;
    }
    *list = NULL;
}

void print_access_points(struct access_point *list){
    if(list == NULL){
        printf("No available access points\n");
        return;
    }
    printf("SSID\t\tBSSID\t\t\t\tChannel\tSignal Strength\n");
    while(list != NULL){
        printf("%s\t%s\t\t%d\t%.1f dBm\n", list->ssid, list->bssid, list->channel, list->signal_strength);
        list = list->next;
    }
}

int main(){
    struct access_point *access_points = NULL;
    int option;
    do{
        printf("1. Scan for available networks\n2. Clear results\n3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option){
            case 1:{
                // Code for scanning wireless networks goes here
                // Sample data, replace with actual results
                add_access_point(&access_points, "MyWiFi", "12:34:56:78:90:ab", 6, -67.2);
                add_access_point(&access_points, "Neighbor's WiFi", "de:ad:be:ef:12:34", 1, -82.7);
                add_access_point(&access_points, "OpenWiFi", "ff:ff:ff:ff:ff:ff", 11, -50.5);
                print_access_points(access_points);
                break;
            }
            case 2:{
                clear_access_points(&access_points);
                printf("Results cleared\n");
                break;
            }
            case 3:{
                clear_access_points(&access_points);
                printf("Exiting program\n");
                break;
            }
            default:{
                printf("Invalid option\n");
                break;
            }
        }
    }while(option != 3);
    return 0;
}
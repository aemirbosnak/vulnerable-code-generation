//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

/* Structure to hold network device information */
struct network_device
{
    char device_name[20];
    char ip_address[20];
    char mac_address[20];
    char connected_devices[MAX][20];
    int num_of_connected_devices;
};

/* Function to add connected devices to a network device */
void add_device(struct network_device *device, char *new_device)
{
    int i;
    for(i=0;i<device->num_of_connected_devices;i++)
    {
        if(strcmp(device->connected_devices[i], new_device)==0)
        {
            return;
        }
    }
    strcpy(device->connected_devices[device->num_of_connected_devices], new_device);
    device->num_of_connected_devices++;
}

int main()
{
    int num_of_devices, i, j;
    printf("Enter the number of devices: ");
    scanf("%d", &num_of_devices);

    struct network_device devices[num_of_devices];

    /* Input device information */
    for(i=0;i<num_of_devices;i++)
    {
        printf("Device %d name: ", i+1);
        scanf("%s", devices[i].device_name);
        printf("IP Address: ");
        scanf("%s", devices[i].ip_address);
        printf("MAC Address: ");
        scanf("%s", devices[i].mac_address);
        devices[i].num_of_connected_devices = 0;
    }

    /* Input connected device information */
    for(i=0;i<num_of_devices;i++)
    {
        printf("Enter the number of devices %s is connected to: ", devices[i].device_name);
        int num;
        scanf("%d", &num);
        for(j=0;j<num;j++)
        {
            char temp_device[20];
            printf("Enter the name of device %d: ", j+1);
            scanf("%s", temp_device);
            add_device(&devices[i], temp_device);
        }
    }

    /* Print information about all devices */
    for(i=0;i<num_of_devices;i++)
    {
        printf("\nDevice name: %s\n", devices[i].device_name);
        printf("IP Address: %s\n", devices[i].ip_address);
        printf("MAC Address: %s\n", devices[i].mac_address);
        printf("Connected Devices:\n");
        for(j=0;j<devices[i].num_of_connected_devices;j++)
        {
            printf("\t%s\n", devices[i].connected_devices[j]);
        }
    }

    return 0;
}
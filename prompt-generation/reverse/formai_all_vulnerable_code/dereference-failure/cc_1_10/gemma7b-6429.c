//Gemma-7B DATASET v1.0 Category: Smart home automation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ Devices 10

typedef struct Device
{
  char name[20];
  int state;
  struct Device *next;
} Device;

Device *deviceList = NULL;

void addDevice(char *name, int state)
{
  Device *newNode = malloc(sizeof(Device));
  strcpy(newNode->name, name);
  newNode->state = state;
  newNode->next = deviceList;
  deviceList = newNode;
}

void controlDevice(char *name, int state)
{
  Device *device = deviceList;
  while (device)
  {
    if (strcmp(device->name, name) == 0)
    {
      device->state = state;
      printf("Device %s is now in state %d.\n", device->name, device->state);
      break;
    }
    device = device->next;
  }

  if (device == NULL)
  {
    printf("Error: Device not found.\n");
  }
}

int main()
{
  addDevice("Light", 1);
  addDevice("Fan", 0);
  addDevice("TV", 2);

  controlDevice("Light", 0);
  controlDevice("Fan", 1);
  controlDevice("TV", 3);

  return 0;
}
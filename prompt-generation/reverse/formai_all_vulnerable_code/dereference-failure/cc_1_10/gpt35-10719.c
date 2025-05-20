//FormAI DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Define the states of different smart home devices */
typedef enum {
  OFF = 0,
  ON
} DeviceState;

/* Define the properties of different smart home devices */
typedef struct {
  char *name;
  DeviceState state;
} Device;

/* Define the smart home system */
typedef struct {
  Device *devices;
  int numDevices;
  bool status;
} SmartHomeSystem;

/* Create a new device */
Device createDevice(char *name) {
  Device device;
  device.name = name;
  device.state = OFF;
  return device;
}

/* Add a device to the smart home system */
void addDevice(SmartHomeSystem *system, Device device) {
  system->numDevices++;
  system->devices = realloc(system->devices, system->numDevices * sizeof(Device));
  system->devices[system->numDevices - 1] = device;
}

/* Turn on a device */
void turnOnDevice(Device *device) {
  if (device->state == OFF) {
    device->state = ON;
    printf("%s turned on.\n", device->name);
  } else {
    printf("%s is already on.\n", device->name);
  }
}

/* Turn off a device */
void turnOffDevice(Device *device) {
  if (device->state == ON) {
    device->state = OFF;
    printf("%s turned off.\n", device->name);
  } else {
    printf("%s is already off.\n", device->name);
  }
}

/* Turn on all devices */
void turnOnAllDevices(SmartHomeSystem *system) {
  int i;
  for (i = 0; i < system->numDevices; i++) {
    turnOnDevice(&system->devices[i]);
  }
  printf("All devices turned on.\n");
}

/* Turn off all devices */
void turnOffAllDevices(SmartHomeSystem *system) {
  int i;
  for (i = 0; i < system->numDevices; i++) {
    turnOffDevice(&system->devices[i]);
  }
  printf("All devices turned off.\n");
}

/* Get the status of the smart home system */
char* getStatus(SmartHomeSystem *system) {
  return system->status ? "on" : "off";
}

/* Toggle the status of the smart home system */
void toggleStatus(SmartHomeSystem *system) {
  system->status = !system->status;
  printf("Smart home system turned %s.\n", getStatus(system));
}

/* Main program */
int main() {
  SmartHomeSystem system;
  system.devices = NULL;
  system.numDevices = 0;
  system.status = OFF;

  /* Add devices to the smart home system */
  addDevice(&system, createDevice("Lights"));
  addDevice(&system, createDevice("TV"));
  addDevice(&system, createDevice("Thermostat"));
  addDevice(&system, createDevice("Security System"));

  /* Turn on all devices */
  turnOnAllDevices(&system);

  /* Toggle the status of the smart home system */
  toggleStatus(&system);

  /* Turn off all devices */
  turnOffAllDevices(&system);

  return 0;
}
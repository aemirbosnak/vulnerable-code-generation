//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct SensorNode {
  char sensor_name[64];
  int sensor_id;
  struct SensorNode* next;
} SensorNode;

SensorNode* head = NULL;

void sensor_add(char* sensor_name, int sensor_id) {
  SensorNode* new_node = (SensorNode*)malloc(sizeof(SensorNode));
  strcpy(new_node->sensor_name, sensor_name);
  new_node->sensor_id = sensor_id;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    SensorNode* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void sensor_check(char* data) {
  SensorNode* current = head;
  while (current) {
    if (strcmp(data, current->sensor_name) == 0) {
      printf("Sensor %s triggered!\n", current->sensor_name);
      system("/bin/bash -c \"echo 'Intruder Alert!' > /dev/ttyUSB0\"");
    }
    current = current->next;
  }
}

int main() {
  sensor_add("Kitchen Door Sensor", 1);
  sensor_add("Living Room Sensor", 2);
  sensor_add("Back Door Sensor", 3);

  char data[] = "Living Room Sensor";
  sensor_check(data);

  return 0;
}
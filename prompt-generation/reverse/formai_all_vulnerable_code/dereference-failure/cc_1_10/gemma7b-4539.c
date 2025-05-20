//Gemma-7B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store Wi-Fi signal strength data
typedef struct wif_data {
  char ssid[64];
  int signal_strength;
  struct wif_data* next;
} wif_data;

// Function to measure the Wi-Fi signal strength
int measure_signal_strength() {
  // Simulate random signal strength between -50 and -20
  return rand() % 31 + 50;
}

// Function to insert a wif_data node into a linked list
void insert_node(wif_data** head, char* ssid, int signal_strength) {
  wif_data* new_node = malloc(sizeof(wif_data));
  strcpy(new_node->ssid, ssid);
  new_node->signal_strength = signal_strength;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
  }
}

// Function to print the Wi-Fi signal strength data
void print_data(wif_data* head) {
  while (head) {
    printf("SSID: %s, Signal Strength: %d\n", head->ssid, head->signal_strength);
    head = head->next;
  }
}

int main() {
  // Create a linked list to store the wif_data nodes
  wif_data* head = NULL;

  // Measure and insert nodes into the linked list
  insert_node(&head, "Wi-Fi Network 1", measure_signal_strength());
  insert_node(&head, "Wi-Fi Network 2", measure_signal_strength());
  insert_node(&head, "Wi-Fi Network 3", measure_signal_strength());

  // Print the signal strength data
  print_data(head);

  return 0;
}
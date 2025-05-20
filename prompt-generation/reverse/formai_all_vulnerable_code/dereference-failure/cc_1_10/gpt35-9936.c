//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_SSID_LENGTH 32

/** Function prototypes **/
void get_wifi_signals();
void print_signal_strength(char ssid[], int signal_strength);

int main() {
  get_wifi_signals();
  return 0;
}

void get_wifi_signals() {
  FILE *fp;
  char path[1035];

  // Execute the shell command to get SSIDs and signal strengths
  fp = popen("/usr/sbin/iw dev wlan0 scan | grep SSID -A 5 | grep -e \"signal\" -e \"SSID\" | sed 's/^[ \t]*//;s/[ \t]*$//' |awk '{if(NR%2==0)printf \"%d \", $NF;else printf \"%s \", $0;}'","r");
  if (fp == NULL) {
    printf("Failed to get wifi signal strengths.\n");
    return;
  }

  // Parse the output and print the signal strength for each SSID
  while (fgets(path, sizeof(path)-1, fp) != NULL) {
    char *ssid = strtok(path, " ");
    int signal_strength = atoi(strtok(NULL, " "));
    
    // Only print signal strength if SSID is valid
    if (strlen(ssid) > 0 && strlen(ssid) <= MAX_SSID_LENGTH) {
      print_signal_strength(ssid, signal_strength);
    }
  }

  // Close the file pointer when done
  pclose(fp);
}

void print_signal_strength(char ssid[], int signal_strength) {
  int bars = 0;

  // Calculate number of bars based on signal strength
  if (signal_strength <= -100) {
    bars = 0;
  } else if (signal_strength >= -50) {
    bars = 4;
  } else {
    bars = (signal_strength + 100) / 25;
  }

  // Print the signal strength bars for the SSID
  printf("%s: ", ssid);
  for (int i = 0; i < bars; i++) {
    printf("▮");
  }
  printf("\n");
}
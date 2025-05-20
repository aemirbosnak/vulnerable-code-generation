//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surprised
#include <stdio.h>

// Defining the maximum number of Wi-Fi networks that can be scanned
#define MAX_NETWORKS 100

int main()
{
  int wifiStrength[MAX_NETWORKS]; // Integer array to hold the signal strength of Wi-Fi networks
  int numberOfNetworks = 0; // Variable to hold the number of networks scanned
  
  // Scanning for Wi-Fi networks and getting their signal strength
  printf("Scanning for Wi-Fi networks...\n");
  for(int i=0; i<MAX_NETWORKS; i++)
  {
    wifiStrength[i] = rand() % 101; // Generating a random number between 0-100 to simulate Wi-Fi signal strength
    if(wifiStrength[i] > 0) numberOfNetworks++;
    else break; // Exit loop if no more networks
  }
  
  printf("Scanning completed! %d networks found.\n\n", numberOfNetworks);
  
  // Displaying the Wi-Fi networks and their signal strength
  printf("### Wi-Fi Networks ###\n");
  for(int i=0; i<numberOfNetworks; i++)
  {
    printf("Network %d: Signal Strength = %d%%\n", i+1, wifiStrength[i]);
  }
  
  // Analyzing the signal strength and providing feedback
  int maxStrength = wifiStrength[0], minStrength = wifiStrength[0], avgStrength = 0;
  for(int i=0; i<numberOfNetworks; i++)
  {
    if(wifiStrength[i] > maxStrength) maxStrength = wifiStrength[i];
    if(wifiStrength[i] < minStrength) minStrength = wifiStrength[i];
    avgStrength += wifiStrength[i];
  }
  avgStrength /= numberOfNetworks;
  
  printf("\n### Signal Analysis ###\n");
  printf("Maximum Signal Strength: %d%%\n", maxStrength);
  printf("Minimum Signal Strength: %d%%\n", minStrength);
  printf("Average Signal Strength: %d%%\n", avgStrength);
  
  // Providing recommendations based on signal strength
  printf("\n### Recommendations ###\n");
  if(avgStrength >= 80) printf("Great signal strength, no issues expected.\n");
  else if(avgStrength >= 60) printf("Signal strength is good, but may experience some issues.\n");
  else if(avgStrength >= 40) printf("Signal strength is fair, expect some issues.\n");
  else if(avgStrength >= 20) printf("Signal strength is poor, may experience frequent issues.\n");
  else printf("Signal strength is very poor, connectivity issues are expected.\n");
  
  return 0;
}
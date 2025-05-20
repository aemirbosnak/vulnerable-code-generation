//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining structure for Access Point (AP)
struct AccessPoint {
   int apId;
   int signalStrength;
   char ssid[30];
};

int main() {
   int n;
   printf("Enter number of access point(s): ");
   scanf("%d", &n);

   // Dynamically allocating memory for APs
   struct AccessPoint *aps = (struct AccessPoint*)malloc(n * sizeof(struct AccessPoint));

   // Taking user input for APs
   for (int i = 0; i < n; i++) {
      printf("\nEnter details for access point %d:\n", i+1);
      printf("Enter signal strength (in dBm): ");
      scanf("%d", &aps[i].signalStrength);
      printf("Enter SSID: ");
      scanf("%s", aps[i].ssid);
      aps[i].apId = i+1;
   }

   // Displaying the collected data
   printf("\n\n***Wi-Fi Signal Strength Analyzer***\n\n");
   printf("AP ID\tSignal Strength (dBm)\tSSID\n");
   for (int i = 0; i < n; i++) {
      printf("%d\t\t%d\t\t%s\n", aps[i].apId, aps[i].signalStrength, aps[i].ssid);
   }

   // Sorting the APs by their signal strength in descending order using Bubble Sort
   for (int i = 0; i < n-1; i++) {
      for (int j = 0; j < n-i-1; j++) {
         if (aps[j].signalStrength < aps[j+1].signalStrength) {
            // Swapping the APs
            struct AccessPoint temp = aps[j];
            aps[j] = aps[j+1];
            aps[j+1] = temp;
         }
      }
   }

   // Displaying the sorted data
   printf("\n\nAfter sorting by Signal Strength (in descending order):\n");
   printf("AP ID\tSignal Strength (dBm)\tSSID\n");
   for (int i = 0; i < n; i++) {
      printf("%d\t\t%d\t\t%s\n", aps[i].apId, aps[i].signalStrength, aps[i].ssid);
   }

   // Freeing the dynamically allocated memory
   free(aps);

   return 0;
}
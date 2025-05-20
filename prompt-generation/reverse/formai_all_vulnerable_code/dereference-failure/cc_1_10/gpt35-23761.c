//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_SSID_LENGTH 32

// Struct to hold SSID and signal strength
typedef struct {
    char ssid[MAX_SSID_LENGTH + 1];
    int signal_strength;
} wifi_data;

// Function to parse wifi data from file and store it in wifi_data struct
void parse_file(char *filename, wifi_data *data, int *num_networks) {
    FILE *file = fopen(filename, "r");
    char buffer[256];
    int line_num = 0;

    if (file != NULL) {
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            if (line_num >= MAX_LINES) {
                break;
            }

            char *ssid = strtok(buffer, ",");
            char *signal_strength_str = strtok(NULL, ",");
            int signal_strength = atoi(signal_strength_str);

            if (strlen(ssid) <= MAX_SSID_LENGTH) {
                strcpy(data[line_num].ssid, ssid);
                data[line_num].signal_strength = signal_strength;
                line_num++;
            }
        }
        *num_networks = line_num;
        fclose(file);
    } else {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
}

// Function to calculate average signal strength
float calculate_average_signal_strength(wifi_data *data, int num_networks) {
    int sum = 0;
    for (int i = 0; i < num_networks; i++) {
        sum += data[i].signal_strength;
    }
    return (float)sum / num_networks;
}

// Function to sort wifi data by signal strength
void sort_by_signal_strength(wifi_data *data, int num_networks) {
    for (int i = 0; i < num_networks - 1; i++) {
        for (int j = i + 1; j < num_networks; j++) {
            if (data[i].signal_strength < data[j].signal_strength) {
                wifi_data temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: wifi_analyzer <filename>\n");
        exit(1);
    }

    char *filename = argv[1];
    wifi_data data[MAX_LINES];
    int num_networks = 0;

    parse_file(filename, data, &num_networks);
    if (num_networks == 0) {
        printf("No networks found in file.\n");
        exit(1);
    }

    float avg_signal_strength = calculate_average_signal_strength(data, num_networks);

    printf("---------------------\n");
    printf("Wifi networks analyzed\n");
    printf("---------------------\n");
    printf("Number of networks: %d\n", num_networks);
    printf("Average signal strength: %.2f\n", avg_signal_strength);
    printf("---------------------\n");
    printf("Networks by signal strength:\n");
    sort_by_signal_strength(data, num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %d\n", data[i].ssid, data[i].signal_strength);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Browser Plugin ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for storing user preferences
typedef struct {
    bool darkMode;
    bool autoRefresh;
    int fontSize;
} Preferences;

// Default preferences
Preferences defaultPrefs = {false, false, 12};

// Function to get user preferences from local storage
Preferences loadPreferences() {
    Preferences prefs = defaultPrefs;  // Default values
    FILE* file = fopen("prefs.txt", "r");
    if (file != NULL) {
        char* line = NULL;
        size_t len = 0;
        ssize_t read;
        while ((read = getline(&line, &len, file)) != -1) {
            char* key = strtok(line, "=");
            char* val = strtok(NULL, "=");
            if (strcmp(key, "darkMode") == 0) {
                prefs.darkMode = atoi(val);
            } else if (strcmp(key, "autoRefresh") == 0) {
                prefs.autoRefresh = atoi(val);
            } else if (strcmp(key, "fontSize") == 0) {
                prefs.fontSize = atoi(val);
            }
        }
        free(line);
        fclose(file);
    }
    return prefs;
}

// Function to save user preferences to local storage
void savePreferences(Preferences prefs) {
    FILE* file = fopen("prefs.txt", "w");
    if (file != NULL) {
        fprintf(file, "darkMode=%d\n", prefs.darkMode);
        fprintf(file, "autoRefresh=%d\n", prefs.autoRefresh);
        fprintf(file, "fontSize=%d\n", prefs.fontSize);
        fclose(file);
    }
}

// Function to toggle dark mode
void toggleDarkMode(bool* darkMode) {
    *darkMode = !(*darkMode);
    printf("Dark mode is now %s\n", *darkMode ? "on" : "off");
}

// Function to toggle auto refresh
void toggleAutoRefresh(bool* autoRefresh) {
    *autoRefresh = !(*autoRefresh);
    printf("Auto refresh is now %s\n", *autoRefresh ? "on" : "off");
}

// Function to change font size
void changeFontSize(int* fontSize, int delta) {
    *fontSize += delta;
    printf("Font size is now %d\n", *fontSize);
}

int main() {
    // Load user preferences from local storage
    Preferences prefs = loadPreferences();

    // Do something with user preferences
    toggleDarkMode(&prefs.darkMode);
    toggleAutoRefresh(&prefs.autoRefresh);
    changeFontSize(&prefs.fontSize, 2);

    // Save updated user preferences to local storage
    savePreferences(prefs);

    return 0;
}
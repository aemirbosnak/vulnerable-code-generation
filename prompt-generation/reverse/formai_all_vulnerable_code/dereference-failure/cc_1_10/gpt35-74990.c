//FormAI DATASET v1.0 Category: Browser Plugin ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the maximum number of supported tabs
#define MAX_TABS 10

// Define the Tab struct to hold relevant information about each tab
typedef struct Tab {
    char* url;
    char* title;
    int active;
} Tab;

// Define a global array of tabs
Tab tabs[MAX_TABS];

// Define the number of currently open tabs (starts at 0)
int numTabs = 0;

/**
 * Open a new tab with a given URL and title
 *
 * @param url: the URL of the new tab
 * @param title: the title of the new tab
 */
void openTab(char* url, char* title) {
    if (numTabs < MAX_TABS) {
        // Allocate memory for the new tab
        Tab* newTab = (Tab*) malloc(sizeof(Tab));

        // Set the properties of the new tab
        newTab->url = url;
        newTab->title = title;
        newTab->active = 1;

        // Add the new tab to the list of tabs
        tabs[numTabs++] = *newTab;

        printf("Opened new tab: %s - %s\n", newTab->title, newTab->url);
    } else {
        printf("Max number of tabs reached!\n");
    }
}

/**
 * Switch to a particular tab by index
 *
 * @param tabIdx: the index of the tab to switch to
 */
void switchToTab(int tabIdx) {
    // Make sure the tab index is valid
    if (tabIdx >= 0 && tabIdx < numTabs) {
        // Set the active status of all tabs and switch to the new active tab
        for (int i = 0; i < numTabs; i++) {
            if (i == tabIdx) {
                tabs[i].active = 1;
                printf("Switched to tab %d: %s - %s\n", i+1, tabs[i].title, tabs[i].url);
            } else {
                tabs[i].active = 0;
            }
        }
    } else {
        printf("Invalid tab index!\n");
    }
}

/**
 * Print the current list of open tabs
 */
void listTabs() {
    printf("Currently open tabs:\n");
    for (int i = 0; i < numTabs; i++) {
        printf("%d: %s - %s %s\n", i+1, tabs[i].title, tabs[i].url, tabs[i].active ? "(active)" : "");
    }
}

/**
 * Close the currently active tab
 */
void closeTab() {
    int activeTabIdx = -1;

    // Find the index of the active tab
    for (int i = 0; i < numTabs; i++) {
        if (tabs[i].active) {
            activeTabIdx = i;
            break;
        }
    }

    if (activeTabIdx >= 0) {
        // Free the memory of the tab to be closed
        free(tabs[activeTabIdx].url);
        free(tabs[activeTabIdx].title);

        // Remove the tab from the list of tabs by shifting all tabs after it left one position
        numTabs--;
        for (int i = activeTabIdx; i < numTabs; i++) {
            tabs[i] = tabs[i+1];
        }

        printf("Closed active tab.\n");
    } else {
        printf("No active tab found.\n");
    }
}

int main() {
    // Open some example tabs
    openTab("https://www.google.com", "Google");
    openTab("https://github.com", "GitHub");

    // Switch to the first tab
    switchToTab(0);

    // List the currently open tabs
    listTabs();

    // Close the active tab
    closeTab();

    // List the currently open tabs again
    listTabs();

    return 0;
}
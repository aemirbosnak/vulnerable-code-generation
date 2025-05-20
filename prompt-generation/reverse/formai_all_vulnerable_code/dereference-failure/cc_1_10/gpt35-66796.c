//FormAI DATASET v1.0 Category: Browser Plugin ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// This struct represents a browser tab
typedef struct tab {
    char* url;
    char* title;
    struct tab* next_tab;
} Tab;

// This struct represents the entire browser
typedef struct browser {
    Tab* current_tab;
    Tab* first_tab;
} Browser;

// This function creates a new tab from a given URL and title
Tab* create_tab(char* url, char* title) {
    Tab* new_tab = (Tab*) malloc(sizeof(Tab));
    new_tab->url = url;
    new_tab->title = title;
    new_tab->next_tab = NULL;
    return new_tab;
}

// This function adds a new tab to the browser's linked list
void add_tab_to_browser(Browser* my_browser, Tab* new_tab) {
    if (my_browser->first_tab == NULL) {
        my_browser->first_tab = new_tab;
    } else {
        // Find the last tab in the linked list and add the new tab after it
        Tab* current_tab = my_browser->first_tab;
        while (current_tab->next_tab != NULL) {
            current_tab = current_tab->next_tab;
        }
        current_tab->next_tab = new_tab;
    }
}

// This function prints the details of a given tab
void print_tab_details(Tab* my_tab) {
    printf("Title: %s\n", my_tab->title);
    printf("URL: %s\n", my_tab->url);
}

// This function changes the active tab to a given tab
void switch_to_tab(Browser* my_browser, Tab* desired_tab) {
    if (desired_tab == NULL) {
        printf("Tab not found.\n");
    } else {
        my_browser->current_tab = desired_tab;
        printf("Switched to tab:\n");
        print_tab_details(desired_tab);
    }
}

// This function displays all tabs in the browser's linked list
void display_all_tabs(Browser* my_browser) {
    int tab_number = 1;
    Tab* current_tab = my_browser->first_tab;
    while (current_tab != NULL) {
        printf("Tab %d:\n", tab_number);
        print_tab_details(current_tab);
        printf("\n");
        current_tab = current_tab->next_tab;
        tab_number++;
    }
}

int main() {
    // Create an example browser with three tabs
    Browser my_browser;
    my_browser.current_tab = NULL;
    my_browser.first_tab = NULL;

    Tab* tab1 = create_tab("https://www.google.com", "Google");
    add_tab_to_browser(&my_browser, tab1);
    Tab* tab2 = create_tab("https://www.youtube.com", "YouTube");
    add_tab_to_browser(&my_browser, tab2);
    Tab* tab3 = create_tab("https://www.reddit.com", "Reddit");
    add_tab_to_browser(&my_browser, tab3);

    // Switch to the third tab and display all tabs
    switch_to_tab(&my_browser, tab3);
    display_all_tabs(&my_browser);

    return 0;
}
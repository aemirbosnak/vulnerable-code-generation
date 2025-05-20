//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
/*
  This program analyzes a log file containing information about website visitors.
  The log file has the following format:
  
  [timestamp] [visitor IP] [page URL]
  
  The program analyzes the log file to determine which pages are the most popular and which IPs
  are the most frequent visitors.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Define a struct to represent a website visitor
typedef struct {
    char ip_address[16];
    int num_visits;
} Visitor;

// Define a struct to represent a webpage
typedef struct {
    char url[MAX_LINE_LENGTH];
    int num_hits;
} Webpage;

// Define a function to compare two visitors by their number of visits
int compare_visitors(const void* a, const void* b) {
    const Visitor* visitor_a = (const Visitor*) a;
    const Visitor* visitor_b = (const Visitor*) b;
    return visitor_b->num_visits - visitor_a->num_visits;
}

// Define a function to compare two webpages by their number of hits
int compare_webpages(const void* a, const void* b) {
    const Webpage* webpage_a = (const Webpage*) a;
    const Webpage* webpage_b = (const Webpage*) b;
    return webpage_b->num_hits - webpage_a->num_hits;
}

int main(int argc, char* argv[]) {
    // Check that the log file name was specified
    if (argc != 2) {
        printf("Usage: log_analyzer [log_file]\n");
        exit(1);
    }

    char* log_file_name = argv[1];

    // Open the log file
    FILE* log_file = fopen(log_file_name, "r");
    if (!log_file) {
        printf("Error: could not open log file '%s'\n", log_file_name);
        exit(1);
    }

    // Initialize an array to store visitors and an array to store webpages
    Visitor visitors[1000];
    int num_visitors = 0;
    Webpage webpages[1000];
    int num_webpages = 0;

    // Read each line of the log file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        // Parse the timestamp, visitor IP, and page URL from the line
        char* timestamp = strtok(line, " ");
        char* ip_address = strtok(NULL, " ");
        char* url = strtok(NULL, " ");

        // Search for the visitor in the visitors array
        int visitor_index = -1;
        for (int i = 0; i < num_visitors; i++) {
            if (strcmp(visitors[i].ip_address, ip_address) == 0) {
                visitor_index = i;
                break;
            }
        }

        // If the visitor is not found, add a new visitor to the visitors array
        if (visitor_index == -1) {
            Visitor new_visitor;
            strcpy(new_visitor.ip_address, ip_address);
            new_visitor.num_visits = 1;
            visitors[num_visitors] = new_visitor;
            num_visitors++;
        }
        // Otherwise, increment the number of visits for the existing visitor
        else {
            visitors[visitor_index].num_visits++;
        }

        // Search for the webpage in the webpages array
        int webpage_index = -1;
        for (int i = 0; i < num_webpages; i++) {
            if (strcmp(webpages[i].url, url) == 0) {
                webpage_index = i;
                break;
            }
        }

        // If the webpage is not found, add a new webpage to the webpages array
        if (webpage_index == -1) {
            Webpage new_webpage;
            strcpy(new_webpage.url, url);
            new_webpage.num_hits = 1;
            webpages[num_webpages] = new_webpage;
            num_webpages++;
        }
        // Otherwise, increment the number of hits for the existing webpage
        else {
            webpages[webpage_index].num_hits++;
        }
    }

    // Sort the visitors array by the number of visits in descending order
    qsort(visitors, num_visitors, sizeof(Visitor), compare_visitors);

    // Print the top 10 visitors
    printf("Top visitors:\n");
    for (int i = 0; i < 10 && i < num_visitors; i++) {
        printf("%s: %d\n", visitors[i].ip_address, visitors[i].num_visits);
    }

    // Sort the webpages array by the number of hits in descending order
    qsort(webpages, num_webpages, sizeof(Webpage), compare_webpages);

    // Print the top 10 webpages
    printf("\nTop webpages:\n");
    for (int i = 0; i < 10 && i < num_webpages; i++) {
        printf("%s: %d\n", webpages[i].url, webpages[i].num_hits);
    }

    // Close the log file
    fclose(log_file);

    return 0;
}
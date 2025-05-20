//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Function to check if a tag is opening or closing */
bool is_tag_opening(char* tag) {
    if (tag[0] == '<' && tag[1] != '/') {
        return true;
    }
    return false;
}

/* Function to get the tag name from a line */
char* get_tag_name(char* line) {
    char* tag = malloc(strlen(line) + 1);
    int i = 1;
    while (line[i] != ' ' && line[i] != '>') {
        tag[i - 1] = line[i];
        i++;
    }
    tag[i - 1] = '\0';
    return tag;
}

/* Function to get the tag value from a line */
char* get_tag_value(char* line) {
    char* value = malloc(strlen(line) + 1);
    int i = 0, j = 0;
    while (line[i] != '>') {
        i++;
    }
    i++;
    while (line[i] != '<') {
        value[j] = line[i];
        i++;
        j++;
    }
    value[j] = '\0';
    return value;
}

/* Main function to parse the XML file */
int main() {
    FILE *fp;
    char line[100];
    char current_tag[50] = "";
    bool current_tag_opened = false;

    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    while (fgets(line, 100, fp) != NULL) {
        if (is_tag_opening(line)) {
            strcpy(current_tag, get_tag_name(line));
            current_tag_opened = true;
        } else if (strncmp(line, "</", 2) == 0) {
            current_tag_opened = false;
            printf("%s: %s\n", current_tag, get_tag_value(line));
        } else if (current_tag_opened) {
            printf("%s: %s\n", current_tag, get_tag_value(line));
        }
    }

    fclose(fp);
    return 0;
}
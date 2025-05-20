//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct element {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Element;

Element elements[MAX_ELEMENTS];
int num_elements = 0;

void startElement(const char* name) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Too many elements.\n");
        exit(1);
    }
    strcpy(elements[num_elements].name, name);
    num_elements++;
}

void endElement(const char* name) {
    if (num_elements <= 0) {
        printf("Error: Mismatched end element.\n");
        exit(1);
    }
    strcpy(elements[--num_elements].value, "");
}

void characters(const char* chars, int len) {
    if (num_elements <= 0) {
        printf("Error: Mismatched end element.\n");
        exit(1);
    }
    if (len >= MAX_VALUE_LEN) {
        printf("Error: Value too long.\n");
        exit(1);
    }
    strncpy(elements[num_elements-1].value, chars, len);
    elements[num_elements-1].value[len] = '\0';
}

int main() {
    FILE* fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[4096];
    int len;
    while ((len = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        for (int i = 0; i < len; i++) {
            if (buffer[i] == '<') {
                int j = i + 1;
                while (j < len && buffer[j]!= '>') {
                    j++;
                }
                if (j >= len) {
                    printf("Error: Invalid element.\n");
                    exit(1);
                }
                startElement(&buffer[i+1]);
            } else if (buffer[i] == '>') {
                int j = i + 1;
                while (j < len && buffer[j]!= '<') {
                    j++;
                }
                if (j >= len) {
                    printf("Error: Invalid element.\n");
                    exit(1);
                }
                endElement(&buffer[i+1]);
            } else if (isalpha(buffer[i])) {
                int j = i;
                while (j < len && isalnum(buffer[j])) {
                    j++;
                }
                characters(&buffer[i], j - i);
            }
        }
    }

    fclose(fp);

    printf("Number of elements: %d\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Element %d:\n", i);
        printf("  Name: %s\n", elements[i].name);
        printf("  Value: %s\n", elements[i].value);
    }

    return 0;
}
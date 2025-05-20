//FormAI DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook {
    char name[50];
    char number[20];
};

int main() {
    struct phonebook *pb;
    int num_entries = 0;
    int max_entries = 10;
    char option;

    pb = (struct phonebook*) malloc(max_entries * sizeof(struct phonebook));

    while (1) {
        printf("Enter option (a - add, l - list, q - quit): ");
        scanf(" %c", &option);

        if (option == 'a') {
            char name[50];
            char number[20];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);

            if (num_entries == max_entries) {
                max_entries *= 2;
                pb = (struct phonebook*) realloc(pb, max_entries * sizeof(struct phonebook));
            }

            strcpy(pb[num_entries].name, name);
            strcpy(pb[num_entries].number, number);
            num_entries++;
        }
        else if (option == 'l') {
            if (num_entries == 0) {
                printf("No entries.\n");
            }
            else {
                printf("Name\t\tNumber\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s\t\t%s\n", pb[i].name, pb[i].number);
                }
            }
        }
        else if (option == 'q') {
            break;
        }
        else {
            printf("Invalid option.\n");
        }
    }

    free(pb);
    return 0;
}
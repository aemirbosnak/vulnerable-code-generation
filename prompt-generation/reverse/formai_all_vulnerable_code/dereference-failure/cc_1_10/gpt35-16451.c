//FormAI DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

struct person {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct index {
    char name[MAX_NAME_LENGTH];
    int offset;
};

void add_person(FILE *data, FILE *index_file, char *name, char *email) {
    struct person p;
    strcpy(p.name, name);
    strcpy(p.email, email);
    fwrite(&p, sizeof(struct person), 1, data);

    struct index idx;
    strcpy(idx.name, name);
    fseek(data, 0, SEEK_END);
    idx.offset = ftell(data) - sizeof(struct person);
    fwrite(&idx, sizeof(struct index), 1, index_file);
}

void search_by_name(FILE *data, FILE *index_file, char *name) {
    struct index idx;
    int found = 0;

    rewind(index_file);
    while (fread(&idx, sizeof(struct index), 1, index_file)) {
        if (strcmp(idx.name, name) == 0) {
            found = 1;
            fseek(data, idx.offset, SEEK_SET);
            struct person p;
            fread(&p, sizeof(struct person), 1, data);
            printf("Name: %s\nEmail: %s\n", p.name, p.email);
        }
    }

    if (!found) {
        printf("No person found with that name.\n");
    }
}

int main() {
    FILE *data = fopen("data.bin", "ab+");
    FILE *index_file = fopen("index.bin", "ab+");
    
    if (data == NULL || index_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int choice;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    do {
        printf("\n1. Add a person\n");
        printf("2. Search by name\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_person(data, index_file, name, email);
                break;

            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                search_by_name(data, index_file, name);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    fclose(data);
    fclose(index_file);
    return 0;
}
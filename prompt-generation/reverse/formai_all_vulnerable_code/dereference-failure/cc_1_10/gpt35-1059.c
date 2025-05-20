//FormAI DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

struct email {
    char name[30];
    char address[50];
};

struct mailing_list {
    struct email emails[MAX_EMAILS];
    int num_emails;
};

struct mailing_list* create_list() {
    struct mailing_list* list = malloc(sizeof(struct mailing_list));
    list->num_emails = 0;
    return list;
}

void add_email(struct mailing_list* list, char* name, char* address) {
    if (list->num_emails == MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }
    strcpy(list->emails[list->num_emails].name, name);
    strcpy(list->emails[list->num_emails].address, address);
    list->num_emails++;
}

void print_list(struct mailing_list* list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->num_emails; i++) {
        printf("%s <%s>\n", list->emails[i].name, list->emails[i].address);
    }
}

void save_list(struct mailing_list* list, char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < list->num_emails; i++) {
        fprintf(fp, "%s,%s\n", list->emails[i].name, list->emails[i].address);
    }
    fclose(fp);
    printf("Mailing list saved to %s\n", filename);
}

struct mailing_list* load_list(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }
    struct mailing_list* list = create_list();
    char line[80];
    char* name;
    char* address;
    while (fgets(line, 80, fp) != NULL) {
        name = strtok(line, ",");
        address = strtok(NULL, ",");
        add_email(list, name, address);
    }
    fclose(fp);
    printf("Mailing list loaded from %s\n", filename);
    return list;
}

int main() {
    struct mailing_list* list = create_list();
    add_email(list, "John Smith", "john.smith@example.com");
    add_email(list, "Jane Doe", "jane.doe@example.com");
    print_list(list);
    save_list(list, "mailing_list.csv");
    struct mailing_list* loaded_list = load_list("mailing_list.csv");
    print_list(loaded_list);
    return 0;
}
//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char phone[12];
} Subscriber;

typedef struct node {
    Subscriber* subscriber;
    struct node* next;
} Node;

Node* head = NULL;
int count = 0;

void menu();
void add_subscriber();
void delete_subscriber();
void view_subscribers();
void save_subscribers();
void load_subscribers();
void filter_subscribers();
void clear_subscribers();

int main() {
    load_subscribers();
    menu();
    save_subscribers();
    clear_subscribers();
    return 0;
}

void menu() {
    while (1) {
        printf("\n\n");
        printf(" ██████╗░██╗░░░██╗░░░░░░█████╗░██╗░░░██╗███████╗██████╗░\n");
        printf(" ██╔══██╗██║░░░██║░░░░░██╔══██╗██║░░░██║██╔════╝██╔══██╗\n");
        printf(" ██████╔╝██║░░░██║░░░░░███████║██║░░░██║█████╗░░██████╔╝\n");
        printf(" ██╔══██╗██║░░░██║░░░░░██╔══██║██║░░░██║██╔══╝░░██╔══██╗\n");
        printf(" ██║░░██║╚██████╔╝██╗░░██║░░██║╚██████╔╝███████╗██║░░██║\n");
        printf(" ╚═╝░░╚═╝░╚═════╝░╚═╝░░╚═╝░░╚═╝░╚═════╝░╚══════╝╚═╝░░╚═╝\n\n");
        printf("1. Add subscriber\n");
        printf("2. Delete subscriber\n");
        printf("3. View subscribers\n");
        printf("4. Filter subscribers\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                delete_subscriber();
                break;
            case 3:
                view_subscribers();
                break;
            case 4:
                filter_subscribers();
                break;
            case 0:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void add_subscriber() {
    printf("Enter name: ");
    char name[50];
    scanf("%s", name);

    Node* node = (Node*)malloc(sizeof(Node));
    node->subscriber = (Subscriber*)malloc(sizeof(Subscriber));
    strcpy(node->subscriber->name, name);

    printf("Enter email: ");
    scanf("%s", node->subscriber->email);

    printf("Enter phone: ");
    scanf("%s", node->subscriber->phone);

    node->next = head;
    head = node;

    count++;

    printf("Subscriber added successfully.\n");
}

void delete_subscriber() {
    printf("Enter name of subscriber to delete: ");
    char name[50];
    scanf("%s", name);

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->subscriber->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->subscriber);
            free(current);
            count--;
            printf("Subscriber deleted successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Subscriber not found. Try again.\n");
}

void view_subscribers() {
    printf("Total subscribers: %d\n", count);

    if (count == 0) {
        return;
    }

    Node* current = head;

    while (current != NULL) {
        printf("%s - %s - %s\n", current->subscriber->name, current->subscriber->email, current->subscriber->phone);
        current = current->next;
    }
}

void save_subscribers() {
    FILE* fp = fopen("subscribers.txt", "w+");

    if (fp != NULL) {
        Node* current = head;

        while (current != NULL) {
            fprintf(fp, "%s,%s,%s\n", current->subscriber->name, current->subscriber->email, current->subscriber->phone);
            current = current->next;
        }

        fclose(fp);
    }
}

void load_subscribers() {
    FILE* fp = fopen("subscribers.txt", "r");

    if (fp != NULL) {
        char line[150];

        while (fgets(line, sizeof(line), fp) != NULL) {
            char* name = strtok(line, ",");
            char* email = strtok(NULL, ",");
            char* phone = strtok(NULL, ",");

            Node* node = (Node*)malloc(sizeof(Node));
            node->subscriber = (Subscriber*)malloc(sizeof(Subscriber));
            strcpy(node->subscriber->name, name);
            strcpy(node->subscriber->email, email);
            strcpy(node->subscriber->phone, phone);

            node->next = head;
            head = node;

            count++;
        }

        fclose(fp);
    }
}

void filter_subscribers() {
    printf("Enter search query: ");
    char query[50];
    scanf("%s", query);

    int matches = 0;
    Node* current = head;

    while (current != NULL) {
        char* name = current->subscriber->name;
        if (strstr(name, query) != NULL) {
            printf("%s - %s - %s\n", current->subscriber->name, current->subscriber->email, current->subscriber->phone);
            matches++;
        }
        current = current->next;
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

void clear_subscribers() {
    Node* current = head;

    while (current != NULL) {
        Node* next = current->next;
        free(current->subscriber);
        free(current);
        current = next;
    }

    count = 0;
}
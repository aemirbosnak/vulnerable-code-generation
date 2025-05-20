//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for the linked list
struct Node {
    char *entry;
    char *date;
    struct Node *next;
};

// Create a new node
struct Node *create_node(char *entry, char *date) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->entry = strdup(entry);
    new_node->date = strdup(date);
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the linked list
void insert_node(struct Node **head, struct Node *new_node) {
    new_node->next = *head;
    *head = new_node;
}

// Delete a node from the linked list
void delete_node(struct Node **head, char *date) {
    struct Node *current = *head;
    struct Node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->date, date) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->entry);
            free(current->date);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Print the linked list
void print_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%s %s\n", current->date, current->entry);
        current = current->next;
    }
}

// Get the number of entries for a given date
int get_num_entries(struct Node *head, char *date) {
    int count = 0;
    struct Node *current = head;
    while (current != NULL) {
        if (strcmp(current->date, date) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Get the average length of entries for a given date
float get_avg_length(struct Node *head, char *date) {
    int total_length = 0;
    int num_entries = 0;
    struct Node *current = head;
    while (current != NULL) {
        if (strcmp(current->date, date) == 0) {
            total_length += strlen(current->entry);
            num_entries++;
        }
        current = current->next;
    }
    return (float)total_length / num_entries;
}

// Get the most frequent word in a given date
char *get_most_freq_word(struct Node *head, char *date) {
    char *most_freq_word = NULL;
    int max_freq = 0;
    struct Node *current = head;
    while (current != NULL) {
        if (strcmp(current->date, date) == 0) {
            char *words[100];
            int num_words = 0;
            char *token = strtok(current->entry, " ");
            while (token != NULL) {
                words[num_words++] = token;
                token = strtok(NULL, " ");
            }
            for (int i = 0; i < num_words; i++) {
                int freq = 0;
                for (int j = 0; j < num_words; j++) {
                    if (strcmp(words[i], words[j]) == 0) {
                        freq++;
                    }
                }
                if (freq > max_freq) {
                    max_freq = freq;
                    most_freq_word = words[i];
                }
            }
        }
        current = current->next;
    }
    return most_freq_word;
}

int main() {
    // Create the head of the linked list
    struct Node *head = NULL;

    // Insert some nodes into the linked list
    insert_node(&head, create_node("Hello world!", "2023-03-08"));
    insert_node(&head, create_node("This is a test.", "2023-03-09"));
    insert_node(&head, create_node("I am learning C.", "2023-03-10"));
    insert_node(&head, create_node("I am having a lot of fun.", "2023-03-11"));

    // Print the linked list
    printf("Linked list:\n");
    print_list(head);

    // Get the number of entries for a given date
    printf("\nNumber of entries for 2023-03-10: %d\n", get_num_entries(head, "2023-03-10"));

    // Get the average length of entries for a given date
    printf("Average length of entries for 2023-03-10: %.2f\n", get_avg_length(head, "2023-03-10"));

    // Get the most frequent word in a given date
    printf("Most frequent word for 2023-03-10: %s\n", get_most_freq_word(head, "2023-03-10"));

    // Delete a node from the linked list
    delete_node(&head, "2023-03-09");

    // Print the linked list again
    printf("\nLinked list after deleting a node:\n");
    print_list(head);

    // Free the linked list
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current->entry);
        free(current->date);
        free(current);
        current = next;
    }

    return 0;
}
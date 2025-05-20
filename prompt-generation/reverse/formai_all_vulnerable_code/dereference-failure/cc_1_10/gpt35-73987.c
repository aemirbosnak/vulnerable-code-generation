//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000
#define ALPHA_INDEX_OFFSET 97
#define NUM_LETTERS 26

// Define the structure for a frequency node
typedef struct fnode {
    char letter;
    int freq;
    struct fnode *next;
} FNode;

// Function to convert the text to lower case
void to_lower(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }
}

// Function to check if a character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to update the frequency of a letter in the linked list
void update_frequency(FNode **head, char letter) {
    FNode *curr = *head;
    while (curr != NULL) {
        if (curr->letter == letter) {
            curr->freq++;
            return;
        }
        curr = curr->next;
    }

    // If the letter is not in the list, create a new node for it
    FNode *new_node = (FNode *) malloc(sizeof(FNode));
    new_node->letter = letter;
    new_node->freq = 1;
    new_node->next = *head;
    *head = new_node;
}

// Function to print the frequency list
void print_freq_list(FNode *head) {
    while (head != NULL) {
        printf("%c: %d\n", head->letter, head->freq);
        head = head->next;
    }
}

// Function to get the most frequent letter in the linked list
char get_most_frequent_letter(FNode *head) {
    FNode *curr = head;
    char most_freq_letter;
    int max_freq = 0;

    while (curr != NULL) {
        if (curr->freq > max_freq) {
            max_freq = curr->freq;
            most_freq_letter = curr->letter;
        }
        curr = curr->next;
    }

    return most_freq_letter;
}

// Function to shift a letter by a certain number of positions
char shift_letter(char c, int shift) {
    int index = c - ALPHA_INDEX_OFFSET;
    index = (index + shift) % NUM_LETTERS;
    return index + ALPHA_INDEX_OFFSET;
}

// Main function
int main() {
    printf("Welcome to the Shape Shifting Text Summarizer!\n");

    // Get the text input from the user
    char text[MAX_LEN];
    printf("Enter the text to be summarized (max %d characters):\n", MAX_LEN);
    fgets(text, sizeof(text), stdin);
    to_lower(text);

    // Create a linked list to store the frequency of each letter in the text
    FNode *freq_list = NULL;
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (is_letter(c)) {
            update_frequency(&freq_list, c);
        }
    }
    printf("Letter frequencies:\n");
    print_freq_list(freq_list);

    // Determine the most frequent letter in the text
    char most_freq_letter = get_most_frequent_letter(freq_list);
    printf("Most frequent letter: %c\n", most_freq_letter);

    // Determine the shift value based on the most frequent letter
    int shift = most_freq_letter - 'e';
    printf("Shift value: %d\n", shift);

    // Shift each letter in the text by the shift value
    printf("Shape shifted text:\n");
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (is_letter(c)) {
            printf("%c", shift_letter(c, shift));
        } else {
            printf("%c", c);
        }
    }

    return 0;
}
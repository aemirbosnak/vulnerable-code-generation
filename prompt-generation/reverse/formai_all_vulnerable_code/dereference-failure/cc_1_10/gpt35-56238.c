//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int score;

int get_random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

Node* create_new_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* create_linked_list(int size) {
    Node* head = create_new_node(get_random_number(97, 122));
    Node* current_node = head;
    for (int i = 1; i < size; i++) {
        Node* new_node = create_new_node(get_random_number(97, 122));
        current_node->next = new_node;
        current_node = new_node;
    }
    return head;
}

void print_linked_list(Node* head) {
    while (head != NULL) {
        printf("%c", head->data);
        head = head->next;
    }
}

int calculate_typing_speed(float time_elapsed, int word_count) {
    return (int) (word_count / (time_elapsed / 60));
}

void start_typing_test(Node* head) {
    score = 0;
    int word_count = 0;
    float time_elapsed = 0;
    time_t start_time = time(NULL);
    char user_input[MAX_STRING_LENGTH];
    while (head != NULL) {
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");
    fgets(user_input, MAX_STRING_LENGTH, stdin);
    time_elapsed = (float) (time(NULL) - start_time);
    char* token = strtok(user_input, " ");
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }
    score = calculate_typing_speed(time_elapsed, word_count);
}

int main() {
    printf("Welcome to the Typing Speed Test\n");
    printf("Type the phrase exactly as you see it on the screen\n");
    Node* head = create_linked_list(100);
    start_typing_test(head);
    printf("You typed at a speed of %d words per minute\n", score);
    return 0;
}
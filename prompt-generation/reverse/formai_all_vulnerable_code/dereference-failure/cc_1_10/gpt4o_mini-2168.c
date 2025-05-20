//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum title size
#define MAX_TITLE_LEN 100

// Structure for a Book
typedef struct Book {
    char title[MAX_TITLE_LEN];
    struct Book* next;
} Book;

// Structure for a Stack to manage recently added books
typedef struct Stack {
    Book* top;
} Stack;

// Structure for a Queue to manage borrowed books
typedef struct Queue {
    Book* front;
    Book* rear;
} Queue;

// Function prototypes
Book* createBook(const char* title);
void push(Stack* stack, const char* title);
char* pop(Stack* stack);
void enqueue(Queue* queue, const char* title);
char* dequeue(Queue* queue);
void displayBooks(Book* head);
void freeBooks(Book* head);
void clearStack(Stack* stack);
void clearQueue(Queue* queue);

// Main Function
int main() {
    Book* library = NULL; // Head of the linked list
    Stack recentBooks = { NULL }; // Stack initialization
    Queue borrowedBooks = { NULL, NULL }; // Queue initialization
    int choice;
    char title[MAX_TITLE_LEN];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Books\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Show Recently Added Books\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter book title to add: ");
                getchar(); // Consume newline
                fgets(title, MAX_TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                library = createBook(title);
                push(&recentBooks, title);
                printf("Book added: %s\n", title);
                break;
            case 2:
                printf("Enter book title to remove: ");
                getchar(); 
                fgets(title, MAX_TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; 
                // Logic to remove book from list (to be implemented)
                printf("Book removed: %s (not implemented)\n", title);
                break;
            case 3:
                printf("Books in the library:\n");
                displayBooks(library);
                break;
            case 4:
                printf("Enter book title to borrow: ");
                getchar(); 
                fgets(title, MAX_TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0; 
                enqueue(&borrowedBooks, title);
                printf("Book borrowed: %s\n", title);
                break;
            case 5:
                printf("Returning book...\n");
                char* bookReturned = dequeue(&borrowedBooks);
                if (bookReturned) {
                    printf("Book returned: %s\n", bookReturned);
                    free(bookReturned);
                } else {
                    printf("No borrowed books to return.\n");
                }
                break;
            case 6:
                printf("Recently added books:\n");
                if (recentBooks.top) {
                    printf("%s\n", recentBooks.top->title);
                    clearStack(&recentBooks);
                } else {
                    printf("No recent books added.\n");
                }
                break;
            case 7:
                printf("Exiting...\n");
                freeBooks(library);
                clearStack(&recentBooks);
                clearQueue(&borrowedBooks);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function implementations
Book* createBook(const char* title) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook) {
        strncpy(newBook->title, title, MAX_TITLE_LEN);
        newBook->next = NULL;
    }
    return newBook;
}

void push(Stack* stack, const char* title) {
    Book* newBook = createBook(title);
    newBook->next = stack->top;
    stack->top = newBook;
}

char* pop(Stack* stack) {
    if (stack->top == NULL) return NULL;
    Book* temp = stack->top;
    stack->top = stack->top->next;
    char* title = strdup(temp->title);
    free(temp);
    return title;
}

void enqueue(Queue* queue, const char* title) {
    Book* newBook = createBook(title);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newBook;
        return;
    }
    queue->rear->next = newBook;
    queue->rear = newBook;
}

char* dequeue(Queue* queue) {
    if (queue->front == NULL) return NULL;
    Book* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    char* title = strdup(temp->title);
    free(temp);
    return title;
}

void displayBooks(Book* head) {
    if (head == NULL) {
        printf("No books available.\n");
        return;
    }
    Book* current = head;
    while (current != NULL) {
        printf("- %s\n", current->title);
        current = current->next;
    }
}

void freeBooks(Book* head) {
    while (head) {
        Book* temp = head;
        head = head->next;
        free(temp);
    }
}

void clearStack(Stack* stack) {
    while (stack->top) {
        pop(stack);
    }
}

void clearQueue(Queue* queue) {
    while (queue->front) {
        dequeue(queue);
    }
}
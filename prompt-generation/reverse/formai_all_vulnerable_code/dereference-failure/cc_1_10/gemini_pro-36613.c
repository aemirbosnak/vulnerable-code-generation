//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <pthread.h>

// A generic linked list node
struct node 
{ 
    char *data; 
    struct node *next; 
}; 

// Our global stock list
struct node *stock_list = NULL;

// Our global lock
pthread_mutex_t stock_list_lock;

// Our global condition variable
pthread_cond_t stock_list_cv;

// Insert a stock into the global stock list
void insert_stock(char *stock) 
{ 
    // Acquire the lock
    pthread_mutex_lock(&stock_list_lock);
    
    // Create a new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = strdup(stock);
    new_node->next = stock_list;
    
    // Insert the new node at the head of the list
    stock_list = new_node;
    
    // Release the lock
    pthread_mutex_unlock(&stock_list_lock);
    
    // Signal the condition variable
    pthread_cond_signal(&stock_list_cv);
} 

// Remove a stock from the global stock list
void remove_stock(char *stock) 
{ 
    // Acquire the lock
    pthread_mutex_lock(&stock_list_lock);
    
    // Find the node to remove
    struct node *prev = NULL;
    struct node *curr = stock_list;
    while (curr != NULL && strcmp(curr->data, stock) != 0) 
    {
        prev = curr;
        curr = curr->next;
    }
    
    // If the node was found, remove it from the list
    if (curr != NULL) 
    {
        if (prev == NULL) 
        {
            stock_list = curr->next;
        } 
        else 
        {
            prev->next = curr->next;
        }
        free(curr->data);
        free(curr);
    }
    
    // Release the lock
    pthread_mutex_unlock(&stock_list_lock);
} 

// Print the global stock list
void print_stock_list() 
{ 
    // Acquire the lock
    pthread_mutex_lock(&stock_list_lock);
    
    // Print the list
    struct node *curr = stock_list;
    while (curr != NULL) 
    {
        printf("%s\n", curr->data);
        curr = curr->next;
    }
    
    // Release the lock
    pthread_mutex_unlock(&stock_list_lock);
} 

// A thread function that waits for stock updates
void *stock_update_thread(void *arg) 
{ 
    // Wait for a signal on the condition variable
    pthread_mutex_lock(&stock_list_lock);
    while (stock_list == NULL) 
    {
        pthread_cond_wait(&stock_list_cv, &stock_list_lock);
    }
    pthread_mutex_unlock(&stock_list_lock);
    
    // Print the updated stock list
    print_stock_list();
    
    return NULL;
} 

int main() 
{ 
    // Initialize the lock and condition variable
    pthread_mutex_init(&stock_list_lock, NULL);
    pthread_cond_init(&stock_list_cv, NULL);
    
    // Create a thread to wait for stock updates
    pthread_t tid;
    pthread_create(&tid, NULL, stock_update_thread, NULL);
    
    // Insert some stocks into the global stock list
    insert_stock("AAPL");
    insert_stock("GOOG");
    insert_stock("MSFT");
    
    // Print the updated stock list
    print_stock_list();
    
    // Remove a stock from the global stock list
    remove_stock("GOOG");
    
    // Print the updated stock list
    print_stock_list();
    
    // Wait for the thread to finish
    pthread_join(tid, NULL);
    
    // Destroy the lock and condition variable
    pthread_mutex_destroy(&stock_list_lock);
    pthread_cond_destroy(&stock_list_cv);
    
    return 0;
}
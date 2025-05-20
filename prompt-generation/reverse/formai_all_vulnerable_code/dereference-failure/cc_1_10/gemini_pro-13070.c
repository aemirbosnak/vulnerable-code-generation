//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct {
    char *key;
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} list;

list *list_new() {
    list *l = malloc(sizeof(list));
    l->head = NULL;
    pthread_mutex_init(&l->lock, NULL);
    pthread_cond_init(&l->cond, NULL);
    return l;
}

void list_free(list *l) {
    node *n = l->head;
    while (n) {
        node *next = n->next;
        free(n->key);
        free(n);
        n = next;
    }
    pthread_mutex_destroy(&l->lock);
    pthread_cond_destroy(&l->cond);
    free(l);
}

bool list_insert(list *l, char *key, int value) {
    pthread_mutex_lock(&l->lock);
    node *n = malloc(sizeof(node));
    n->key = strdup(key);
    n->value = value;
    n->next = l->head;
    l->head = n;
    pthread_cond_signal(&l->cond);
    pthread_mutex_unlock(&l->lock);
    return true;
}

bool list_delete(list *l, char *key) {
    pthread_mutex_lock(&l->lock);
    node *prev = NULL;
    node *n = l->head;
    while (n) {
        if (strcmp(n->key, key) == 0) {
            if (prev) {
                prev->next = n->next;
            } else {
                l->head = n->next;
            }
            free(n->key);
            free(n);
            pthread_mutex_unlock(&l->lock);
            return true;
        }
        prev = n;
        n = n->next;
    }
    pthread_mutex_unlock(&l->lock);
    return false;
}

bool list_find(list *l, char *key, int *value) {
    pthread_mutex_lock(&l->lock);
    node *n = l->head;
    while (n) {
        if (strcmp(n->key, key) == 0) {
            *value = n->value;
            pthread_mutex_unlock(&l->lock);
            return true;
        }
        n = n->next;
    }
    pthread_mutex_unlock(&l->lock);
    return false;
}

void *thread_func(void *arg) {
    list *l = (list *)arg;
    while (true) {
        pthread_mutex_lock(&l->lock);
        while (l->head == NULL) {
            pthread_cond_wait(&l->cond, &l->lock);
        }
        node *n = l->head;
        l->head = n->next;
        pthread_mutex_unlock(&l->lock);
        printf("%s: %d\n", n->key, n->value);
        free(n->key);
        free(n);
    }
    return NULL;
}

int main() {
    list *l = list_new();
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, l);
    list_insert(l, "foo", 1);
    list_insert(l, "bar", 2);
    list_insert(l, "baz", 3);
    sleep(1);
    list_free(l);
    pthread_join(thread, NULL);
    return 0;
}
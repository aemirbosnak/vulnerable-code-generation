//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int x, y;
} point_t;

typedef struct {
    point_t *points;
    int num_points;
} point_set_t;

typedef struct {
    point_set_t *set;
    int num_sets;
} point_set_list_t;

typedef struct {
    point_set_list_t *list;
    int num_lists;
} point_set_list_list_t;

void *thread_func(void *arg) {
    point_set_list_list_t *list_list = (point_set_list_list_t *)arg;
    for (int i = 0; i < list_list->num_lists; i++) {
        point_set_list_t *list = &list_list->list[i];
        for (int j = 0; j < list->num_sets; j++) {
            point_set_t *set = &list->set[j];
            for (int k = 0; k < set->num_points; k++) {
                point_t *point = &set->points[k];
                printf("(%d, %d)\n", point->x, point->y);
            }
        }
    }
    return NULL;
}

int main() {
    point_set_list_list_t list_list;
    list_list.num_lists = 10;
    list_list.list = malloc(sizeof(point_set_list_t) * list_list.num_lists);
    for (int i = 0; i < list_list.num_lists; i++) {
        point_set_list_t *list = &list_list.list[i];
        list->num_sets = 10;
        list->set = malloc(sizeof(point_set_t) * list->num_sets);
        for (int j = 0; j < list->num_sets; j++) {
            point_set_t *set = &list->set[j];
            set->num_points = 10;
            set->points = malloc(sizeof(point_t) * set->num_points);
            for (int k = 0; k < set->num_points; k++) {
                point_t *point = &set->points[k];
                point->x = rand() % 100;
                point->y = rand() % 100;
            }
        }
    }

    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, &list_list);
    pthread_join(thread, NULL);

    return 0;
}
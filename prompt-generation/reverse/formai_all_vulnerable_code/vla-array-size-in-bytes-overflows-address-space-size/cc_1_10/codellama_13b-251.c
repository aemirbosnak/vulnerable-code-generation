//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 100
#define MAX_PATH_LENGTH 10000

typedef struct {
    int x;
    int y;
} City;

int compare_cities(const void *a, const void *b) {
    City *city1 = (City *) a;
    City *city2 = (City *) b;
    return city1->x - city2->x;
}

void print_path(City *cities, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", cities[i].x);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    City cities[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    qsort(cities, n, sizeof(City), compare_cities);

    int path[MAX_PATH_LENGTH];
    int path_length = 0;
    for (int i = 0; i < n; i++) {
        int city_index = 0;
        for (int j = 0; j < path_length; j++) {
            if (path[j] == cities[i].x) {
                city_index = j;
                break;
            }
        }
        if (city_index == 0) {
            path[path_length++] = cities[i].x;
        } else {
            int swap_index = path_length - 1;
            while (swap_index > city_index) {
                int temp = path[swap_index];
                path[swap_index] = path[swap_index - 1];
                path[swap_index - 1] = temp;
                swap_index--;
            }
        }
    }

    print_path(path, path_length);

    return 0;
}
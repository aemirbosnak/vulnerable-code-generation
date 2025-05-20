//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: authentic
/*
 * Fitness Tracker
 *
 * A simple C program to track your fitness data.
 *
 * Copyright (c) 2023 Your Name <you@example.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEPS 100000

typedef struct {
    char name[32];
    int steps[MAX_STEPS];
    int num_steps;
} fitness_tracker;

fitness_tracker *create_fitness_tracker(char *name) {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    if (tracker == NULL) {
        return NULL;
    }

    strcpy(tracker->name, name);
    tracker->num_steps = 0;

    return tracker;
}

void destroy_fitness_tracker(fitness_tracker *tracker) {
    free(tracker);
}

void add_steps(fitness_tracker *tracker, int steps) {
    if (tracker->num_steps == MAX_STEPS) {
        return;
    }

    tracker->steps[tracker->num_steps++] = steps;
}

int get_total_steps(fitness_tracker *tracker) {
    int total_steps = 0;
    for (int i = 0; i < tracker->num_steps; i++) {
        total_steps += tracker->steps[i];
    }

    return total_steps;
}

void print_fitness_tracker(fitness_tracker *tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Total steps: %d\n", get_total_steps(tracker));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        return 1;
    }

    fitness_tracker *tracker = create_fitness_tracker(argv[1]);
    if (tracker == NULL) {
        fprintf(stderr, "Error: could not create fitness tracker.\n");
        return 1;
    }

    // Add some steps to the tracker.
    add_steps(tracker, 1000);
    add_steps(tracker, 2000);
    add_steps(tracker, 3000);

    // Print the fitness tracker.
    print_fitness_tracker(tracker);

    // Destroy the fitness tracker.
    destroy_fitness_tracker(tracker);

    return 0;
}
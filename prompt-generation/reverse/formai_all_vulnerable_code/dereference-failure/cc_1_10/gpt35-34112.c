//FormAI DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ITER 2000

#define SCREEN_WIDTH 150
#define SCREEN_HEIGHT 50

// define complex struct
typedef struct complex{
    double real;
    double imag;
}complex;

// define thread data struct
typedef struct thread_data{
    int thread_id;
    int num_threads;
}thread_data;

// initialize global variables
int max_iter;
int screen_width,screen_height;
int **canvas;
double xmin = -2.0, xmax = 1.0;
double ymin = -1.0, ymax = 1.0;

// function to calculate mandelbrot set
void* calculate_mandelbrot_set(void* arg){
    int i,j;
    thread_data* data = (thread_data*)arg;
    int thread_id = data->thread_id;
    int num_threads = data->num_threads;
    complex c,z;
    double x,y;
    int iter;
    int start_idx = thread_id * (screen_height/num_threads);
    int end_idx = (thread_id == num_threads-1) ? screen_height : (thread_id+1)*(screen_height/num_threads);
    for(i=start_idx;i<end_idx;++i){
        y = ymin + (double)i/SCREEN_HEIGHT*(ymax-ymin);
        for(j=0;j<SCREEN_WIDTH;++j){
            x = xmin + (double)j/SCREEN_WIDTH*(xmax-xmin);
            c.real = x;
            c.imag = y;
            z.real = 0.0;
            z.imag = 0.0;
            iter = 0;
            while((z.real*z.real + z.imag*z.imag < 4.0) && (iter < MAX_ITER)){
                double temp = z.real*z.real - z.imag*z.imag + c.real;
                z.imag = 2*z.real*z.imag + c.imag;
                z.real = temp;
                ++ iter;
            }
            canvas[i][j] = iter;
        }
    }
}

// function to print the canvas on screen
void print_canvas(){
    int i,j;
    for(i=0;i<SCREEN_HEIGHT;++i){
        for(j=0;j<SCREEN_WIDTH;++j){
            int iter = canvas[i][j];
            if(iter == MAX_ITER){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    scanf("%d",&max_iter);
    scanf("%d %d",&screen_width,&screen_height);
    canvas = (int**)malloc(sizeof(int*)*SCREEN_HEIGHT);
    int i,j;
    for(i=0;i<SCREEN_HEIGHT;++i){
        canvas[i] = (int*)malloc(sizeof(int)*SCREEN_WIDTH);
    }
    // create threads
    int num_threads = sysconf(_SC_NPROCESSORS_ONLN); 
    if(num_threads > screen_height){
        num_threads = screen_height;
    }
    pthread_t *threads = (pthread_t*)malloc(sizeof(pthread_t)*num_threads);
    thread_data *data = (thread_data*)malloc(sizeof(thread_data)*num_threads);
    for(i=0;i<num_threads;++i){
        data[i].thread_id = i;
        data[i].num_threads = num_threads;
        pthread_create(&threads[i],NULL,calculate_mandelbrot_set,(void*)&data[i]);
    }
    for(i=0;i<num_threads;++i){
        pthread_join(threads[i],NULL);
    }
    // print canvas
    print_canvas();
    return 0;
}
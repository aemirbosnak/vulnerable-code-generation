//FormAI DATASET v1.0 Category: Fractal Generation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//Define a function to calculate the mandel_iteration of a given complex number
int mandel_iteration(double real, double imaginary, int max_iteration){
    int i;
    double r = 0, c_real = real, c_imag = imaginary;
    for(i=0;i<max_iteration;i++){
        double r_new = pow(r,2) - pow(c_real,2) - pow(c_imag,2);
        double i_new = (2*r*c_imag);
        r = r_new + c_real;
        c_imag = i_new + imaginary;
        if(pow(r,2) + pow(c_imag,2) > 4){
            break;
        }
    }
    return i;
}

int main(){
    //initialize variables
    double x_min = -2, x_max = 1, y_min = -1, y_max = 1;
    int width = 800, height = 600, max_iteration=1000;
    int i,j;

    //Generate random seed
    srand(time(NULL));

    //Allocate memory for the fractal array
    int** fractal = (int**)malloc(sizeof(int*)*height);
    for(i=0;i<height;i++){
        fractal[i] = (int*)malloc(sizeof(int)*width);
    }

    //Fill the fractal array with data
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            double x = x_min + (x_max - x_min) * (double)j / (double)width;
            double y = y_min + (y_max - y_min) * (double)i / (double)height;
            fractal[i][j] = mandel_iteration(x,y,max_iteration);
        }
    }

    //Print the fractal array to a file
    FILE* file = fopen("fractal.pgm","w");
    fprintf(file,"P2\n%d %d\n255\n",width,height);
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            fprintf(file,"%d ",(int)((double)fractal[i][j]/(double)max_iteration*255));
        }
        fprintf(file,"\n");
    }
    fclose(file);

    //Free the memory
    for(i=0;i<height;i++){
        free(fractal[i]);
    }
    free(fractal);

    return 0;
}
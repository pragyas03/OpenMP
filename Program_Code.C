#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <omp.h>

enum {R = 20};

double NaiveSlide(double inputArray[R], int size, int step);
double OptimizedSlide(int row, double inputArray[R], int size, int step);

int main () {
   
   int a, step = 2, size = 4;
   double randomInputArray[R];
    
   /* for loop execution */
   for( a = 1; a <= R; a++ ){
      randomInputArray[a-1] = a;
   }
    
   clock_t end;
   clock_t begin;

   double time_spent;
   double time_spent_opt; 
  
    // Naive -- RUN
	begin = clock();
       	NaiveSlide(randomInputArray, size, step);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime taken by Naive product is: %lf \n\n",time_spent);
	
    // Optimized -- RUN
	begin = clock();
        OptimizedSlide(R, randomInputArray, size, step);
	end = clock();
	time_spent_opt = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime taken by OMP product is: %lf \n ",time_spent_opt);
 	printf("\n\nSpeed up using OMP is:\t %.4f times sequential one \n\n", time_spent/time_spent_opt);
    
  return 0;
}

double NaiveSlide(double inputArray[R], int size, int step){
	double product[R];
    double temp_prod ;
    int i,j;

	for(i = 0; i <= R-size+step; i+=step ){
            temp_prod = 1;
            for (j = i; j < i+size ; j++){

                temp_prod = temp_prod * inputArray[j];
            }
            product[i] = temp_prod;
		}
    printf("\nNaive {SIZE:%d, STEP:%d} : Values of sliding window statistics are: \n",size,step);
    for (int k = 0 ; k <=R ; k+=step){
        double val = product[k];
	if (val <= 0.00)
		break;		
	printf("%.2f\t",val);
	}
	return 0;
}

double OptimizedSlide(int row, double inputArray[R], int size, int step){
    double product[row];
    double temp_prod;
	int i;
    
 	#pragma omp parallel for shared(row, product, inputArray)  private(i) schedule(static, 10) 
	for (i=0;i <= row-size+step; i+=step){
        temp_prod = 1;
        for(int j = i; j< i+size ;j++){
            temp_prod = temp_prod * inputArray[j];
        }
        product[i] = temp_prod;
       }
    printf("Optimized {SIZE:%d, STEP:%d} : Values of sliding window statistics are: \n", size,step);
	for (int k = 0 ; k < row ; k+=step){
	double val = product[k];
        if (val <= 0.00)
                break;          
        printf("%.2f\t",val);
	}	
    	return 0;
}
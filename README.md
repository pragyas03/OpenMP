# OpenMP

* The project is coded in C language. The program code is run in parallel using OpenMP. It is seen that there is at least 2x speed up when the code is executed using OpenMP.
* The program is based on the concept of the sliding window problem.
* In this project, the input values are:
  - a single-dimensional array of elements that is sorted in ascending order
  -  window size
  -  step size
* When the program code is run, it computes the product of all elements of the array that are inside the window of the given ‘size’ and then the window slides forward with the given number of ‘step’ (which is the indices of the array).
* Finally, an array of the calculated products is formed and printed as the output of the program.

# Compilation Steps

* For the program included with this report the size of the array is 20, the window size is 4 and the step size is 2. With these values, the array of products is calculated using the naive approach and parallelized using OpenMP.
* The program is compiled using gcc -fopenmp command
* The name of the method showing the naive approach is NaiveSlide() and the name of the method showing the parallel approach with OpenMP is OptimizedSlide().

# Output Screenshots

![Output -1](https://github.com/pragyas03/OpenMP/blob/main/Output_1.png)
![Output -2](https://github.com/pragyas03/OpenMP/blob/main/Output_2.png)
![Output -3](https://github.com/pragyas03/OpenMP/blob/main/Output_3.png)


# Achieved Speedup
The speed-up achieved after running the code multiple times is always at least 2x times using OpenMP when compared to the naive approach.

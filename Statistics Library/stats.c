#include "stats.h"
#include <stdlib.h>
#include <math.h>

double mean(double *arr, int length)
{
    double sum = 0;
    
    for (int i = 0; i < length; ++i)
        sum += arr[i];
        
    return sum / length;
}


int cmpfunc (const void * a, const void * b) {
   return ( *(double *)a - *(double *)b );
}


double median(double *arr, int length)
{
    qsort(arr, length, sizeof(double), cmpfunc);
    
    if (length % 2) 
        return arr[length / 2];
    
    return (arr[length / 2] + arr[length / 2 - 1]) / 2;
}


double sd(double *arr, int length)
{
    double m = mean(arr, length);
    double sum = 0;
    
    for (int i = 0; i < length; ++i)
        sum += pow(arr[i] - m, 2);
        
    return sqrt(sum / length);
}
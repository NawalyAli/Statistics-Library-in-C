#include <stdio.h>
#include <stdlib.h>
#include "stats.h"


int main(void)
{
    printf("Enter numbers (seperated by space): ");
    
    int c, length = 0;
    double *arr = NULL;
    
    do {
        double data;
        scanf("%lf", &data);
        
        arr = realloc(arr, (length + 1) * sizeof(double));
        arr[length] = data;
        length++;
    } while ((c = getc(stdin)) != '\n' && c != EOF);
    
    printf("\nMean: %.3lf", mean(arr, length));
    printf("\nMedian: %.3lf", median(arr, length));
    printf("\nStandard Deviation: %.3lf", sd(arr, length));
    
    free(arr);
    return 0;
}
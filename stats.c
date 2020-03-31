/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
* *****************************************************************************/
/**
 * @file <Add File Name>
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Harsh Talati>
 * @date < 03-28-2020>
 *
 *
 */
#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


printarray(test,SIZE);
    print_statistics(test,SIZE);



 

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */
/*Printing array here*/

void printarray(unsigned char *array, unsigned int har)
{
    printf("\nThe array is:\n [");
    for (int i=0; i<har;i++)
    {
        printf("%d  ", array[i]);
    }

printf("]\n");
}


/*Printing statistics here*/

void print_statistics(unsigned char *array, unsigned int har)
{
    float median;
    median = find_median(array, har);
    printf("\nMedian is %f\n", median );
    
    int mean;
    mean = find_mean(array,har);
    printf("\nMean is %i\n",mean);
   
    int minimum;
    minimum = find_minimum(array,har);
    printf("\nMinimum number is %i\n", minimum);
    
    int maximum;
    maximum = find_maximum(array,har);
    printf("\nMaximum number is %i\n", maximum);
}


/*Median  function*/
 unsigned char find_median(unsigned char *array, unsigned int har)
 {
     float med =0.0;
     
     sort_array(array,har);
     if (har%2!=0){
    med = array[(har/2)];
     }
     if (har%2 == 0){
         med = (array[(har/2)-1] + array[(har/2)])/2.0;
     }
     return med;
 }

/*Mean  function*/
unsigned char find_mean(unsigned char *array, unsigned int  har)
{
    unsigned int sum=0;
    for(int i =0;i<har;i++)
    {
        sum += array[i];
    }
    sum = sum/har;

    return sum;
}

/*Max number function*/
unsigned char find_maximum(unsigned char *array, unsigned int har)
{
    unsigned char max = array[0];
    for (int i=0;i < har; i++){
        if (array[i] > max ){
            max = array[i];
        }
    }
    return max;
}

/*Min number function*/
unsigned char find_minimum(unsigned char *array, unsigned int har)
{
    unsigned char min = array[0];
    for (int i=0;i < har; i++){
        if (array[i] < min ){
            min = array[i];
        }
    }
    return min;
}

/*Sorting of array  function*/
void  sort_array(unsigned char *array, unsigned int har)
{
    for (char i=0; i < har; i++){
        for(char j=0; j <har; j++){
            if (array[i] > array[j]) {
                unsigned char buffer = array[i];
                array[i] = array[j];
                array[j] = buffer;
            }
        }
    }

printf("\nThis is sorted array(largest to smallest):\n [");
for (int i=0; i < har; i++)
{
printf("%i  ", array[i]);
}
printf("]\n");
}




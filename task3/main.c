#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int sum(int array[], int asize);
int swap(int* pA, int* pB);
int sort_1pass(int array[], int asize);
void sort(int array[], int asize);
void printarray(int array[], int asize);

int main()
{
    int array[SIZE]={8,2,3,4,5,3,0,7,9};
    printarray(array, SIZE);
    printf("Sum of the digits : %d\n", sum(array, SIZE));
    sort(array, SIZE);
    printf("the median (middle) digit in the sorted array : %d\n", array[SIZE/2]);
    printf("average of the digits in the array : %0.2lf\n", (double)(sum(array, SIZE))/SIZE);
    return 0;
}

void printarray(int array[], int asize){
    int i;
    for(i=0; i<asize; i++)
        printf("%d ", array[i]);
     printf("\n");
}

int sum(int array[], int asize){
    int i;
    int result=0;
    for(i=0; i<asize; i++)
        result+=array[i];
    return result;
}

int swap(int* pA, int* pB){
    if(*pA>*pB) {
        int temp=*pA;
        *pA=*pB;
        *pB=temp;
        return 1;
     }
    else return 0;
}

int sort_1pass(int array[], int asize){
    int i;
    int temp=0;
    for(i=0; i<asize-1; i++)
        if(array[i]>array[i+1]){
            swap(&array[i],&array[i+1]);
            temp=1;
        }
    return temp;
}


void sort(int array[], int asize){
    int i;
    for(i=0; i<asize; i++){
        sort_1pass(array, asize);
        printarray(array, asize);
    }
}

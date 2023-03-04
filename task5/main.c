#include <stdio.h>
#include <stdlib.h>
#define SIZE 9 // array size
int main(void)
{
 int array1[10] = {8,2,3,4,5,3,0,7,9};
 int array2[10] = {1,2,3,4,5,6,7,8,9};
 int array3[10];
 int i;
 printf("Array1 = { 8,2,3,4,5,3,0,7,9}\n");
 printf("Array2 = { 1,2,3,4,5,6,7,8,9}\n");
 printf("Array3 = {");
 for(i=0; i<(SIZE-1); i++){
     array3[i] = array1[i]*array2[i];
     printf(" %d,", array3[i]);
 }
 for(i=(SIZE-1); i<(SIZE); i++){
        array3[i] = array1[i]*array2[i];
        printf(" %d", array3[i]);
 }
 printf("}\n");

 return 0;
}

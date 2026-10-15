#include <stdio.h>
#include <stdlib.h>
 
typedef struct { 


    int size;
    int* array;


   /* data */
} Array;
 
Array arraycreat(int insize);
void arrayfree(Array* a);
int arraysize(Array* a);
int* arrayat(Array*a,int num);



   
Array arraycreat(int insize){
  Array a;
  a.size = insize;
  a.array =(int*)malloc(sizeof(int)*insize);
  return a;
}
void arrayfree(Array* a){
a->size = 0;
free(a->array); 
a->array = NULL;



}
int arraysize(Array* a){

return a->size;

}
int* arrayat(Array* a, int num){

   return &(a->array[num]);
}
int main() {

   int b;
scanf("%d",&b);

Array a = arraycreat(b);

printf("%d",arraysize(&a));
printf("%d",arraysize(&a));
a.array[10] = 100;
printf("%d",*arrayat(&a,10));
arrayfree(&a);
return 0;
}




























    return 0;
}
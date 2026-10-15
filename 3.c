#include <stdio.h>
#include <stdlib.h>
void mycopy(char* p1,char* p2);
int main(){
char a1[50] = {0}; 
fgets(a1,sizeof(a1),stdin);
char a2[50];
mycopy(a2,a1);
printf("%s\n",a2);
return 0;
}
void mycopy(char* p1,char* p2){
   
while((*(p1++) = *(p2++)) != '\0'){
}
}
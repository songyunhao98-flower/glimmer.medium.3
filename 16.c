#include <stdio.h>
int count(int a ,int b){
    int num = 0;
for(;a > 0;){

if((a % 10) == b){
num++;
}
a = a / 10;
}
return num;
}
int main(){

int a,b;
scanf("%d %d",&a,&b);
printf("%d\n",count(a,b));



return 0;
}
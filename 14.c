#include <stdio.h>
int main(){
int num;
int count = 0;
scanf("%d",&num);
int mast = 255;
int num1 = (num & mast);
for(int cnt = 0;cnt <= 31;cnt++){
if((num1 & (1 << cnt) ^ (1 << cnt)) == 0){
count++;
}
}
printf("%d\n",count);






    return 0;
}
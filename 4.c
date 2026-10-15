#include <stdio.h>
int judge(int num);
int main(){
printf("请输入数字\n");
int num;
scanf("%d",&num);
int result;
result = judge(num);
printf("%d\n",result);
    return 0;
}
int judge(int num){
int sum = 0;
for(int cnt = 0;cnt <= 31;cnt++){
if((num & (1 << cnt) ^ (1 << cnt)) == 0){
sum++;
}
}
return sum;
}
#include <stdio.h>
int judge(int a);
int main(){
int num;
int sum =0;
scanf("%d",&num);
for(int i = 1; i <= num; i++){
int res = judge(i);
if(res == 1){
sum = sum + i;
}
}
printf("%d\n",sum);

    return 0;
}
int judge(int a){
int res = 0;
if(a % 5 == 0){
    res = 1;
}
return res;
}
#include <stdio.h>
int sushu(int a);
int main(){
int max;
int sum = 0;
int count = 0;
int cnt;
scanf("%d",&max);
for( cnt = 2;sum <= max;cnt++){
int judge;
judge = sushu(cnt);
if(judge == 1){
sum = sum + cnt;
printf("%d\n",cnt);
count++;
}
}
if(sum == max){
    printf("%d\n",count);

}
else {
    printf("%d\n",count - 1);
}





    return 0;
}
int sushu(int a){
int judge = 1;
if(a == 2){
    judge = 1;
}else {
for(int i = 2;i < a;i++){
if(a % i == 0){
    judge = 0;
    break;
}
}
}
return judge;
}
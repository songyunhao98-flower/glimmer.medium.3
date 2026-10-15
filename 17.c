#include <stdio.h>
int judge(int a[],int cnt1);
int main(){
int num;
int count;
int max = 0;
scanf("%d",&num);
int a[50];
for(int cnt = 0;cnt < num;cnt++){
scanf("%d",&a[cnt]);
}
for(int cnt1 = 0;cnt1 < num;cnt1++){

if(judge(a,cnt1) > max){
max = judge(a,cnt1);
}
}
printf("%d\n",max);

return 0;
}
int judge(int a[],int cnt1){
int count = 1;

while(a[cnt1 + 1] == a[cnt1] + 1){

count++;
cnt1++;
}
return count;
}

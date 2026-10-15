#include <stdio.h>
enum {
mon = 1,
tus,
wed,
thu,
fif,
sat,
san,
};
int judge(int cent,int today){
int cnt = 0;
switch (cent) {
case 0:
case 5:
if(today == mon){
    cnt = 1;
}
break;
case 1:
case 6:
if(today == tus){
    cnt = 1;
}
break;
case 2:
case 7:
if(today == wed){
    cnt = 1;
}
break;
case 3:
case 8:
if(today == thu){
    cnt = 1;
}
break;
case 4:
case 9:
if(today == fif){
    cnt = 1;
}
break;
default:
cnt = 0;
break;
}
return cnt;
} 
int main(){
int cent; 
int today;
scanf("%d %d",&cent,&today);
printf("%s\n",judge(cent,today)?"ok":"no");

return 0;
}
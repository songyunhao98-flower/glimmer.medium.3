#include <stdio.h>
typedef struct{
char a[100];
int b;
int c;
int d;
} person;
int judge(person a,person b);
int daxiao(int a,int b);
int main(){
int num;
int i = 0;
person ren[100];
scanf("%d",&num);
for( i = 0;i < num;i++){
scanf("%s %d %d %d",ren[i].a,&ren[i].b,&ren[i].c,&ren[i].d);
}
for(int i = 0; i < num; i++){
for(int cnt = i + 1;cnt < num;cnt++){
 int jud = judge(ren[i],ren[cnt]);
if( jud == 1){
printf("%s %s\n",ren[i].a,ren[cnt].a);
}
}
}
    return 0;
}
int judge(person a,person b){
int result = 0;
if(daxiao(a.b,b.b) && daxiao(a.c,b.c) && daxiao(a.d,b.d)){
        
result = 1;}
return result;
}
int daxiao(int a,int b){
int re = 0;
if(a >= b && a - b <= 5 ){
    re = 1;
}else if(a <= b && a - b >= -5){
    re = 1;
}

return re;

}
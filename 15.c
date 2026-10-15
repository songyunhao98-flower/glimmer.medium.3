#include <stdio.h>
#include <stdlib.h>
char a[100] = {0};
int main(){
int idx = 0;
int judge = 0;
if(fgets(a,sizeof(a),stdin) == NULL){
return 1;
}
for(;a[idx] != '\n';idx++){

if(a[idx] >= 48 && a[idx] <= 57){
printf("%c\n",a[idx]);
judge = 1;
break;
}
}
if(judge == 0){
printf("none");
}
    return 0;
}
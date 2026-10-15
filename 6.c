#include <stdio.h>
#include <stdlib.h>
char lastword(char* p);
int main(){

char a[50] = {0};
if(fgets(a,sizeof(a),stdin) == NULL){
    return 0;
}

printf("%c\n",lastword(a));


    return 0;
}
char lastword(char* p){
int idx;
for(idx = 0;*(p + idx) != '\0';idx++){
}
return *(p + idx - 2);

}
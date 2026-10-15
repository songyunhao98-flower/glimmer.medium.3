
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
int main (){

struct stat a;
if(stat("another.c",&a) == -1) {
    
    printf("fault");
return 1;
}
printf("%ld\n",a.st_ino);

struct tm* b; 
b = localtime(&a.st_mtime);
char c[100];
strftime(c,sizeof(c),"%Y-%m-%d %H:%M:%S",b);
printf("%s\n",c);










    return 0;
}

	
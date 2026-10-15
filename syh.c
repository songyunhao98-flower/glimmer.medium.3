#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 全局变量，存放在静态存储区 .data / .bss
int global_uninit;
int global_init = 100;
static int global_static = 200;

void func_scope()
{
    int local_var = 10;                // 栈上局部变量
    static int static_local = 0;       // 静态局部变量，仅初始化一次
    static_local++;
    printf("[静态局部变量] static_local = %d\n", static_local);
    printf("func_scope内部local_var的地址%p\n", &local_var);
}

struct TestAlign
{
    char c;
    int  i;
};

int main(void)
{
    printf("========= １．各类变量地址（虚拟地址空间）=========\n");
    printf("未初始化全局变量global_uninit地址%p\n", &global_uninit);
    printf("已初始化全局变量global_init地址%p\n", &global_init);
    printf("静态全局变量global_static地址%p\n", &global_static);

    int main_local = 20;
    printf("main函数内局部变量main_local地址%p\n", &main_local);

    func_scope();
    func_scope();

    printf("\n========= ２．指针 &、* 与数组本质 =========\n");
    int arr[5] = {1,2,3,4,5};
    int *p = arr;
    printf("数组名arr = %p&arr[0] = %p\n", arr, &arr[0]);
    printf("*p = %d,p+1 = %p9指针+1,跳过一个int)\n", *p, p+1);

    printf("\n========= ３．动态内存 malloc、calloc、realloc、free =========\n");
    int *pmalloc = malloc(5 * sizeof(int));
    printf("malloc分配地址:%p,malloc内存初始值:%d(随机脏值)\n", pmalloc, pmalloc[0]);

    int *pcalloc = calloc(5, sizeof(int));
    printf("calloc分配地址:%p,calloc内存初始值:%d(自动清零)\n", pcalloc, pcalloc[0]);

    int *ptmp = realloc(pmalloc, 10 * sizeof(int));
    if(ptmp != NULL)
    {
        pmalloc = ptmp;
        printf("realloc扩容后地址:%p\n", pmalloc);
    }

    free(pmalloc);
    free(pcalloc);

    printf("\n========= 4.C字符串,末尾'\\0' =========\n");
    char str[] = "hello";
    printf("字符串内容：%s,数组长度sizeof(str)=%zu\n", str, sizeof(str));

    printf("\n========= 5.sizeof 数组 vs 指针 =========\n");
    printf("sizeof(arr)=%zu\n", sizeof(arr));
    printf("sizeof(p)=%zu(32位系统4字节,64位系统8字节)\n", sizeof(p));

    printf("\n========= ６．结构体内存对齐 =========\n");
    printf("sizeof(struct TestAlign)=%zu\n", sizeof(struct TestAlign));

    printf("\n========= ７．悬垂指针演示（禁止实际使用）=========\n");
    int *dangle_p;
    {
        int temp = 99;
        dangle_p = &temp;
    }
    

    return 0;
}
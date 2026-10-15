# ~~我是倒着写的 改题人不要嘲笑我~~
## task 1
### task 1.1 什么是指针
#### task 1.1.1
**指针变量保存地址。**可以把普通变量想成一个房间，把指针想成写着房间位置的纸条。纸条和房间是两个不同对象。

```c
int age = 18;
int *p = &age;
```

| 写法 | 读法 | 这里的含义 |
|---|---|---|
| `int *p` | p是指向int的指针 | p中保存可用于访问int对象的地址 |
| `age` | 变量的值 | 18 |
| `&age` | 取age的地址 | age所在位置 |
| `p` | 指针的值 | 保存的地址，与 `&age`相同 |
| `*p` | 解引用 | 沿地址访问age，此时读到18 |
| `&p` | 取指针变量自身的地址 | “纸条本身放在哪里” |

`*p = 19;`会改动 `age`，因为它们在这里访问同一个整数对象。`p = ...`改变的是指针保存的地址，与 `*p = ...`改变目标对象的内容不同。

指针大小与目标平台、编译模式和实现有关。常见64位桌面环境中对象指针为8字节，常见32位环境中为4字节，但 C 不保证所有平台、所有指针类型一律如此。不能只看电脑宣传“64位”，就不看实际编译目标。
#### task 1.1.2
题中 `x`开始为10，指针 `p`指向它，然后执行 `*p = 20`，所以 `x`变成20。
另一部分中，数组初值为 `{3,6,9}`，`q`起初指向首元素；关键表达式是：
```c
int y = ++*arr + *++q;
```
按运算符结合方式拆开：

| 部分 | 等价理解 | 效果 | 该部分得到的值 |
|---|---|---|---:|
| `++*arr` | `++(*arr)` | 首元素3先变成4 | 4 |
| `*++q` | `*(++q)` | q先移到第二个元素，再读取 | 6 |

所以 **`y=10`，原题输出为 `20 10`**。数组现在是 `{4,6,9}`，q指向下标1。
#### task 1.1.3
| 情况 | 是什么意思 | 怎样处理 |
|---|---|---|
| 未初始化指针 | 例如只写 `int *p;`，尚未让它保存有效地址 | 初始化后再使用 |
| 空指针 | 明确表示当前没有指向可访问对象，常写 `NULL` | 使用前判断；不能解引用 |
| 悬空指针 | 曾指向对象，但对象已结束生存期 | 不再访问；管理好所有别名 |
| 野指针 | 常被泛指为指向无效或不明确位置的指针 | 避免未初始化、越界、失效对象访问 |
#### task 1.1.4
**代码** ：
```c
void swap(int *first, int *second)
{
    int midst = *first;
    *first = *second;
    *second = midst;
}
```
### task 1.2 什么是结构体
#### task 1.2.1
**结构体**把不同类型的信息组合成一个整体。例如一个人的姓名、性别、年龄、身高属于同一份记录。

```c
typedef struct PerInfo {
    char name[10];
    char sex;
    int age;
    double height;
} PerInfo;
```

| 成员 | 类型 | 含义 |
|---|---|---|
| `name` | `char[10]` | 10字节字符数组；作为字符串最多留9字节正文 |
| `sex` | `char` | 一个字节的标记，例如 `'M'`或 `'F'` |
| `age` | `int` | 年龄整数 |
| `height` | `double` | 身高数值，例如以米为单位的1.78 |
#### task 1.2.2
**以下面的代码为例** ：

```c
PerInfo person = {"Yunhao", 'M', 18, 1.78};
PerInfo *ptr = &person;
ptr->age = 19;
```

三种访问形式：

| 写法 | 使用条件 | 这里是否访问原来的age |
|---|---|---|
| `person.age` | 手里是结构体对象 | 是 |
| `(*ptr).age` | 先解引用，得到对象，再访问成员 | 是 |
| `ptr->age` | 通过结构体指针直接访问成员 | 是 |

`->`没有复制整个结构体。它表示“沿着指针找到对象，再找其中的成员”。`(*ptr)`上的括号不能随意去掉，因为 `.`的优先级高于一元 `*`。
#### task 1.2.3
**内存对齐**：对象通常要放在满足特定地址倍数要求的位置。成员之间可能因此空出一些字节，叫**填充**。

在常见的 `char`大小/对齐为1、`int`为4、`double`为8的布局规则下，按题目顺序计算：

| 内容 | 从结构体开头算的字节偏移 | 大小 | 原因 |
|---|---:|---:|---|
| name | 0—9 | 10 | 字符数组 |
| sex | 10 | 1 | char只需按1对齐 |
| 填充 | 11 | 1 | 让age从4的倍数12开始 |
| age | 12—15 | 4 | int |
| height | 16—23 | 8 | 16已是8的倍数 |

总计24字节，已是最大成员对齐8的倍数。**偏移**是从整个对象开头到某成员开头的字节距离，首成员偏移为0。

常见布局计算套路：当前末尾位置向上取到成员对齐要求的倍数，放入成员；所有成员放完后，再把总大小向上取到结构体对齐要求的倍数。

若改成 `name、height、sex、age`：name后需填充到16，height占16—23，sex占24，age从28开始，总大小为32字节。数据内容相同，仅顺序变化就可能改变空间占用。
## task 2
### task 2.1 什么是链表
#### task 2.1.1

| 对比 | 数组 | 普通单向链表 |
|---|---|---|
| 元素位置 | 一段连续存储 | 不要求节点地址连续 |
| 怎么找到下一项 | 按元素大小计算地址 | 读取当前节点的next |
| 找第n项 | 合法下标可直接定位 | 通常从头走过去 |
| 插入删除 | 为保留顺序可能需要搬元素 | 找到位置后主要调整连接 |
| 额外空间 | 不需每项存next | 每个节点多存一个指针，分配还可能有额外开销 |
#### task 2.1.2
节点定义：

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```
### task 2.2
#### 实现基本的链操作
```c
Node *node = malloc(sizeof *node);
node->data = 0;
node->next = NULL;
```
#### 添加元素
```c
Node* cha(int value){
Node* node = (Node*)malloc(sizeof(Node));
if(node == NULL) return NULL;
node->data = value;
ndoe->next = NULL; 
return node;
}
```
```c
void head_cha(Node** headnode,int value){
Node* node1 = (Node*)malloc(sizeof(Node));
if(node1 == NULL) return;
node1->data = value;
node1->next = *headnode;
*headnode = node1;
}
```
```c
void end_cha(Node* head,int value){
if(head == NULL) return;
for(;head->next != NULL;head = head->next){
}
Node* node_end = (Node*)malloc(sizeof(Node));
if(node_end == NULL) return;
node_end->data = value;
node_end->next = NULL;
head->next = node_end;
}
```
#### 打印链表
```c
void print(Node* head){
while(head != NULL){
printf("%d ",head->data);
head = head->next;
}
return;
}
```

#### 查找元素
```c
int chazhao(Node* head,int n){
if(head == NULL) return 0;   
int count = 0;
for(;head->data != n;){
head = head->next;
count++;
if(head == NULL) {
    printf("fault");
    return 0;
}
}
return count;
}
```
#### 删除元素
```c
int delete(Node** head,int num){
if(*head == NULL) return 0;
int count = 0;
if(num == 0){
Node* old_head = *head;
*head = (*head)->next;
free(old_head);
return 1;
}
Node* last = *head;
Node* head_copy = *head;
for(;count != num;count++){
last = head_copy;
head_copy = head_copy->next;
if(head_copy == NULL) {
    printf("false");
    return 0;
}
}
last->next = head_copy->next;
free(head_copy);
return 1;
}
```
#### 反转函数 
```c
Node* fanzhuan(Node* head,Node* node_next){
if(node_next == NULL) return head;
Node* space = node_next->next;
node_next->next = head;
return fanzhuan(node_next,space); 
}
```
**标注** ：
- 其中node_next 为head->next
- 最后要写上head = fanzhuan(head);
- 用了递归但没用双指针
- 这是我的最先想到的思路,后
- 我在询问了AI后得到了双指针写法
- 下面是双指针写法  
**双指针** ：
```c
Node* fanzhuan(Node *head)
{
    Node *previous = NULL;
    Node *current = head;  

    while (current != NULL)
    {

        Node *next = current->next;
        current->next = previous;
     
        previous = current;
        current = next;
    }


    return previous;
}
```
- 最后补上head = fanzhuan(head);
  
- **后面又尝试自己写了** ：
  
```c
Node* fanzhuan(Node* head){
Node* next_node = head->next;
head->next = NULL;   
Node* current_node = head;
while(next_node != NULL){
Node* space = next_node->next;
next_node->next = current_node;
current_node = next_node;
next_node = space;
}
return current_node;
}
head = fanzhuan(head);
```

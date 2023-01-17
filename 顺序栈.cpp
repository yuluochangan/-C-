#include<stdio.h>
#include<stdlib.h>
#define maxsize 1000
#define n 5
struct Sqstack {
	int num[maxsize];
	int top=0;
};
typedef Sqstack stack;
typedef Sqstack* stackpoint;
void push(stackpoint* s,int newdata) {//压入新数据newdata
	stackpoint S = *s;
	if (S->top == maxsize - 1) {
		printf("栈已满");

	}
	S->top++;//栈顶向上一位
	S->num[S->top] = newdata;//新元素赋给栈顶
	
	

}
void pop(stackpoint* s, int *p) {
	stackpoint S = *s;
	*p = S->num[S->top];//栈顶数据保存到*p
	S->top--;//栈顶向下一位
}


void printstack(stackpoint* s,int m) {
	stackpoint S = *s;
	for (int i = 0; i < m; i++) {
		printf("%d\n", S->num[i]);
		S->top=i;
	}

}
int main() {
	int x;
	int *p=&x;
	stackpoint s = (stackpoint)malloc(sizeof(stack));//建立结构体并通过指针s对结构体进行操作
	for (int i = 0; i < n; i++) {
		s->num[i] = i;
	}
	printstack(&s, 5);
	push(&s, 10);
	pop(&s, p);
	printstack(&s, 6);
	printf("出栈元素为%d", *p);
	return 0;

}

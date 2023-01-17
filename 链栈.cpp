#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)；
struct Sqstack {
	int data;
	struct Sqstack* next;
	
};
typedef struct Sqstack stack;
typedef struct Sqstack* Lstackpoint;

void createtaillist(Lstackpoint* head, int n) {//尾插法方式创建链栈
	Lstackpoint p, r;

	*head = (Lstackpoint)malloc(sizeof(stack));
	r = *head;

	for (int i = 0; i < n; i++) {
		p = (Lstackpoint)malloc(sizeof(stack));
		printf("请输入栈数据：");
		scanf("%d", &p->data);
		r->next = p;
		r = p;

	}
	r->next = NULL;
}

void print(Lstackpoint* head) {
	Lstackpoint p = *head;
	p = p->next;
	printf("此时链栈自底自上为：");
	while (p) {
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
void push(Lstackpoint* head,int newdata) {//压入的新数据newdata
	Lstackpoint s;
	Lstackpoint p = *head;
	while (p->next) {
		p = p->next;
	}
	s= (Lstackpoint)malloc(sizeof(stack));
	s->data = newdata;
	s->next = p->next;
	p->next = s;
	
	
}
void pop(Lstackpoint* head) {//输出栈顶数据
	Lstackpoint p = *head;
	while (p->next) {
		p = p->next;
	}
	printf("此时栈顶元素为：%d", p->data);
}
int main() {
	Lstackpoint head;
	createtaillist(&head, 5);
	print(&head);
	printf("插入之后");
	push(&head, 6);
	print(&head);
	pop(&head);
}

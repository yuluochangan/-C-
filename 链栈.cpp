#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)��
struct Sqstack {
	int data;
	struct Sqstack* next;
	
};
typedef struct Sqstack stack;
typedef struct Sqstack* Lstackpoint;

void createtaillist(Lstackpoint* head, int n) {//β�巨��ʽ������ջ
	Lstackpoint p, r;

	*head = (Lstackpoint)malloc(sizeof(stack));
	r = *head;

	for (int i = 0; i < n; i++) {
		p = (Lstackpoint)malloc(sizeof(stack));
		printf("������ջ���ݣ�");
		scanf("%d", &p->data);
		r->next = p;
		r = p;

	}
	r->next = NULL;
}

void print(Lstackpoint* head) {
	Lstackpoint p = *head;
	p = p->next;
	printf("��ʱ��ջ�Ե�����Ϊ��");
	while (p) {
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}
void push(Lstackpoint* head,int newdata) {//ѹ���������newdata
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
void pop(Lstackpoint* head) {//���ջ������
	Lstackpoint p = *head;
	while (p->next) {
		p = p->next;
	}
	printf("��ʱջ��Ԫ��Ϊ��%d", p->data);
}
int main() {
	Lstackpoint head;
	createtaillist(&head, 5);
	print(&head);
	printf("����֮��");
	push(&head, 6);
	print(&head);
	pop(&head);
}

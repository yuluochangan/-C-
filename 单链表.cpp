#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)；
struct node {
	int data;
	struct node* next;
};

typedef struct node Node;
typedef struct node* List;

void createheadlist(List *head, int n) {
	
	List p;

	*head = (List)malloc(sizeof(Node));
	(*head)->next = NULL;
	(*head)->data = 0;
	for (int i = 0; i < n; i++) {
		p= (List)malloc(sizeof(Node));
		printf("请输入链表数据：");
		scanf("%d", &p->data);
		p ->next = (*head)->next;
		(*head)->next = p;

	}

}

void createtaillist(List* head, int n) {
	List p,r;
	
	*head = (List)malloc(sizeof(Node));
	r = *head;
	
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		printf("请输入链表数据：");
		scanf("%d", &p->data);
		r->next=p;
		 r= p;

	}
	r->next = NULL;
}
void print(List *head) {
	List p = *head;
	p= p->next;
	printf("此时链表为：");
	while (p) {
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}

void search(List* head,int m) {
	int cnt=0;
	List p = *head;
	while (p) {
		if (m == p->data) {
			printf("在第%d个结点\n",cnt);
			//p = p->next;
			break;
		}
		else {
			p = p->next;
			cnt++;
		}
		


	}
}

void deleteNode(List* head, int m) {
	List p = *head;
	List q;
	for (int i = 0; i < m-1; i++) {
		p = p->next;

	}
	q = p->next;
	p->next = p->next->next;
	free(q);
}

void addNode(List* head, int location,int newdata) {//头结点*head，插入结点位置location，插入数据data
	List p = *head;
	List s;
	q= (List)malloc(sizeof(Node));
	for (int i = 0; i < location - 1; i++) {
		p = p->next;

	}
	s->data = newdata;
	s->next = p->next;
	p->next = s;
}

int main() {
	List head;
	int n,m,z,location,newdata;
	head= (List)malloc(sizeof(Node));
	printf("请输入要创建的链表结点个数：");
	scanf("%d", &n);
	createtaillist(&head, n);
	//createheadlist(&head, n);
	print(&head);
	printf("请输入要查找的数字：");
	scanf("%d", &m);
	search(&head, m);

	printf("请输入要删除的位置：");
	scanf("%d", &z);
	deleteNode(&head, z);
	print(&head);
	printf("请输入要插入的结点的位置：");
	scanf("%d", &location);
	printf("请输入要插入的数据：");
	scanf("%d", &newdata);
	addNode(&head, location, newdata);
	print(&head);
	return 0;
}
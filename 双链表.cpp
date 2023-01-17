#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)；
struct node {
	int data;
	struct node* prior;
	struct node* next;
};
typedef struct node Node;
typedef struct node* List;

void createheadlist(List* head, int n) {

	List p,s;
	p = *head;//头结点
	p->prior = NULL;
	p->next = NULL;

	//采取头插法，第一个结点要先用尾插的方式插入
	if (p->next == NULL) {
		s = (List)malloc(sizeof(Node));
		p->next = s;//把s连在p的后面
		s->prior = p;//让p连在s的前面
		printf("请输入链表数据：");
		scanf("%d", &s->data);

	}

	
		for (int i = 0; i < n-1; i++) {
			s = (List)malloc(sizeof(Node));
			printf("请输入链表数据：");
			scanf("%d", &s->data);
			s->prior = p;
			s->next = p->next;
			p->next->prior = s;
			p->next = s;

		}
	

}

void createtaillist(List* head, int n) {
	List p,s;
	p = *head;
	for (int i = 1; i <= n; i++) {
		s = (List)malloc(sizeof(Node));
		s->prior = p;
		p->next = s;
		printf("请输入链表数据：");
		scanf("%d", &s->data);
		p = s;
	}
}

void print(List* head, int n) {
	List p;
	p = *head;
	printf("当前链表为：\n");
	for (int i = 1; i <= n; i++) {
		p = p->next;
		printf("结点%d数据为:%d\n", i,p->data);
	}
	
}


void search(List* head, int num) {
	List p;
	int cnt=0;
	p = *head;
	while (p) {
		
		if (num == p->data) {
			printf("该数据在%d个结点\n",cnt);
			break;
		}
		else {
			p = p->next;
			cnt++;
		}
	}
}


void addNode(List* head, int location, int newdata) {//插入数据
	List p, s;
	p = *head;
	for (int i = 0; i < location-1; i++) {//p移动到要插入 结点的前一个结点
		p = p->next;
	}
	s = (List)malloc(sizeof(Node));
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	s->data = newdata;
}

void deleteNode(List* head, int m) {
	List p, s;
	p = *head;
	for (int i = 0; i < m; i++) {//p移动到要删除结点
		p = p->next;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	s = p;
	free(s);
}



int main() {
	List head;
	int n,m,location,newdata,num;
	head = (List)malloc(sizeof(Node));
	
	
	printf("请输入结点数量：\n");
	scanf("%d", &n);
	//createheadlist(&head, n);
	createtaillist(&head, n);
	
	print(&head, n);
	printf("请输入要查找的数据：\n");
	scanf("%d", &num);
	search(&head,num);
	printf("请输入要插入的结点位置\n");
	scanf("%d", &location);
	printf("请输入要插入结点的数据\n");
	scanf("%d", &newdata);
	addNode(&head, location, newdata);
	print(&head, n);
	printf("要删除第几个结点：\n");
	scanf("%d", &m);
	deleteNode(&head, m);
	print(&head, n);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)��
struct node {
	int data;
	struct node* prior;
	struct node* next;
};
typedef struct node Node;
typedef struct node* List;

void createheadlist(List* head, int n) {

	List p,s;
	p = *head;//ͷ���
	p->prior = NULL;
	p->next = NULL;

	//��ȡͷ�巨����һ�����Ҫ����β��ķ�ʽ����
	if (p->next == NULL) {
		s = (List)malloc(sizeof(Node));
		p->next = s;//��s����p�ĺ���
		s->prior = p;//��p����s��ǰ��
		printf("�������������ݣ�");
		scanf("%d", &s->data);

	}

	
		for (int i = 0; i < n-1; i++) {
			s = (List)malloc(sizeof(Node));
			printf("�������������ݣ�");
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
		printf("�������������ݣ�");
		scanf("%d", &s->data);
		p = s;
	}
}

void print(List* head, int n) {
	List p;
	p = *head;
	printf("��ǰ����Ϊ��\n");
	for (int i = 1; i <= n; i++) {
		p = p->next;
		printf("���%d����Ϊ:%d\n", i,p->data);
	}
	
}


void search(List* head, int num) {
	List p;
	int cnt=0;
	p = *head;
	while (p) {
		
		if (num == p->data) {
			printf("��������%d�����\n",cnt);
			break;
		}
		else {
			p = p->next;
			cnt++;
		}
	}
}


void addNode(List* head, int location, int newdata) {//��������
	List p, s;
	p = *head;
	for (int i = 0; i < location-1; i++) {//p�ƶ���Ҫ���� ����ǰһ�����
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
	for (int i = 0; i < m; i++) {//p�ƶ���Ҫɾ�����
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
	
	
	printf("��������������\n");
	scanf("%d", &n);
	//createheadlist(&head, n);
	createtaillist(&head, n);
	
	print(&head, n);
	printf("������Ҫ���ҵ����ݣ�\n");
	scanf("%d", &num);
	search(&head,num);
	printf("������Ҫ����Ľ��λ��\n");
	scanf("%d", &location);
	printf("������Ҫ�����������\n");
	scanf("%d", &newdata);
	addNode(&head, location, newdata);
	print(&head, n);
	printf("Ҫɾ���ڼ�����㣺\n");
	scanf("%d", &m);
	deleteNode(&head, m);
	print(&head, n);
	return 0;
}

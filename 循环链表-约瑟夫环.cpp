#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)��
//Լɪ������ʵ��
typedef struct Node {
	int data;
	struct Node* next;
}Node, * Point;

void tailcreate(Point* head, int n) {//����������Ϊn������˼��Ϊ�����󵽣����ϰ��½���������β
	Point p, s;
	p = *head;//ѭ��ָ��p��ͷ��㿪ʼ
	for (int i = 2; i <= n; i++) {
		s = (Point)malloc(sizeof(Node));
		s->data = i;
		p->next = s;//���½������ͷ�ڵ�ĺ���
		p = s;//��ʱ�½��s��������Ľ�㣬����һ�������s�ĺ�����룬ѭ������
	}
	p->next = *head;
}
void find(Point* head, int lotcation, int num) {
	Point p = *head;
	Point s;
	for (int i = 0; i < lotcation - 1; i++) {//��ʱp�ƶ����˵�locationλ�õĽ��
		p = p->next;
	}
	printf("��%d�ſ�ʼ����\n", lotcation, p->data);//���Խ����洢�����Ƿ��Ӧ



	while (1) {
		if (p == p->next) {
			printf("���ʤ������%d", p->data);
			break;
		}
		else {
			for (int j = 0; j < num - 2; j++) {//��ʼ������p�ƶ�����ɾ���Ľ���ǰһ�����
				p = p->next;
			}
			printf("����������%d\n", p->next->data);
			s = p->next;
			p->next = p->next->next;//����ɾ�����ĺ�һ������뱻ɾ������ǰһ�������������
			free(s);//�ͷű�ɾ�����Ŀռ�
			p = p->next;//��ʱ��p�ƶ�����ɾ��������һ�����
		}

	}
}
int main() {
	Point head;
	int num, k, m;
	head = (Point)malloc(sizeof(Node));/*����һ��Node���ʹ�С���ڴ棬
			��ǿ��ת��Ϊ���ָ�����ͣ�����ͷ���head*/
	head->data = 1;
	head->next = NULL;


	printf("����������\n");
	scanf("%d", &num);
	printf("�ӱ�ż���ʼ��\n");
	scanf("%d", &k);
	printf("�������ĳ��У�\n");
	scanf("%d", &m);

	tailcreate(&head, num);
	find(&head, k, m);


	return 0;



}

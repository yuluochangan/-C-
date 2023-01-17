#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)；
//约瑟夫环问题实现
typedef struct Node {
	int data;
	struct Node* next;
}Node, * Point;

void tailcreate(Point* head, int n) {//创建结点个数为n的链表思想为先来后到，不断把新结点放在链表尾
	Point p, s;
	p = *head;//循环指针p从头结点开始
	for (int i = 2; i <= n; i++) {
		s = (Point)malloc(sizeof(Node));
		s->data = i;
		p->next = s;//把新结点连在头节点的后面
		p = s;//此时新结点s变成了最后的结点，让下一个结点在s的后面插入，循环往复
	}
	p->next = *head;
}
void find(Point* head, int lotcation, int num) {
	Point p = *head;
	Point s;
	for (int i = 0; i < lotcation - 1; i++) {//此时p移动到了第location位置的结点
		p = p->next;
	}
	printf("从%d号开始计数\n", lotcation, p->data);//测试结点与存储数据是否对应



	while (1) {
		if (p == p->next) {
			printf("最后胜利者是%d", p->data);
			break;
		}
		else {
			for (int j = 0; j < num - 2; j++) {//开始计数，p移动到被删除的结点的前一个结点
				p = p->next;
			}
			printf("出列数据是%d\n", p->next->data);
			s = p->next;
			p->next = p->next->next;//将被删除结点的后一个结点与被删除结点的前一个结点链接起来
			free(s);//释放被删除结点的空间
			p = p->next;//此时让p移动到被删除结点的下一个结点
		}

	}
}
int main() {
	Point head;
	int num, k, m;
	head = (Point)malloc(sizeof(Node));/*申请一块Node类型大小的内存，
			并强制转化为结点指针类型，创建头结点head*/
	head->data = 1;
	head->next = NULL;


	printf("参与人数：\n");
	scanf("%d", &num);
	printf("从编号几开始：\n");
	scanf("%d", &k);
	printf("数到几的出列：\n");
	scanf("%d", &m);

	tailcreate(&head, num);
	find(&head, k, m);


	return 0;



}

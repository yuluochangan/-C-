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
void push(stackpoint* s,int newdata) {//ѹ��������newdata
	stackpoint S = *s;
	if (S->top == maxsize - 1) {
		printf("ջ����");

	}
	S->top++;//ջ������һλ
	S->num[S->top] = newdata;//��Ԫ�ظ���ջ��
	
	

}
void pop(stackpoint* s, int *p) {
	stackpoint S = *s;
	*p = S->num[S->top];//ջ�����ݱ��浽*p
	S->top--;//ջ������һλ
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
	stackpoint s = (stackpoint)malloc(sizeof(stack));//�����ṹ�岢ͨ��ָ��s�Խṹ����в���
	for (int i = 0; i < n; i++) {
		s->num[i] = i;
	}
	printstack(&s, 5);
	push(&s, 10);
	pop(&s, p);
	printstack(&s, 6);
	printf("��ջԪ��Ϊ%d", *p);
	return 0;

}

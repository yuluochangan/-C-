#include<stdio.h>
#define maxsize 20
#define len 10
typedef struct {
	int data[maxsize];
	int length;
}sqlist,* sqlistpoint;

/*Ҫ�����λ��location��Ҫ���������n_data*/
int insert(sqlistpoint p, int location, int n_data) {

	for (int i = len; i >=location; i--) {
		p->data[i + 1] = p->data[i];
	}
	p->data[location] = n_data;
	return 0;

}
/*Ҫ���ҵ�����searchdata*/
int search(sqlistpoint p, int searchdata) {
	for (int i = 0; i < len; i++) {
		if (p->data[i] == searchdata)
			printf("����ҵ������±�Ϊ%d\n", i);
	}
	return 0;
}
/*Ҫɾ��������λ��location*/
int deletedata(sqlistpoint p, int location) {
	for (int i = location; i <len; i++) {
		p->data[i] = p->data[i+1];
	}
	return 0;
}

	

int main() {
	sqlist a;
	sqlistpoint p= &a;
	for (int i = 0; i < len; i++) {
		p->data[i] = i;
		printf("a.data[%d]=%d\n", i, p->data[i]);
	}
	
	//insert(p, 3, 10);���Բ���
	//deletedata(p, 3);����ɾ��
	//search(p, 3);���Բ���
	for (int i = 0; i < len; i++) {
		
		printf("a.data[%d]=%d\n", i, p->data[i]);
	}
}

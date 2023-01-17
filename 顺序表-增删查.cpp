#include<stdio.h>
#define maxsize 20
#define len 10
typedef struct {
	int data[maxsize];
	int length;
}sqlist,* sqlistpoint;

/*要插入的位置location，要插入的数据n_data*/
int insert(sqlistpoint p, int location, int n_data) {

	for (int i = len; i >=location; i--) {
		p->data[i + 1] = p->data[i];
	}
	p->data[location] = n_data;
	return 0;

}
/*要查找的数据searchdata*/
int search(sqlistpoint p, int searchdata) {
	for (int i = 0; i < len; i++) {
		if (p->data[i] == searchdata)
			printf("你查找的数据下标为%d\n", i);
	}
	return 0;
}
/*要删除的数据位置location*/
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
	
	//insert(p, 3, 10);测试插入
	//deletedata(p, 3);测试删除
	//search(p, 3);测试查找
	for (int i = 0; i < len; i++) {
		
		printf("a.data[%d]=%d\n", i, p->data[i]);
	}
}

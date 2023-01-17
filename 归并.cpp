#include<stdio.h>
void Msort(int a[],int left,int mid,int right,int temp[]) {//数组num分为从s到m以及从m+1到e两个部分

	/*int left = 0;
	int right = size - 1;
	int mid = left + (right - left) / 2;*/
	int p = 0;//数组temp的下标，从0开始
	int p1 = left, p2 = mid + 1;//将数组a分为两份，p1为前半截，p2为后半截
	while (p1<=mid&&p2<=right)//将p1与p2遍历比较，将较小的放入temp数组
	{
		if (a[p1] < a[p2])
			temp[p++] = a[p1++];//等价于将a[p1]的值赋给temp[p]后，p1++,p++
		else
			temp[p++] = a[p2++];//同上,当此处运行结束后，有一半的数组元素已经放入了temp

	}
	while (p1 <= mid)//将p1中剩余的值放入temp
		temp[p++] = a[p1++];
	while (p2 <= right)//将p2中剩余的值放入temp
		temp[p++] = a[p2++];
	for (int i = 0; i < right - left + 1; i++) {//将temp数组拷贝到a数组
		a[left + i] = temp[i];
	}

}
void sort(int a[], int left, int right, int temp[]) {
	if (left < right) {
		int m = left + (right - left) / 2;//取中点
		sort(a, left, m, temp);//对前一半进行归并排序
		sort(a, m + 1, right, temp);//对后一半进行归并排序
		Msort(a, left, m, right, temp);//将p1,p2进行合并，并返回到a
	}
}
int main() {
	int a[8] = { 13,27,19,2,8,12,30,89 };
	int b[8];
	int size = 8;
	sort(a, 0, size - 1, b);
	for (int i = 0; i < size; i++) {
		printf("%d  ", a[i]);
	}
	return 0;
}

#include<stdio.h>
void Msort(int a[],int left,int mid,int right,int temp[]) {//����num��Ϊ��s��m�Լ���m+1��e��������

	/*int left = 0;
	int right = size - 1;
	int mid = left + (right - left) / 2;*/
	int p = 0;//����temp���±꣬��0��ʼ
	int p1 = left, p2 = mid + 1;//������a��Ϊ���ݣ�p1Ϊǰ��أ�p2Ϊ����
	while (p1<=mid&&p2<=right)//��p1��p2�����Ƚϣ�����С�ķ���temp����
	{
		if (a[p1] < a[p2])
			temp[p++] = a[p1++];//�ȼ��ڽ�a[p1]��ֵ����temp[p]��p1++,p++
		else
			temp[p++] = a[p2++];//ͬ��,���˴����н�������һ�������Ԫ���Ѿ�������temp

	}
	while (p1 <= mid)//��p1��ʣ���ֵ����temp
		temp[p++] = a[p1++];
	while (p2 <= right)//��p2��ʣ���ֵ����temp
		temp[p++] = a[p2++];
	for (int i = 0; i < right - left + 1; i++) {//��temp���鿽����a����
		a[left + i] = temp[i];
	}

}
void sort(int a[], int left, int right, int temp[]) {
	if (left < right) {
		int m = left + (right - left) / 2;//ȡ�е�
		sort(a, left, m, temp);//��ǰһ����й鲢����
		sort(a, m + 1, right, temp);//�Ժ�һ����й鲢����
		Msort(a, left, m, right, temp);//��p1,p2���кϲ��������ص�a
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

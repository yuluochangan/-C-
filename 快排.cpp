#include<stdio.h>
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void quicksort(int a[],int left,int right){
	if (left > right)
		return;
	int k = a[left];
	int i = left;
	int j = right;
	while (i != j) {
		while (i < j && k <= a[j])
			j--;
		swap(a[i], a[j]);
		while (i < j && a[i] <= k)
			i++;
		swap(a[i], a[j]);
		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);
	}
}
int main() {
	int a[] = { 13,27,19,2,8,12,30,89 };
	int left = 0;
	int right = sizeof(a) / 4;
	quicksort(a, left, right - 1);
	for (int i = 0; i < right; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}

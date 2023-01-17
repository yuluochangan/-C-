#include<stdio.h>
int search(int a[],int size,int target){
	int left=0;
	int right=size-1;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(a[mid]==target)
		  return mid; 
		else if(target>a[mid])
		    left=mid+1;
		else
		    right=mid-1;
		
	}
	return -1;
}
int main(){
	int a[5]={1,2,3,4,5};
	
	printf("%d",search(a,5,3));
	return 0;
}

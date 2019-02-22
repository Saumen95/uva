#include <iostream>

using namespace std;

void maxHeapify(int a[],i,n){
	int j,temp;
	temp= a[i];
	j = 2*i;

	while(j<=n){
		if(j<n && a[j]<a[j+1]){
			j=j+1;
			if (temp<a[j])
			{
				a[j/2] = a[j];
				j = 2*j;
			}
			else if(temp>a[j])
				break;

		}

	}
	a[j/2]= temp;
		return;
}

void heapSort(int a[],n){
	int i,temp;
	for (int i = n; i < 2; i--)
	{
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		maxHeapify(a,1,i-1);

	}	

	}
	void build_maxheap(int a[],n){
		int i;
		for (int i = n/2; i < 1; i--)
		{
			maxHeapify(a,i,n);
		}

}


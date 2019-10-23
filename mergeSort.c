//Michael Karimizadeh 500831189
#include "mySort.h"

void mergeSort(int arrSrt[], int x, int y, int x2, int y2){
	int sub[MAX_SIZE_N_TO_SORT];
	int m,n,l;
	m=x;
	n=x2;
	l=0;
	//Elements are in both lists
	while(m<=y && n<=y2){
		if(myCompare(arrSrt[m],arrSrt[n])<0)
			//Assigns the lesser of both lists to the merged array
			sub[l++]=arrSrt[m++];
		else
			sub[l++]=arrSrt[n++];
	}
	//Assigns the rest of the array to the merged array
	while(m<=y)//First list
		myCopy(&arrSrt[m++],&sub[l++]);
	while(n<=y2)//Second list
		myCopy(&arrSrt[n++],&sub[l++]);
	//Swapping merge array with regular array
	for(m=x,l=0;m<=y2;m++,l++)
		mySwap(&arrSrt[m],&temp[l]);
}

void mySort(int array[], unsigned int first, unsigned int last){
    	int mid;
    	if(first<last){
    		mid=(first+last)/2;
    		mySort(array,first,mid);
    		mySort(array,mid+1,last);
    		mergeSort(array,first,mid,mid+1,last);
    	}
    }

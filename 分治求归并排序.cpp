#include <cstdio>
#include <iostream>
 //给你学分治思想的不是学归并排序的，你的任务就是看懂分治思想 
using namespace std;
 
 //数组，左子树，左子树的长度，右子树，右子树的长度 
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	i = 0; j = 0; k =0;
 
	while(i<leftCount && j< rightCount) {//当左右两个子树都没有读到相应位置的时候 
		if(L[i]  < R[j]) {//比较左右两个数的值谁比较小，小的先插入 
			A[k++] = L[i++];
			//由于经过很多遍的分治，所以无论左子树还是右子树，里面的结构都已经排序好了，所以只要简单的让数组等于下一个就好了 
		}
		else {
			A[k++] = R[j++];
		}
	}
	while(i < leftCount){//左子树没有读完，但是右子树读完的情况 
		A[k++] = L[i++];
	} 
	while(j < rightCount) {//右子树没有读完但是左子树已经读完的情况 
		A[k++] = R[j++];
	}
}
 
 //a是要排的数组，n是数组长度 
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) {
			 return; //当数据小于2的时候就没意义无法使用归并了	
	}  
	mid = n/2;  //中间的那个数 
 
	L = new int[mid];//数组左边的数组 
	R = new int [n - mid];//数组右边的数组 
 
	for(i = 0;i<mid;i++) {
		L[i] = A[i]; 
	} 
	for(i = mid;i<n;i++){
		R[i-mid] = A[i];  
	} 
	//给左右两个数组附上要排序的数组的左右两个的值 
 
	MergeSort(L,mid);  //继续重复分裂 
	MergeSort(R,n-mid);  //继续重复分裂 
	Merge(A,L,mid,R,n-mid);    //排序 
	cout<<endl;
	cout << "-------------------------" << endl;
	cout << "经过这次递归排序后的数组模样" << endl;
	for(i = 0;i < n;i++){
		cout << " " << A[i];
	}
	cout<<endl;
	delete [] R;//删除左右数组 
	delete [] L;
}
 
int main() { 
 
	int A[] = {6,2,3,1,9,10,15,13,12,17};  //这个是待排序的数组 
	int i,numberOfElements; //numberOfElements，记录一下数组的长度 
	numberOfElements = sizeof(A) / sizeof( A[0] ); //sizeof判断变量或数据类型的字节大小
	MergeSort(A,numberOfElements);//归并排序 
	cout << "已经排好的数组" << endl;
	for(i = 0;i < numberOfElements;i++){
		cout << " " << A[i];
	}
	   
	return 0;
}




//真正的分治法核心思想来了，这个才是核心思想啊，记住这个你就记住分治法了 
//代码执行顺序是这样的，先分，分到不能再分了再继续执行合代码 
int init(int a[],n){
	int mid,i, *L, *R;
	if(n < 2) {
		return; //当数据小于2的时候就没意义,无法进行“分 ”的操作了，可以结束递归了 
	}  
	mid = n/2;  //中间的那个数 
 
	L = new int[mid];//数组左边的数组 
	R = new int [n - mid];//数组右边的数组 
 
 	//给左右两个数组附上要排序的数组的左右两个的值 
	for(i = 0;i<mid;i++) {
		L[i] = A[i]; 
	} 
	for(i = mid;i<n;i++){
		R[i-mid] = A[i];  
	} 
	
 
	MergeSort(L,mid);  		//继续对左部分进行递归操作，不停的分下去直到分到不能再分 
	MergeSort(R,n-mid);  	//继续对右部分进行递归操作，不停的分下去直到分到不能再分
	Merge(A,L,mid,R,n-mid); //当最后的一次结束递归后，就可以执行到这一步，也就是对“分开的 ”两个数组进行和并操作 
	cout<<endl;
	 
	 
	delete [] R;//删除左右数组 
	delete [] L;
} 




















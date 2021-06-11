#include <cstdio>
#include <iostream>
 //����ѧ����˼��Ĳ���ѧ�鲢����ģ����������ǿ�������˼�� 
using namespace std;
 
 //���飬���������������ĳ��ȣ����������������ĳ��� 
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	i = 0; j = 0; k =0;
 
	while(i<leftCount && j< rightCount) {//����������������û�ж�����Ӧλ�õ�ʱ�� 
		if(L[i]  < R[j]) {//�Ƚ�������������ֵ˭�Ƚ�С��С���Ȳ��� 
			A[k++] = L[i++];
			//���ھ����ܶ��ķ��Σ�������������������������������Ľṹ���Ѿ�������ˣ�����ֻҪ�򵥵������������һ���ͺ��� 
		}
		else {
			A[k++] = R[j++];
		}
	}
	while(i < leftCount){//������û�ж��꣬������������������ 
		A[k++] = L[i++];
	} 
	while(j < rightCount) {//������û�ж��굫���������Ѿ��������� 
		A[k++] = R[j++];
	}
}
 
 //a��Ҫ�ŵ����飬n�����鳤�� 
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) {
			 return; //������С��2��ʱ���û�����޷�ʹ�ù鲢��	
	}  
	mid = n/2;  //�м���Ǹ��� 
 
	L = new int[mid];//������ߵ����� 
	R = new int [n - mid];//�����ұߵ����� 
 
	for(i = 0;i<mid;i++) {
		L[i] = A[i]; 
	} 
	for(i = mid;i<n;i++){
		R[i-mid] = A[i];  
	} 
	//�������������鸽��Ҫ��������������������ֵ 
 
	MergeSort(L,mid);  //�����ظ����� 
	MergeSort(R,n-mid);  //�����ظ����� 
	Merge(A,L,mid,R,n-mid);    //���� 
	cout<<endl;
	cout << "-------------------------" << endl;
	cout << "������εݹ�����������ģ��" << endl;
	for(i = 0;i < n;i++){
		cout << " " << A[i];
	}
	cout<<endl;
	delete [] R;//ɾ���������� 
	delete [] L;
}
 
int main() { 
 
	int A[] = {6,2,3,1,9,10,15,13,12,17};  //����Ǵ���������� 
	int i,numberOfElements; //numberOfElements����¼һ������ĳ��� 
	numberOfElements = sizeof(A) / sizeof( A[0] ); //sizeof�жϱ������������͵��ֽڴ�С
	MergeSort(A,numberOfElements);//�鲢���� 
	cout << "�Ѿ��źõ�����" << endl;
	for(i = 0;i < numberOfElements;i++){
		cout << " " << A[i];
	}
	   
	return 0;
}




//�����ķ��η�����˼�����ˣ�������Ǻ���˼�밡����ס�����ͼ�ס���η��� 
//����ִ��˳���������ģ��ȷ֣��ֵ������ٷ����ټ���ִ�кϴ��� 
int init(int a[],n){
	int mid,i, *L, *R;
	if(n < 2) {
		return; //������С��2��ʱ���û����,�޷����С��� ���Ĳ����ˣ����Խ����ݹ��� 
	}  
	mid = n/2;  //�м���Ǹ��� 
 
	L = new int[mid];//������ߵ����� 
	R = new int [n - mid];//�����ұߵ����� 
 
 	//�������������鸽��Ҫ��������������������ֵ 
	for(i = 0;i<mid;i++) {
		L[i] = A[i]; 
	} 
	for(i = mid;i<n;i++){
		R[i-mid] = A[i];  
	} 
	
 
	MergeSort(L,mid);  		//�������󲿷ֽ��еݹ��������ͣ�ķ���ȥֱ���ֵ������ٷ� 
	MergeSort(R,n-mid);  	//�������Ҳ��ֽ��еݹ��������ͣ�ķ���ȥֱ���ֵ������ٷ�
	Merge(A,L,mid,R,n-mid); //������һ�ν����ݹ�󣬾Ϳ���ִ�е���һ����Ҳ���Ƕԡ��ֿ��� ������������кͲ����� 
	cout<<endl;
	 
	 
	delete [] R;//ɾ���������� 
	delete [] L;
} 




















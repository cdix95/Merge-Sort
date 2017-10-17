#include <iostream>
#include <cassert>

using namespace std;


void msort(int a[], int x[], int s, int e) {
    int m=(s+e)/2;
    if(e-s<1)return;
    msort(a,x,s,m);
    msort(a,x,m+1,e);
    int i=s,j=m+1,k=0;
    while(i<=m && j<=e){
        if(a[i]<a[j]){
            x[k]=a[i];
            i++;
            k++;
        }
        else{
            x[k]=a[j];
            j++;
            k++;
        }
    }
	
    while(i<=m){
        x[k]=a[i];
        i++;
        k++;
    }
	
    while(j<=e){
        x[k]=a[j];
        j++;
        k++;
    }
	
    for(int i=s;i<=e;i++){
        a[i]=x[i-s];
    }
}

void mergesort(int a[], int n) {
    int *x=new int[n];
    msort(a,x,0,n-1);
    delete[] x;
}

bool sorted(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1])return false;
	}
	return true;
}

int main(int argc, char * args[]) {
	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = rand() % 100;
	mergesort(a, 1000);
	assert(sorted(a, 1000));

	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));

	int c[] = { 7 };
	mergesort(c, 1);
	assert(sorted(c, 1));

	int d[] = { 43, 7, -46, 57, 11 };
	mergesort(d, 5);
	assert(sorted(d, 5));
	
    
	cout << "All tests passed." << endl;	
}

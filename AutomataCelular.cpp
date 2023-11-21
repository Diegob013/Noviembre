#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;

void reglas(int a[],int b[],int i, int key[],int n);

int * llenararreglo(int i,int n,int a[]);

int * binario(int m, int key[]);

int main(){

	srand(time(NULL));
	int n,m;

	do{
	cout<<"Ingrese la regla del automata (1 - 255)"<<endl;
	cin>>m;
	if(m<1 || m>255)
	system("cls");
	}while(m<1 || m>255);

	cout<<"Ingrese el tamano de su arreglo"<<endl;
	cin>>n;

	int a[n];
	int b[n];
	int i,key[8];

	llenararreglo(i,n,a);
	
	binario(m,key);
	
	/*for(i=0;i<8;i++)
		cout<<key[i];
	cout<<endl;*/

	reglas(a,b,i,key,n);

	getch();
	return 0;
}

int * llenararreglo(int i,int n,int a[]){
	int u;
	do{
	cout<<"Desea un solo 1 en el centro (1) o con arreglo aleatorio (2)"<<endl;
	cin>>u;
	if(u==1){
		for(i=0;i<n/2;i++){
			a[i]=0;
		}
		a[n/2]=1;
		for(i=n;i>n/2;i--){
			a[i]=0;
		}
		for(i=0;i<n;i++){
			cout<<a[i];
		}
	}
	if(u==2){
		for(i=0;i<n;i++){
			a[i]=rand()%2;
			cout<<a[i];
		}
	}
	if(u>2 || u<1)
	system("cls");
	}while(u>2 || u<1);
	cout<<endl;
	return a;
}

int * binario(int m, int key[]){
	int l=0;
	while(m!=0){
		key[7-l]=m%2;
		m/=2;
		l++;
	}
	if(l<8)
		while(l<8){
			key[7-l]=0;
			l++;
		}
	return key;
}

void reglas(int a[],int b[],int i, int key[],int n){
	int j,k;
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
		if(i==0){
			if(a[n-1]==0 && a[i]==0 && a[i+1]==0)
				b[i]=key[0];
		
			if(a[n-1]==0 && a[i]==0 && a[i+1]==1)
				b[i]=key[1];
		
			if(a[n-1]==0 && a[i]==1 && a[i+1]==0)
				b[i]=key[2];
		
			if(a[n-1]==0 && a[i]==1 && a[i+1]==1)
				b[i]=key[3];
		
			if(a[n-1]==1 && a[i]==0 && a[i+1]==0)
				b[i]=key[4];
		
			if(a[n-1]==1 && a[i]==0 && a[i+1]==1)
				b[i]=key[5];
		
			if(a[n-1]==1 && a[i]==1 && a[i+1]==0)
				b[i]=key[6];

			if(a[n-1]==1 && a[i]==1 && a[i+1]==1)
				b[i]=key[7];
		}
		
		if(i==n-1){
			if(a[i-1]==0 && a[i]==0 && a[0]==0)
				b[i]=key[0];
			
			if(a[i-1]==0 && a[i]==0 && a[0]==1)
				b[i]=key[1];
			
			if(a[i-1]==0 && a[i]==1 && a[0]==0)
				b[i]=key[2];
			
			if(a[i-1]==0 && a[i]==1 && a[0]==1)
				b[i]=key[3];
			
			if(a[i-1]==1 && a[i]==0 && a[0]==0)
				b[i]=key[4];
			
			if(a[i-1]==1 && a[i]==0 && a[0]==1)
				b[i]=key[5];
			
			if(a[i-1]==1 && a[i]==1 && a[0]==0)
				b[i]=key[6];

			if(a[i-1]==1 && a[i]==1 && a[0]==1)
				b[i]=key[7];
		}
			else{
				if(a[i-1]==0 && a[i]==0 && a[i+1]==0)
					b[i]=key[0];
					
				if(a[i-1]==0 && a[i]==0 && a[i+1]==1)
					b[i]=key[1];
					
				if(a[i-1]==0 && a[i]==1 && a[i+1]==0)
					b[i]=key[2];
					
				if(a[i-1]==0 && a[i]==1 && a[i+1]==1)
					b[i]=key[3];
					
				if(a[i-1]==1 && a[i]==0 && a[i+1]==0)
					b[i]=key[4];
					
				if(a[i-1]==1 && a[i]==0 && a[i+1]==1)
					b[i]=key[5];
					
				if(a[i-1]==1 && a[i]==1 && a[i+1]==0)
					b[i]=key[6];

				if(a[i-1]==1 && a[i]==1 && a[i+1]==1)
					b[i]=key[7];	
				}
		}
	for(k=0;k<n;k++){
		if(b[k]==0)
		cout<<" ";
		else
		cout<<b[k];
		a[k]=b[k];
	}
	cout<<endl;
	}
}
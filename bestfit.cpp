#include<iostream>
using namespace std;
class memory{
private:
int s1; //number of memory blocks
int s2; //number of processes
double* m; //array to store memory block
double* p; //array to store processes

public:
	
	memory(){ //constructor
	s1=s2=0;
	}
	void input(){ //function to take input from user
		cout<<"\n\n\t\tEnter Number of Memory blocks : ";
		cin>>s1;
		m=new double[s1];
		for(int i=0;i<s1;i++){
		cout<<"\n\t\tEnter size of Memory block "<<i+1<<" : ";
		cin>>m[i];
	}
		cout<<"\n\n\t\tEnter Number of processes : ";
		cin>>s2;
		p=new double[s2];
		for(int i=0;i<s2;i++){
		cout<<"\n\t\tEnter size Process "<<i+1<<" : ";
		cin>>p[i];
	}
	first_fit();
	best_fit();
	worst_fit();
	}
	void first_fit(){ //to show first fit memory allocation
		double *temp1; //temperary array to store memory sizes
		temp1=new double[s1];
		for(int i=0;i<s1;i++){
			temp1[i]=m[i];
		}
		int* a; //array to memory allocation
		a=new int[s2];
		for(int i=0;i<s2;i++){
			for(int j=0;j<s1;j++){
				if(temp1[j]>=p[i]){
					a[i]=j+1;
					temp1[j]=temp1[j]-p[i];
					break;
				}else a[i]=-1;
		}
	}
	cout<<"\n\n\t\t----------------FIRST FIT--------------"<<endl;
	display(a);
	}
	
	void best_fit(){
	double *temp1;
	temp1=new double[s1];
		for(int i=0;i<s1;i++){
			temp1[i]=m[i];
		}
	int* a;
	a=new int[s2];
	for(int i=0;i<s2;i++){
		int min=-1;
		for(int j=0;j<s1;j++){
			if(temp1[j]>=p[i]){
				if(min==-1)min=j;
				else if(temp1[min]>temp1[j])min=j;
			}
		}
		if(min!=-1){
		a[i]=min+1;
		temp1[min]=temp1[min]-p[i];
		}
		else a[i]=-1;
	}
	cout<<"\n\n\t\t----------------BEST FIT--------------"<<endl;
	display(a);
	}
	
	void worst_fit(){
		double *temp1;
		temp1=new double[s1];
		for(int i=0;i<s1;i++){
			temp1[i]=m[i];
		}
		int* a;
		a=new int[s2];
		for(int i=0;i<s2;i++){
			int max=-1;
			for(int j=0;j<s1;j++){
				if(temp1[j]>=p[i]){
					if(max==-1)max=j;
					else if(temp1[max]<temp1[j])max=j;
				}
			}
			if(max!=-1){
				a[i]=max+1;
				temp1[max]=temp1[max]-p[i];
			}
			else a[i]=-1;
		}
	cout<<"\n\n\t\t----------------WORST FIT--------------"<<endl;
	display(a);
	}
	
	void display(int a[]){
		cout<<"\n\n\t\tPROCESS\t\tMEMORY BLOCK"<<endl;
		for(int i=0;i<s2;i++){
			if(a[i]>0)
				cout<<"\n\t\t"<<p[i]<<"\t\t"<<a[i]<<endl;
		else 
			cout<<"\n\t\t"<<p[i]<<"\t\tNot Allocated"<<endl;
}
}
};
int main(){
memory m;
m.input();
}

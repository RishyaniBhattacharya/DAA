#include<iostream>
using namespace std;
#define  size 10

class Queue{
	private:
		int q[10][size];
		int front[10];
		int rear[10];
		
		int remove(int k){
			int item;
			item=q[k][front[k]];
			if(front[k]==rear[k])
				front[k]=rear[k]=-1;
			else
				front[k]= (front[k]+1);
			
			return item;
			
		}
	public:
		Queue(){
			int i;
			for(i=0;i<10;i++){
				front[i]=rear[i]=-1;
			}
		}
		
		
	void Enqueue(int item, int k){
			if( front[k]==rear[k]+1 || front[k]==0 && rear[k]==99)
				cout<<"Queue "<<k <<" is full";
			else if(front[k]==-1){
				front[k]=rear[k]=0;
				
			}
			else
				rear[k]= (rear[k]+1) % 100;
			
			q[k][rear[k]]=item;
				
			
		}
		
		int *Dequeue()
		{
			int *p=new int[size];
			int k=0;
			for(int i=0;i<10;i++){
				while(front[i]!=-1){
					p[k]=remove(i);
					k++;
				}
			}
			return p;
			
		}
		
};

int main(){
	Queue ob;

	int *a= new int[size];

	for(int i=0;i<size;i++){
		cout<<"Enter element at "<<i<<" th index: "<<endl;
		cin>>a[i];
	}
	
	int x=1;
	int d=10;

	for(int i=1;i<=3;i++){
		for(int j=0;j<size;j++){
			int digit= a[j]%d/x;
			ob.Enqueue(a[j],digit);
		}
		
		a=ob.Dequeue();
		
		x*=10;
		d = d*10;
	}

	cout<<"sorted list"<<endl;

	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}

	cout<<endl;
	
}

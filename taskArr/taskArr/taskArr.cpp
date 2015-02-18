// taskArr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

class CTestArray{
private:
	int *arr;
	int last;
public:
	//constructor
	CTestArray()
	{
		last = 0;
	}
	
	// copy constructor
	CTestArray(const CTestArray & m){
		last = m.last;
		for(int i = 0; i < m.last; ++i){
		    arr = new int[last];
			memcpy(arr+i,m.arr+i,sizeof(int));
		}   
	}
	//printing on Display
	void printArr(){
	    for(int i = 0;i < last; ++i){
		    cout<<arr[i]<<" ";
	    }
		cout<<endl;
	}
	//Dobavka
	CTestArray Add(int elem)
	{
		if(last == 0){
		   arr = new int[1];
		   arr[last] = elem;
		   last = 1;
		}
		else{
            last +=1;
			int* arr1 = new int[last];
			for(int i = 0; i < last - 1; ++i){
			    arr1[i] = arr[i];
			}
			arr1[last-1] = elem;
			arr = arr1;
		}
		return *this;	
	}
	//Vstavka
	CTestArray Insert(int index,int value){
		last += 1;
		int* arr1 = new int[last];
		for(int i = 0; i < index; ++i){
			    arr1[i] = arr[i];
			}
		for(int i = index+1;i < last; ++i){
			arr1[i] = arr[i-1];
		}
		arr1[index] = value;
		arr = arr1;
		return *this;
	
	}
	//Ydalenie
	CTestArray Delete(int index){
	    last -= 1;
		int*arr1 = new int[last];
		for(int i = 0; i < index; ++i){
			    arr1[i] = arr[i];
			}
		for(int i = index;i < last; ++i){
			arr1[i] = arr[i+1];
		}
		arr = arr1;
	    return *this;
	}
	//sortirovka po vosrastaniu
	CTestArray sortArr(){
	    qsort(arr, last, sizeof(int), comp);
	    return *this;
	}
	//ochistka
	void clearArr(){
	    int *arr1 = new int;
		last = 0;
	    arr = arr1;
	}
	
};


int _tmain(int argc, _TCHAR* argv[])
{   CTestArray m,n;
    m.Add(100);
	m.Add(500);
	m.Add(3);
	m.printArr();
	m.Insert(0,7);
	m.printArr();
	m.Delete(0);
	m.printArr();
	m.sortArr();
	m.printArr();
	n = m;
    n.printArr();
	n.clearArr();
    n.printArr();
	system("PAUSE");
	return 0;
}

int comp(const void *i, const void *j)
{
  return *(int *)i - *(int *)j;
}


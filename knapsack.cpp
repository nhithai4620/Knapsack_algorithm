#include <bits/stdc++.h>
using namespace std;

struct Item 
{
	int value;
	int weight;
};

bool Sosanh(Item a, Item b){
	double r1 = (double)a.value/a.weight;
	double r2 = (double)b.value/b.weight;
	return r1>r2 ;
}

double Knapsack(Item arr[],int size,int weight){
	sort(arr,arr + size,Sosanh);
	int currentkg = 0;
	double totalvl = 0;
	for (int i = 0; i < size; i++){
		if (currentkg + arr[i].weight <= weight){
			currentkg += arr[i].weight;
			totalvl += arr[i].value;
		}
		else {
			int remainkg = weight - currentkg;
			totalvl += arr[i].value *((double)remainkg/arr[i].weight);
			break;	
		}
	}
	return totalvl;
}
int main(){
	int size , weight;
	cin >> size >> weight;
	Item *arr = new Item[size];
	  for (int i = 0; i < size; i++) {
        cin >> arr[i].weight;
    }
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i].value;
    }
    cout << setprecision(4) << fixed << Knapsack(arr, size, weight) << endl;
    delete[] arr;
    return 0;
}

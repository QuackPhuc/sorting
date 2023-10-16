#include<iostream>
#include<random>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b; 
    b = tmp;
}
int partition(int array[], int left, int right)
{
    int i = left - 1;
    for(int j = left; j < right; j++)
    {
        if(array[j] < array[right])
            swap(array[++i],array[j]);
    }
    swap(array[right],array[i+1]);
    return i + 1;
}

void Quick_Sort(int array[], int left, int right)
{
    if(left >= right)
        return;
    int pivot = partition(array, left, right);
    Quick_Sort(array, left, pivot - 1);
    Quick_Sort(array, pivot + 1, right);
}
int main()
{
    int array[20];
    for(int i = 0; i < 20; i++)
    {
        array[i] = int(rand() % 5000);
        cout<<array[i]<<" ";
    }
    Quick_Sort(array,0,19);
    cout<<endl;
    for(int i = 0; i < 20; i++)
        cout<<array[i]<<" ";

    
}
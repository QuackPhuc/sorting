#include<iostream>
#include<random>
using namespace std;

int Max(int array[], int size)
{
    int max = array[0];
    for(int i = 1; i < size; i++)
    {
        if(array[i] > max) max = array[i];
    }
    return max;
};

void Multi(int array[], int size, int num)
{
    for(int i = 0; i < size; i++) array[i] = num;
}

void Counter_sort(int array[], int n, int exp)
{
    int Count[n];
    int Sorted[n];
    Multi(Count,n,0);
    Multi(Sorted,n,-1);
    for(int i = 0; i < n; i++)
    {
        int idx = int(array[i]/exp) % n;
        Count[idx]++;
    }
    for(int i = 1; i < n; i++)
        Count[i] += Count[i-1];
    for(int i = n - 1; i >= 0 ; i--)
    {
        int idx = int(array[i]/exp) % n;
        int real_idx = Count[idx] - 1;
        while(Sorted[real_idx] != -1)
            real_idx--;
        Sorted[real_idx] = array[i];
    }
    for(int i = 0; i < n; i++)
    {
        array[i] = Sorted[i];
    }
};

void Radix_sort(int array[], int n)
{
    int max = Max(array,n);
    int exp = 1;
    while(max > 0)
    {
        Counter_sort(array,n,exp);
        max /= n;
        exp *= n;
    }
    
};

int main()
{
    int array[20];
    for(int i = 0; i < 20; i++)
    {
        array[i] = int(rand() % 1000);
        cout<<array[i]<<" ";
    }
    Radix_sort(array,20);
    cout<<endl;
    for(int i = 0; i < 20; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}
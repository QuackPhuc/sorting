#include<iostream>
#include<random>
using namespace std;

void merge(int array[], int left, int mid, int right)
{
    int idx_l = left; int idx_r = mid + 1; int idx = 0;
    int sub_array[right - left + 1];
    while((idx_l <= mid) && (idx_r <= right))
    {
        if(array[idx_l] <= array[idx_r])
        {
            sub_array[idx] = array[idx_l];
            idx++; idx_l++;
        }
        else
        {
            sub_array[idx] = array[idx_r];
            idx++; idx_r++;
        }
    }

    if(idx_l > mid)
    {
        for(; idx_r <= right; idx++)
            sub_array[idx] = array[idx_r++];
    }
    else
    {
        for(; idx_l <= mid; idx++)
            sub_array[idx] = array[idx_l++];
    }
    for(int i = 0; i < right - left + 1; i++)
        array[left + i] = sub_array[i];
}

void Merge_Sort(int array[], int left, int right)
{
    if(right <= left)
        return;
    int mid = (int(right - left) / 2) + left;
    if(mid != 0)
    {
        Merge_Sort(array, left, mid);
        Merge_Sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main()
{
    int array[20];
    for(int i = 0; i < 20; i++)
    {
        array[i] = int(rand() % 11);
        cout<<array[i]<<" ";
    }
    Merge_Sort(array,0,19);
    cout<<endl;
    for(int i = 0; i < 20; i++)
        cout<<array[i]<<" ";

    
}
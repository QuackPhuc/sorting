#include<random>
#define mergeSort(array, n) Merge_Sort(array, 0, n - 1)
#define quickSort(array, n) Quick_Sort(array, 0, n - 1)
#define radixSort(array, n) Radix_sort(array, n)
#define shakerSort(array, n) CocktailSort(array, n)
#define interchangeSort(array, n) Interchange_Sort(array, n)
#define binaryinsertionSort(array, n) InsertionSort(array, n)

void randomArray(int array[], long size, int seed = 0)
{
    srand(seed);
    for(int i = 0; i < size; i++)
        array[i] = rand();
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int array[], int left, int mid, int right)
{
    int idx_l = left, idx_r = mid + 1, idx = 0;
    int sub_array[right - left + 1];
    while((idx_l <= mid) && (idx_r <= right))
    {
        if(array[idx_l] <= array[idx_r])
        {
            sub_array[idx++] = array[idx_l++];
        }
        else
        {
            sub_array[idx++] = array[idx_r++];
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
    Merge_Sort(array, left, mid);
    Merge_Sort(array, mid + 1, right);
    merge(array, left, mid, right);
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

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}
 
void heapSort(int arr[], int N)
{
 
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

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
}

int shellSort(int arr[], int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    {  
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    if (item == a[mid])
        return mid + 1;
    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}
 
void InsertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void Interchange_Sort(int a[], int n){
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);//hoán vị a[i] và a[j]
			}
		}
	}
}

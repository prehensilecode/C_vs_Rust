#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define SIZE 10000

int myArray[SIZE - 1];

void copyarray(int array[],int copy[],int n)
{
    int i;
    for(i=0;i<n;i++)
    copy[i]=array[i];
}

void printSorted()
{
    int i;
    for( i = 0; i < SIZE - 1; i++)
    {
        printf("%d\n", myArray[i]);
    }
}


void init()
{
    int i;
    for( i = 0; i < SIZE - 1; i++)
    {
        myArray[i] = rand()%1000000;
    }
}

//Bubble sort
void bubblesort(int array[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(array[j]>array[j+1])
                swap(array[j],array[j+1],temp);

        }
    }
}

//Insertion sort
void insertionsort(int array[],int n)
{
    int i,j,key;
    for(j=1;j<n;j++)
    {
        key=array[j];
        i=j-1;
        while(i>=0 && array[i]>key)
        {
            array[i+1]=array[i];
            i=i-1;
        }
        array[i+1]=key;
     }
}

//selection sort
void selectionsort(int array[],int n)
{
    int i,j,minpos,temp;
    for(i=0;i<n;i++)
    {
        minpos=i;
        for(j=i+1;j<n;j++){
            if(array[j]<array[minpos])
                minpos=j;

        }
        swap(array[i],array[minpos],temp);
    }
}


//Shell sort
void shellsort(int array[],int n)
{
    int gap,i,key,j,temp;
    for(gap=n/2;gap>0;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            key=array[i];
            for(j=i;j>=gap&&array[j-gap]>key;j-=gap)
                array[j]=array[j-gap];
            array[j]=key;
        }
    }

}

//Heap sort

int parent(int i) {
    return(i/2);
}
int left(int i) {
    return(2*i+1);
}
int right(int i) {
    return(2*i+2);
}

void heapify(int a[],int i,int n)
{
    int l,r,large,temp;
    l=left(i);
    r=right(i);
    if((l<=n-1)&&(a[l]>a[i]))
        large=l;
    else
        large=i;
    if((r<=n-1)&&(a[r]>a[large]))
        large=r;
    if(large!=i)
    {
        temp=a[i];
        a[i]=a[large];
        a[large]=temp;
        heapify(a,large,n);
    }
}

void buildheap(int a[],int n)
{
    int i;
    for(i=(n-1)/2;i>=0;i--)
        heapify(a,i,n);
}

void heapsort1(int a[],int n)
{
    int i,m,temp;
    buildheap(a,n);
    m=n;
    for(i=n-1;i>=1;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        m=m-1;
        heapify(a,0,m);
    }
}


// quicksort (via libc)
int compare(const void *a,const void *b)
{
  return (*(int*)a - *(int*)b);
}

void quicksort_libc(int a[],int n)
{
  qsort(a, (size_t)n, sizeof(int), compare);
}


// quicksort from https://www.programiz.com/dsa/quick-sort
void qsswap(int *a,int *b)
{
    // not used; use the swap() macro defined above
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[],int low,int high)
{
    int temp;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            qsswap(&a[i], &a[j]);
        }
    }

    //swap(a[i+1],a[high],temp);
    qsswap(&a[i+1],&a[high]);
    return (i+1);
}

void quicksort(int a[],int n)
{
    int low = 0;
    int high = n-1;
    if (low < high)
    {
        int piv = partition(a, low, high);
        quicksort(&a[low], piv-1);
        quicksort(&a[piv+1], high-piv-1);
    }
}

void print_result(const char *name,double elapsed,int size)
{
    printf("Time taken by %s is %0.6lf secs for %d\n",name,elapsed,size);
}


//Main 
int main()
{
    init();
    double elapsed_T;
    time_t begin,end;

    int bubble[SIZE - 1];
    copyarray(myArray,bubble,SIZE);
    begin=clock();
    bubblesort(bubble,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    print_result("bubble sort", elapsed_T,SIZE);


    int insertion[SIZE - 1];
    copyarray(myArray,insertion,SIZE);
    begin=clock();
    insertionsort(insertion,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    print_result("insertion sort",elapsed_T,SIZE);


    int selection[SIZE - 1];
    copyarray(myArray,selection,SIZE);
    begin=clock();
    selectionsort(insertion,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    print_result("selection sort",elapsed_T,SIZE);


    int shell[SIZE - 1];
    copyarray(myArray,shell,SIZE);
    begin=clock();
    shellsort(shell,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    print_result("shell sort",elapsed_T,SIZE);

    int heap[SIZE - 1];
    copyarray(myArray,heap,SIZE);
    begin=clock();
    heapsort1(heap,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    print_result("heap sort",elapsed_T,SIZE);

    int quicklibc[SIZE - 1];
    copyarray(myArray,quicklibc,SIZE);
    begin=clock();
    quicksort_libc(quicklibc,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    print_result("quicksort (libc)",elapsed_T,SIZE);

    int quick[SIZE - 1];
    copyarray(myArray,quick,SIZE);
    begin=clock();
    quicksort_libc(quick,SIZE);
    end=clock();
    elapsed_T=(((double)end-begin)/CLOCKS_PER_SEC);
    print_result("quicksort",elapsed_T,SIZE);

#ifdef DEBUG
    // check
    int check = 0;
    for (int i = 0; i < SIZE; i++)
    {
        check += quick[i] - quicklibc[i];
    }
    printf("check = %d\n", check);
#endif

    return 0;
}

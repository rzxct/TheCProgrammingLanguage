#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low = 0, high = n-1, mid;
    while (low < high)
    { 
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }
    }
    mid = (low + high) / 2;
	if (x == v[mid])
	{
		return mid;
	}
	else
	{
		return -1;
	}
}

int main()
{
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10};
    int x = 8;
    int position = binsearch(x, v, 10);
    if (position == -1)
    {
        printf("x did not in v");
    }
    else 
	{
        printf("x is in the %d position of v", position);
    }
    return 0;
}

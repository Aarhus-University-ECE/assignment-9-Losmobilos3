#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x)
{
    if (n > 0 && a[n-1] == x)       //
        return true;                // Recursive step
    else if (n > 0 && a[n-1] != x)  //
        return search(a, n-1, x);   //
    else
        return false; // Basecase
}
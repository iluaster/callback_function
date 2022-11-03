#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/* Comparison function. Receives two generic (void) pointers to the items under comparison. */
int cmp(const void *p, const void *q) {
	int x = *(const int *)p;
	int y = *(const int *)q;

	/* Avoid return x - y, which can cause undefined behaviour
	 *        because of signed integer overflow. */
	if (x < y)
		return -1;  // Return -1 if you want ascending, 1 if you want descending order. 
	else if (x > y)
		return 1;   // Return 1 if you want ascending, -1 if you want descending order.

	return 0;
	// All the logic is often alternatively written:
	//     return (x > y) - (x < y);
}
	//
	//     /* Sort an array of n integers, pointed to by a. */
	//     void sort_ints(int *a, size_t n) {
	//         qsort(a, n, sizeof(*a), compare_ints);
	//         }

void print_array(int *a,int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main(int argc, char *argv[])
{
	srand(time(NULL));
	int n;
	printf("Please input size: ");
	scanf("%d",&n);
	int a[n]; // VLA

	for(int i=0;i<n;i++)
		a[i]=rand()%10000;

	print_array(a,n);
	//cmp is a function pointer / callback function
	qsort(a,sizeof(a)/sizeof(*a),sizeof(*a),cmp);
	print_array(a,n);

	return 0;
}

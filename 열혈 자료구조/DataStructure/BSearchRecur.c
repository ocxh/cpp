int BSearchRecur(int arr[], int first, int last, int target)
{
	int mid;
	if (first > last) return -1;

	mid = (first + last) / 2;

	if (arr[mid] == target) return mid;
	else if (arr[mid] < target) return BSearchRecur(arr, mid + 1, last, target);
	else return BSearchRecur(arr, first, mid - 1, target);
}
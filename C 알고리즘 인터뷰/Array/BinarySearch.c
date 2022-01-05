int BinarySearch(int arr[], int size, int value)
{
	int low=0;
	int high=size-1;
	int mid;
	
	while(low<=high)
	{
		mid = (high+low)/2;
		if(arr[mid] == value)
		{
			return mid;	
		}
		else if(arr[mid] < value)
		{
			low = mid+1;
		}else
		{
			high = mid-1;
		}
	}
	return -1;
}

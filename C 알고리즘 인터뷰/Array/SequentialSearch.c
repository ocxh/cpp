int SequentialSearch(int arr[], int size, int value)
{
	int i=0;
	for(i=0; i<size; i++)
	{
		if(arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

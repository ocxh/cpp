int maxSubArraySum(int a[], int size)
{
	int max = 0, maxHere = 0;
	for(int i=0; i<size; i++)
	{
		maxHere += a[i];
		if(maxHere<0) maxHere=0;
		if(maxHere>max) max = maxHere;
	}
	return max;
}

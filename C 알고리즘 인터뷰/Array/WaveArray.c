//파형생성
void WaveArray(int arr[], int size)
{
	quicksort(arr, size); //정렬 수행
	for(int i=0; i<size-1; i+=2)
	{
		swap(arr,i,i+1);	
	} 
}

//��������
void WaveArray(int arr[], int size)
{
	quicksort(arr, size); //���� ����
	for(int i=0; i<size-1; i+=2)
	{
		swap(arr,i,i+1);	
	} 
}

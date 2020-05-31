#include <stdio.h>
#include <stdlib.h>

void inpMatrix(int *arr, int n);
void outMatrix(int *arr, int n);
void Matrixturn(int *arr, int n); // поворот на 90 градусів матриці

int main()
{
  int n;
  printf("n = ");
  scanf("%d", &n);


  int *arr = (int*) malloc(n*n*sizeof(int));                      //int **arr = (int**) malloc(n  * sizeof(int*));
                                                                  //for (int i = 0; i < n; i++){
                                                                    //arr[i] = malloc(n * sizeof(n));
                                                                  //}

  inpMatrix(arr, n);
  outMatrix(arr, n);
  Matrixturn(arr, n);
  outMatrix(arr,n);
  free(arr);
}
void inpMatrix(int *arr, int n)
{
  int k = 0;
  for( int i = 0; i < n * n; i++)
  {
    printf("a[%d][%d] = ", i/n + 1 , i - k*n + 1);
    scanf("%d", &arr[i]);
    if (i - k*n == n - 1)
    {
      k++;
    }
  }
}

void outMatrix(int *arr, int n)
{
  int k = 0;
  for( int i = 0; i < n * n; i++)
  {
    printf("%d ", arr[i]);
    if (i - k*n == n - 1)
    {
      k++;
      printf("\n");
    }
  }
  printf("\n");
}
void Matrixturn(int *arr, int n)
{
  int ar[n*n];
  int k = 0;
  for(int i = 0; i < n*n; i++)
  {
      ar[i] = arr[n*n - (i - k*n + 1) * n  + k];
  if(i - k*n == n - 1){
      k++;
    }
  }
  for(int i = 0; i < n*n; i++)
  {
      arr[i] = ar[i];
  }

}

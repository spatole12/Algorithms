#include <cstdio>
#include <cstdlib>
#include<iostream>
#include <sort.h>
#include <vector>

using namespace std;

int ivector_length(int* v, int n)
{
  int sum;

  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];

  return sum;
}

/*
 * merge sort implementation
 */
void merge_sort(int** A,int vector_arr[], int left, int right)
{ 
    if (left < right) 
    { 
        int mid = (left+right)/2; 
        merge_sort( A, vector_arr, left, mid); 
        merge_sort( A, vector_arr, mid+1, right);
        merge_order(A, vector_arr, left, mid, right); //call to merge order
    }
}
/*
 * merge order implementation
 */
void merge_order(int** A,int vector_arr[],int p,int q,int r){
    int n1 = q - p + 1; 
    int n2 =  r - q; 
    vector<int> vector_l(n1);
	vector<int*> keyl (n1);
	vector<int> vector_r(n2);
	vector<int*> keyr (n2) ;
	
    for (int i = 0; i < n1; i++){ 
        vector_l[i] = vector_arr[p + i];
		keyl[i]=A[p+i];
	}
    for (int j = 0; j < n2; j++) {
        vector_r[j] = vector_arr[q + 1+ j];
		keyr[j]=A[q + 1+ j];		
	}
 
	int i , j;
	int k = p;
	for(i=0,j=0;i<n1 && j<n2;)
	{
		if(vector_l[i] <= vector_r[j])
		{
			vector_arr[k] = vector_l[i];
			A[k] = keyl[i];
			i+=1;
		}
		else{
			vector_arr[k] = vector_r[j];
			A[k] = keyr[j];
			j+=1;
		}
		k+=1;
	}
	
	while(i<n1)
	{
		vector_arr[k] = vector_l[i];
		A[k] = keyl[i];
		i+=1;
		k+=1;
	}
	
	while(j<n2)
	{
		vector_arr[k] = vector_r[j];
		A[k] = keyr[j];
		j+=1;
		k+=1;
	}
	
} 
/*
 * call merge sort
 */
 void callMerge(int** A,int n,int l,int r)
 {
	
	int vector_arr[r+1];
	for(int i=0;i<=r;i++)
		vector_arr[i]= ivector_length(A[i],n);
	
    merge_sort(A, vector_arr, l, r); // call to merge sort
   
 }	
 /*
 *  naive insertion sort
 */
void insertion_sort(int** A, int n, int l, int r)
{ 

  register int i;
  int* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n))) //naive code
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}
/*
 * insertion sort improved
 */

void insertion_sort_im(int** A, int n, int l, int r)
{ 
  register int i;
  int* key;
  int sum_key;
  
  vector<int> v_sizevector ;
  for (int itr = 0; itr < r+1; itr++)
  {	  
  v_sizevector.push_back(ivector_length(A[itr],n));
  }
  
  
  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
	  sum_key = v_sizevector[j];
      i = j - 1;

      while ((i >= l) && (v_sizevector[i] > sum_key))
        {
		  A[i+1] = A[i];
		  v_sizevector[i+1] = v_sizevector[i];		
		  i = i - 1;	  
		  
	    }
	       A[i+1] = key;
		   v_sizevector[i+1] = sum_key;
     
	}
	
}


/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}


/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
  int** iv_array;

  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
	rg >> iv_array[i][j];
	if (small)
	  iv_array[i][j] %= 100;
	else
	  iv_array[i][j] %= 65536;
      }

  return iv_array;
}


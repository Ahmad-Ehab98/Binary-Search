#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <D:/3rdCSE/Me/Sprints Embedded Booster/types.h>

void bubble_sort (uint32_t* arr,uint8_t arr_size)
{ /*this function is used to sort an array by bubble sort
    this is made by looping on the elements and swap them
    if they are not sorted in ascending order*/
   uint32_t temp; // variable to make swap operation
   bool sorted = 1; // sorted checker
   for(uint8_t i = 0; i<arr_size-1 ; i++)
   {
     if (arr[i]>arr[i+1])
     {
         sorted = 0;
         temp = arr[i];
         arr[i] = arr[i+1];
         arr[i+1] = temp ;
     }
   }

   if(!sorted)
   { // function is called recursively until array is completely sorted
       bubble_sort(arr,arr_size);
   }
}

uint8_t binary_search (uint32_t* arr,uint8_t arr_size,uint32_t element)
{/*this function is used to implement binary search technique
    we firstly sort array by bubble sort function then start*/
    bubble_sort(arr,arr_size);
    printf("array elements after sorting\n");
    for(uint8_t i =0;i<arr_size;i++)
        printf("%d\t",arr[i]);
    bool found = 0; //condition to exit function
    uint8_t start =0;
    uint8_t end = arr_size;
    uint8_t mid;
    while (!found)
    {
        mid = (start+end)/2;
        if (arr[mid]==element)
        {
            found =1;
            continue;
        }
        else if (arr[mid]>element&&mid != start)
            end = mid -1;
        else if (arr[mid]<element&&mid != end)
            start = mid +1;
        else
            break;
    }
    if (found)
        return mid;
    else
        return -1;
}
int main()
{

    uint32_t arr_size,element;
    bool limit = 0; // condition to indicate use inputs size within the limit
    while(!limit)
    {
    printf("enter array size -maximum 255-\n");
    scanf("%d",&arr_size);
    if (arr_size>255)
       printf("error .. enter size of max 255\n");
    else
        limit = 1;
    }
    uint32_t* arr = (uint32_t*)malloc(arr_size*sizeof(uint32_t));
    printf("enter array elements\n");
    for(uint8_t i =0;i<arr_size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter element to search for\n");
    scanf("%d",&element);
    uint8_t found = binary_search(arr,arr_size,element);//search function return
    if (found == 255)//condition of not finding - return value is -1 -
        printf("\nnot found\n");
    else
        printf("\nelement is found in index no. %d\n",found);
    return 0;

}

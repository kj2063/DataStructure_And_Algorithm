#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

// Hoare Partition scheme in quickSort

void swap(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}

int partition(int dataArr[], int leftIndex, int rightIndex){
    
    // Some sorted arrays can be sorted faster by choosing a random pivot.

    // int pivotIndex = rand() % (rightIndex - leftIndex + 1) + leftIndex;
    // swap(dataArr[leftIndex],dataArr[pivotIndex]);
    int firstIndex = leftIndex;
    int pivot = dataArr[firstIndex];

    ++leftIndex;

    while(leftIndex <= rightIndex){
        
        while(dataArr[leftIndex] <= pivot && leftIndex < rightIndex)
            leftIndex++;
        while(dataArr[rightIndex] >= pivot && leftIndex <= rightIndex)
            rightIndex--;
           

        if(leftIndex < rightIndex){
            swap(dataArr[leftIndex], dataArr[rightIndex]);
        }
        else{
            break;
        }
    }

    swap(dataArr[firstIndex], dataArr[rightIndex]);

    return rightIndex;
}

void quickSort(int dataArr[], int leftIndex, int rightIndex){
    if(leftIndex < rightIndex){
        int index = partition(dataArr,leftIndex,rightIndex);

        quickSort(dataArr, leftIndex, index-1);
        quickSort(dataArr, index+1, rightIndex);
    }
}

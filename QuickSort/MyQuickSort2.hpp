#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "MyLinkedStack.hpp"

void swap2(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}

void quickSort2(int dataArr[], int leftIndexParam, int rightIndexParam){
    MyLinkedStack<int> indexStack = MyLinkedStack<int>();
    int left, right;

    indexStack.push(leftIndexParam);
    indexStack.push(rightIndexParam);

    while(!indexStack.isEmpty()){
        int lastIndex = indexStack.pop();
        int firstIndex = indexStack.pop(); 
        right = lastIndex;
        left = firstIndex;

        if(right - left > 0){
            int pivotIndex = rand() % (lastIndex - firstIndex + 1) + firstIndex;
            swap2(dataArr[firstIndex],dataArr[pivotIndex]);
            int pivot = dataArr[firstIndex];

            left++;

            while(left <= right){
                while(dataArr[left] <= pivot && left < right)
                    left++;
                while(dataArr[right] >= pivot && left <= right)
                    right--;

                if(left < right){
                    swap2(dataArr[left],dataArr[right]);
                }
                else{
                    break;
                }
            }

            swap2(dataArr[firstIndex], dataArr[right]);
            
            indexStack.push(firstIndex);
            indexStack.push(right - 1);
            indexStack.push(right + 1);
            indexStack.push(lastIndex);
        }
    }

}

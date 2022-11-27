#include "MyQuickSort.hpp"
#include "MyQuickSort2.hpp"

int main(){
    srand((int)time(NULL));
    int arrSize = 100000;

    int insertArr[arrSize];
    for(int i=0;i<arrSize;i++)
      insertArr[i]=rand()%100;
    
    clock_t startTime = clock();
    // quickSort(insertArr,0,arrSize-1);
    quickSort2(insertArr,0,arrSize-1);
    clock_t endTime = clock();

    double calcTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // for(int i=0; i< arrSize; i++){
    //     printf("%d ", insertArr[i]);
    // }

    printf("\n=> %f sec \n\n", calcTime);

    return 0;
}
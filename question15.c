/**
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void quicksort(int* array, int arraysize){
    if(arraysize == 0)
        return;
    int key = *(array + arraysize - 1);
    int point = 0;
    for(int i = 0; i < arraysize - 1; i++){
        if(*(array + i) <= key){
            *(array + arraysize - 1) = *(array + point);
            *(array + point) = *(array + i);
            *(array + i) = *(array + arraysize - 1);
            point++;
        }
    }
    *(array + arraysize - 1) = *(array + point);
    *(array + point) = key;
    quicksort(array, point);
    quicksort(array + point + 1, arraysize - point - 1);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*)* 16384);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 16384);
    int l = 0;
    quicksort(nums, numsSize);
    for(int first = 0; first < numsSize - 2; first++){
        if(first > 0 && *(nums + first) == *(nums + first - 1)){
            continue;
        }
        int third = numsSize - 1;
        for(int second = first + 1; second < numsSize - 1; second++){
            if(second > first + 1 && *(nums + second) == *(nums + second - 1)){
                continue;
            }
            while(*(nums + first) + *(nums + second) + *(nums + third) > 0 && second < third){
                    third--;
            }
            if(*(nums + first) + *(nums + second) + *(nums + third) == 0 && second < third){
                    result[l] = (int*)malloc(sizeof(int) * 3);
                    result[l][0] = *(nums + first);
                    result[l][1] = *(nums + second);
                    result[l][2] = *(nums + third);
                    (*returnColumnSizes)[l] = 3;
                    l++;
            }
        }
    }
    *returnSize = l;
    return result;
}

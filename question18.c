/**
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * (1) 0 <= a, b, c, d < n
 * (2) a, b, c, and d are distinct.
 * (3) nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 *
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void quicksort(int* nums, int numsSize) {
    if (numsSize < 2)
        return;
    int key = *(nums + numsSize - 1);
    int p = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (*(nums + i) < key) {
            *(nums + numsSize - 1) = *(nums + p);
            *(nums + p++) = *(nums + i);
            *(nums + i) = *(nums + numsSize - 1);
        }
    }
    *(nums + numsSize - 1) = *(nums + p);
    *(nums + p) = key;
    quicksort(nums, p);
    quicksort(nums + p + 1, numsSize - p - 1);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*)* 1001), i = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1001);
    quicksort(nums, numsSize);
    for(int first = 0; first < numsSize - 3; first++){
        if(first > 0 && *(nums + first) == *(nums + first - 1))
            continue;
        for(int second = first + 1; second < numsSize - 2; second++){
            if(second > first + 1 && *(nums + second) == *(nums + second - 1))
                continue;
            int fourth = numsSize - 1;
            for(int third = second + 1; third < numsSize - 1; third++){
                if(third > second + 1 && *(nums + third) == *(nums + third - 1))
                    continue;
                while((long)*(nums + first) + (long)*(nums + second) + (long)*(nums + third) + (long)*(nums + fourth) > target && third < fourth)
                    fourth--;
                if((long)*(nums + first) + (long)*(nums + second) + (long)*(nums + third) + (long)*(nums + fourth) == target && third < fourth){
                   result[i] = (int*)malloc(sizeof(int) * 4);
                   result[i][0] = *(nums + first);
                   result[i][1] = *(nums + second);
                   result[i][2] = *(nums + third);
                   result[i][3] = *(nums + fourth);
                   (*returnColumnSizes)[i] = 4;
                   i++;
                }
            }
        }
    }
    *returnSize = i;
    return result;
}

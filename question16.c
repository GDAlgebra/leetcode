/**Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 */

void merge(int* array, int first, int mid, int end){
    int left[mid - first + 1], right[end - mid];
    int i = 0;
    for(; i < mid - first + 1; i++){
        left[i] = *(array + first + i);
    }
    i = 0;
    for(; i < end - mid; i++){
        right[i] = *(array + mid + 1 + i);
    }
    i = first;
    int j = 0, k = 0; 
    while(j < mid - first + 1 && k < end - mid){
        if(left[j] < right[k]){
            *(array + i) = left[j];
            j++;
            i++;
        }
        else{
            *(array + i) = right[k];
            k++;
            i++;
        }
    }
    while(j < mid - first + 1){
        *(array + i) = left[j++];
        i++;
    }
    while(k < end - mid){
        *(array + i) = right[k++];
        i++;
    }
}

void mergesort(int* array, int first, int end){
    if(first < end){
        int mid = (first + end) / 2;
        mergesort(array, first, mid);
        mergesort(array, mid + 1, end);
        merge(array, first, mid, end);
    }
    return;
}

int threeSumClosest(int* nums, int numsSize, int target){
    mergesort(nums, 0, numsSize - 1);
    int closesum = *(nums + numsSize - 1) + *(nums + numsSize - 2) + *(nums + numsSize - 3) - target;
    for (int first = 0; first < numsSize - 2; first++) {
        int third = numsSize - 1;
        for (int second = first + 1; second < numsSize - 1; second++) {
            while (*(nums + first) + *(nums + second) + *(nums + third) - target > 0 && second < third) {
                third--;
            }
            if (third < numsSize - 1 && abs(*(nums + first) + *(nums + second) + *(nums + third + 1) - target) < abs(closesum) ) {
                closesum = *(nums + first) + *(nums + second) + *(nums + third + 1) - target;
            }
            if (abs(*(nums + first) + *(nums + second) + *(nums + third) - target) < abs(closesum) && second < third) {
                    closesum = *(nums + first) + *(nums + second) + *(nums + third) - target;
            }
        }
    }
    return closesum + target;
}

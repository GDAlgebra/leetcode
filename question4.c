/**
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 */
int sort(int* start, int numsize , int x){
    int* p = start;
    int i = 0;
    while(i < numsize && *p <= x){
        p++;
        i++;
    }
    return p - start;
}
int min(int a, int b){
    return a < b ? a : b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if((nums1Size + nums2Size) % 2 == 1){
        if(nums2Size == 0){
            return *(nums1 + nums1Size / 2);
        }
        int numsizeodd = (nums1Size + nums2Size + 1) / 2;
        for(int i = 0; i < nums1Size; i++){
            int a = sort(nums2, nums2Size, *(nums1 + i));
            if(a + i + 1 == numsizeodd){
                return *(nums1 + i);
            }
            if(a + i + 1 > numsizeodd){
                return *(nums2 - i + numsizeodd - 1); 
            }
        }
        return *(nums2 + numsizeodd - nums1Size - 1);
    }
    else{
        if(nums2Size == 0){
            return (*(nums1 + nums1Size / 2) + *(nums1 + nums1Size / 2 - 1)) / 2.0;
        }
        int numsizeeven =  (nums1Size + nums2Size) / 2;
        for(int i = 0; i < nums1Size; i++){
            int a = sort(nums2, nums2Size, *(nums1 + i));
            if(a + i + 1 == numsizeeven){
                if (i == nums1Size - 1){
                    return  (*(nums2 + a) + *(nums1 + i)) / 2.0;
                }
                if (a == nums2Size)
                {
                    return  (*(nums1 + i + 1) + *(nums1 + i)) / 2.0;
                }
                return (min(*(nums1 + i + 1), *(nums2 + a)) + *(nums1 + i)) / 2.0;
            }
            if(a + i + 1 == numsizeeven + 1){
                return (*(nums1 + i) + *(nums2 + a - 1)) / 2.0; 
            }
            if(a + i + 1 > numsizeeven + 1){
                return (*(nums2 + numsizeeven - i - 1) + *(nums2 + numsizeeven - i)) / 2.0;
            }
        }
    return (*(nums2 + numsizeeven - nums1Size - 1) + *(nums2 + numsizeeven - nums1Size)) / 2.0;
    }
}

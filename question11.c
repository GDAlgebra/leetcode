/**
 * You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 */
int min(int a, int b){
    return a < b ? a : b;
}

int maxArea(int* height, int heightSize){
    int result = 0, temp = 0, *head = height, *end = height + heightSize - 1;
    while(head != end){
        temp = min(*head, *end) * (end - head);
        if(result < temp){
            result = temp;
        }
        *head < *end ? head++ : end--;
    }
    return result;
}

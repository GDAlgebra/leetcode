/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** results;
char* result;
int resultssize, resultsize, num, left = 0, right = 0;
void backtrack(int index){
    if(index == num){
        if(left == right){
            char* tmp = malloc(sizeof(char) * (resultsize + 1));
            memcpy(tmp, result, sizeof(char) * (resultsize + 1));
            results[resultssize++] = tmp;
        }
        else
            return;
    }
    else{
        if(left > right){
            result[resultsize++] = ')';
            result[resultsize] = 0;
            right++;
            backtrack(index + 1);
            right--;
            result[--resultsize] = 0;
        }
        result[resultsize++] = '(';
        result[resultsize] = 0;
        left++;
        backtrack(index + 1);
        left--;
        result[--resultsize] = 0;
    }
}

char ** generateParenthesis(int n, int* returnSize){
    num = 2 * n;
    resultsize = 0;
    resultssize = 0;
    results = malloc(sizeof(char*) * 2000);
    result = malloc(sizeof(char*) * 100);
    backtrack(0);
    *returnSize = resultssize;
    return results;
}

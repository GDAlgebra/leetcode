/** 
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward.
 * For example, 121 is a palindrome while 123 is not.
 */
int reverse(int x){
    long rs = 0;
    long y = x;
    for( ; y; rs = rs * 10 + y % 10, y /= 10);
    return rs;
}
bool isPalindrome(int x){
    if(x < 0){
        return false;
    }
    if(x == 0){
        return true;
    }
    return x==reverse(x);
}

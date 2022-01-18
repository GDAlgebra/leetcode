/**
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
 * The algorithm for myAtoi(string s) is as follows:
 * 1.Read in and ignore any leading whitespace.
 * 2.Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
 * This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
 * 3.Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
 * 4.Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
 * 5.If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. 
 * Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
 * 6.Return the integer as the final result.
 */
int myAtoi(char * s){
    char* p = s;
    long a = 0;
    int i = 0, havezero = 0;
    for(; *p == ' '; p++);
//if the first char is not a number or + or -
    if( *p != 43 && *p != 45 && (*p < 48 || *p > 57)){
        return 0;
    }
    for (; *p == '0'; p++){
        havezero++;
    }
if(havezero == 0){
//if the first char is +
    if(*p == 43){
        p++;
        for (; *p == '0'; p++);
        for(;*p > 47 && *p < 58;p++){
            a = a * 10 + (*p-48);
            i++;
            if(i>=11){
                return 2147483647;
        }
    }
    return a<2147483647?a:2147483647;
    }
//if the first char is -
    if(*p == 45){
        p++;
        for (; *p == '0'; p++);
        for(;*p > 47 && *p < 58;p++){
            a = a * 10 + (*p-48);
            i++;
            if(i>=11){
                return -2147483648;
        }
    }
    a *= -1;
    return a>-2147483648?a:-2147483648;
    }
}
//if the first char is number
    for(;*p > 47 && *p < 58;p++){
        a = a * 10 + (*p-48);
        i++;
        if(i>=11){
            return 2147483647;
        }
    }
    return a<2147483647?a:2147483647;
}

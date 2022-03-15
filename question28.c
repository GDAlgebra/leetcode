/**
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * Clarification:
 * What should we return when needle is an empty string? This is a great question to ask during an interview.
 * For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

int strStr(char * haystack, char * needle){
    int l1 = strlen(haystack), l2 = strlen(needle);
    if(l1 < l2)
        return -1;
    if(l2 == 0)
        return 0;
    for(int i = 0; i < l1 - l2 + 1; i++){
        bool ismatch = true;
        for(int j = 0; j < l2; j++){
            if(*(haystack + i + j) != *(needle + j)){
                ismatch = false;
                break;
            }
        }
        if(ismatch)
            return i;
    }
    return -1;
}

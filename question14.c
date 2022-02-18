/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */
char * longestCommonPrefix(char ** strs, int strsSize){
    char *result = strs[0];
    for(int i = 1; i < strsSize; i++){
        char *p = strs[i];
// if a char is "", then return no char
        if(*p == '\0'){
            *result = '\0';
            return result;
        }
        for(int j = 0; *p != '\0' && *(result + j) != '\0'; j++){
            if(*(p + j) != *(result + j)){
                *(result + j) = '\0';
                break;
            }
        }
    }
    return result;
}

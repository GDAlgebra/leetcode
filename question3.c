/**
 * Given a string s, find the length of the longest substring without repeating characters.
 */
int max(int a,int b){
    return a>b?a:b;
}
int lengthOfLongestSubstring(char * s){
int maxlength = 0, tempmaxl, i;
char* p = s;
while(*p != 0){
    tempmaxl = 0;
    for(i = 1;;i++)
    {
        if(*(p+i) == 0 || tempmaxl != 0){
            break;
        }
        for(int j = 0; j<i && tempmaxl == 0; j++){
            if(*(p+j) == *(p+i)){
                tempmaxl = i;
            }
        }
    }
    if(tempmaxl!=0){
            maxlength=max(maxlength,tempmaxl); 
    }
    else{
        return max(maxlength,i);
    }
    p++;
}
return maxlength;
}

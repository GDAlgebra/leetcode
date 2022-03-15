/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    char** result = (char*)malloc(sizeof(char*) * 1280);
    if(*digits == '\0'){
        *returnSize = 0;
        return result;
    }
    *returnSize = 1;
    int i = 0, resultarray[4] = {0};
    for(; *(digits + i) != '\0'; i++){
        if(*(digits + i) < 55 || *(digits + i) == 56){
            *returnSize *= 3;
            resultarray[i] = 3;
        }
        else{
            *returnSize *= 4;
            resultarray[i] = 4;
        }   
    }
    int j = 0;
    while(j < *returnSize){
        int l = 1;
        result[j] = (char*)malloc(sizeof(char) * (i + 1));
        for(int k = 0; k < i; k++){
            result[j][k + 1] = '\0';
            if((j / l) % resultarray[k] == 0){
                switch(*(digits + k)){
                    case '2':{
                        result[j][k] = 'a';    
                        break;
                    }
                    case '3':{
                        result[j][k] = 'd';    
                        break;
                    }
                    case '4':{
                        result[j][k] = 'g';    
                        break;
                    }
                    case '5':{
                        result[j][k] = 'j';    
                        break;
                    }
                    case '6':{
                        result[j][k] = 'm';    
                        break;
                    }
                    case '7':{
                        result[j][k] = 'p';    
                        break;
                    }
                    case '8':{
                        result[j][k] = 't';    
                        break;
                    }
                    case '9':{
                        result[j][k] = 'w';    
                        break;
                    }                     
                }
            }
            if((j / l) % resultarray[k] == 1){
                switch(*(digits + k)){
                    case '2':{
                        result[j][k] = 'b';    
                        break;
                    }
                    case '3':{
                        result[j][k] = 'e';    
                        break;
                    }
                    case '4':{
                        result[j][k] = 'h';    
                        break;
                    }
                    case '5':{
                        result[j][k] = 'k';    
                        break;
                    }
                    case '6':{
                        result[j][k] = 'n';    
                        break;
                    }
                    case '7':{
                        result[j][k] = 'q';    
                        break;
                    }
                    case '8':{
                        result[j][k] = 'u';    
                        break;
                    }
                    case '9':{
                        result[j][k] = 'x';    
                        break;
                    }                     
                }
            }
            if((j / l) % resultarray[k] == 2){
                switch(*(digits + k)){
                    case '2':{
                        result[j][k] = 'c';    
                        break;
                    }
                    case '3':{
                        result[j][k] = 'f';    
                        break;
                    }
                    case '4':{
                        result[j][k] = 'i';    
                        break;
                    }
                    case '5':{
                        result[j][k] = 'l';    
                        break;
                    }
                    case '6':{
                        result[j][k] = 'o';    
                        break;
                    }
                    case '7':{
                        result[j][k] = 'r';    
                        break;
                    }
                    case '8':{
                        result[j][k] = 'v';    
                        break;
                    }
                    case '9':{
                        result[j][k] = 'y';    
                        break;
                    }                     
                }
            }
            if((j / l) % resultarray[k] == 3){
                switch(*(digits + k)){
                    case '7':{
                        result[j][k] = 's';    
                        break;
                    }
                    case '9':{
                        result[j][k] = 'z';    
                        break;
                    }                     
                }
            }
            l *= resultarray[k];
        }
        j++;
    }
    return result;
}

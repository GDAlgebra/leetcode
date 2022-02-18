/**
 * Given a roman numeral, convert it to an integer.
 */
int romanToInt(char * s){
    int num = 0;
    char *roman = s;
    while(*roman == 'M'){
        num += 1000;
        roman++;
    }
    while(*roman == 'C'&& *(roman + 1) == 'M'){
        num += 900;
        roman += 2;
    }
    while(*roman == 'D'){
        num += 500;
        roman ++;
    }
    while(*roman == 'C'&& *(roman + 1) == 'D'){
        num += 400;
        roman += 2;
    }
    while(*roman == 'C'){
        num += 100;
        roman ++;
    }
    while(*roman == 'X'&& *(roman + 1) == 'C'){
        num += 90;
        roman += 2;
    }
    while(*roman == 'L'){
        num += 50;
        roman ++;
    }
    while(*roman == 'X'&& *(roman + 1) == 'L'){
        num += 40;
        roman += 2;
    }
    while(*roman == 'X'){
        num += 10;
        roman ++;
    }
    while(*roman == 'I'&& *(roman + 1) == 'X'){
        num += 9;
        roman += 2;
    }
    while(*roman == 'V'){
        num += 5;
        roman ++;
    }
    while(*roman == 'I'&& *(roman + 1) == 'V'){
        num += 4;
        roman += 2;
    }
    while(*roman == 'I'){
        num += 1;
        roman ++;
    } 
    return num;
}

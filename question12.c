/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given an integer, convert it to a roman numeral.
 */
char * intToRoman(int num){
    char *Roman = (char *)malloc(32);
    char *result = Roman;
    int number = num, i = 0;
    while(number != (int)0){
        if(number >= 1000){
            *(result++) = 77;
            number -= 1000;
            continue;
        }
        if(number >= 900){
            *(result++) = 67;
            *(result++) = 77;
            number -= 900;
            continue;
        }
        if(number >= 500){
            *(result++) = 68;
            number -= 500;
            continue;
        }
        if(number >= 400){
            *(result++) = 67;
            *(result++) = 68;
            number -= 400;
            continue;
        }
        if(number >= 100){
            *(result++) = 67;
            number -= 100;
            continue;
        }
        if(number >= 90){
            *(result++) = 88;
            *(result++) = 67;
            number -= 90;
            continue;
        }
        if(number >= 50){
            *(result++) = 76;
            number -= 50;
            continue;
        }
        if(number >= 40){
            *(result++) = 88;
            *(result++) = 76;
            number -= 40;
            continue;
        }
        if(number >= 10){
            *(result++) = 88;
            number -= 10;
            continue;
        }
        if(number >= 9){
            *(result++) = 73;
            *(result++) = 88;
            number -= 9;
            continue;
        }
        if(number >= 5){
            *(result++) = 86;
            number -= 5;
            continue;
        }
        if(number >= 4){
            *(result++) = 73;
            *(result++) = 86;
            number -= 4;
            continue;
        }
        if(number > 0){
            *(result++) = 73;
            number -= 1;
            continue;
        }
    }
    *result = 0;
    return Roman;
}

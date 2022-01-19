/**
  * Given a string s, return the longest palindromic substring in s.
  */
char* longestPalindrome(char* s) {
    int length = 0;
    char* result = NULL, *p = s;
    //odd maximum char
    while (*p != 0) {
        int i = 1;
        char* head = p - 1, * tail = p + 1;
        while (head + 1 != s && *tail != 0 && *head == *tail){
            tail++;
            head--;
            i += 2;
        }
        if (i > length) {
            result = p - (i / 2);
            length = i;
        }
        p++;
    }
    p = s;
    //even maximum char
    while (*p != 0) {
        int i = 0;
        char* head = p, * tail = p + 1;
        while (head + 1 != s && *tail != 0 && *head == *tail){
            tail++;
            head--;
            i += 2;
        }
        if (i > length) {
            result = p - (i / 2) + 1;
            length = i;
        }
        p++;
    }
    char *a = (char*)malloc(length + 1);
    a[length] = '\0';
        for(int i = 0; i < length ; i++){
        a[i] = *(result + i) ;
    }
    return a;
}

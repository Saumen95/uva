#include<bits/stdc++.h>

#define N 128
using namespace std;
static char s[N];
static char t[N];

int main(int argc, char const *argv[])
{
    
    
        while( scanf("%s", s) && scanf("%s", t) ){
 
        // Although a major flaw input beginning with 0 and
        // two strings matching. But for this problem it doesn't matter.
        if( strcmp(s,t) == 0 && s[0] == '0' )
            break;
 
 
        int lens = strlen(s);
        int lent = strlen(t);
 
 
        // Add leading 0's to smaller string (May not be necessary).
        // Shift each characters in string right by padding length.
        if( lens > lent ){
 
            int padding = lens - lent;
 
            for(int i = lent - 1; i >= 0; --i)
                t[i + padding] = t[i];
 
            for(int i = 0; i < padding; ++i)
                t[i] = '0';
        }
 
        else if( lens < lent ){
 
            int padding = lent - lens;
 
            for(int i = lens - 1; i >= 0; --i)
                s[i + padding] = s[i];
 
            for(int i = 0; i < padding; ++i)
                s[i] = '0';
        }
 
 
 
        int maxlen;
        if(lens > lent)
            maxlen = lens;
        else maxlen = lent;
 
 
        int carry = 0;
        int c = 0;
        int sum = 0;
 
 
        // Add two Strings, if a carry operation occurs
        // then add that to the count.
        for(int i = maxlen - 1; i >= 0; --i){
 
            sum += s[i] - '0' + t[i] - '0';
 
            sum = sum + carry;
 
            carry = sum / 10;
 
            if(carry)
                ++c;
 
            sum = 0;
 
        }
 
 
        if(!c)
            printf("No carry operation.\n");
        else if( c > 1 )
            printf("%d carry operations.\n", c);
        else
            printf("%d carry operation.\n", c);
 
    }
 
    return 0;
}





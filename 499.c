#include<stdio.h>

static char s[256];
int main(){
    register unsigned i;
    while(gets(s)){
        unsigned upcase[32] = {0}, lowcase[32] = {0};
        for (i = 0; s[i]; ++i){
            if (s[i] >= 'A' && s[i] <= 'Z')
                ++upcase[s[i] - 'A'];
            else if (s[i] >= 'a' && s[i] <= 'z')
                ++lowcase[s[i] - 'a'];
        }
        unsigned max = upcase[0];

                for (i = 0; i < 26; ++i){
                    if (upcase[i] > max)
                        max = upcase[i];
                    if (lowcase[i] > max)
                        max = lowcase[i];
                }
                for (i = 0; i < 26; ++i){
            if (upcase[i] == max)
                printf("%c", 'A'+i);
        }
        for (i = 0; i < 26; ++i){
            if (lowcase[i] == max)
                printf("%c", 'a'+i);
        }

        printf(" %u\n", max);
    }
    return 0;
}

// CodeChef: https://www.codechef.com/problems/CAKEDOOM

#include <stdio.h>
#include <string.h>
#include <stdbool.h>



int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int K;
        scanf("%d", &K);
        char S[101];
        scanf("%s", S);
        int len = (int)strlen(S);

        // if length is 1 and char is '?' ==> output 0 and move ahead
        // if length is 1 but char is not '?' ==> output string itself and move ahead
        printf(len == 1 ? (S[0] == '?') ? "0\n" : S : "");

        if (len != 1) {
            // check if first and last char are same
            printf(S[0] == S[len - 1] ? "NO\n" : "");

            for (int i = 0; i < len; ++i) {
                if (S[i] == '?') {
                    //
                    int previousElementIndex = len == 0 ? len - 2 : i - 1;
                    if (S[i] == S[previousElementIndex]) {
                        printf("NO\n");
                        break;
                    }
                } else {

                }
            }
        }
    }
    return 0;
}
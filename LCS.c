/*#include <stdio.h>
#include <string.h>

int c[10][10], b[10][10];
char X[10] = "ABCBDAB", Y[10] = "BDCABA";

int LCS_Length(){
    int i,j;
    int m = strlen(X);
    int n = strlen(Y);
    for (i=1; i<=m;i++)
    c[i][0]=0;
    for (j=1; j<=n;j++)
    c[0][j]=0;
    for(i=1;i<=m;i++){
        for (j=1; j<=n;j++){
            if (X[i]==Y[j]){
                c[i][j]=(c[i-1][j-1])+1;
                b[i][j]='r';
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='s';
            }
            else
            c[i][j]=c[i][j-1];
                b[i][j]='t';
        }
    }
    return c[m][n];
}

void PRINT_LCS(int b[10][10], char X[10], int (*c)[10], int j){
    int i=strlen(X);
    if(i==0||j==0)
    return;
    if(b[i][j]=='r'){
        PRINT_LCS(b,X,i-1,j-1);
        printf("%c", X[i]);
    }
    else if(b[i][j]=='s')
    PRINT_LCS(b,X,i-1,j);
    else
    PRINT_LCS(b,X,i,j-1); 
}


int main() {
    int length = LCS_Length();
    printf("Length of LCS: %d\n", length);
    printf("LCS: ");
    PRINT_LCS(b, X, c, strlen(Y));
    printf("\n");
    return 0;
}
*/

#include <stdio.h>
#include <string.h>

void LCS(char *X,char *Y, int m, int n){
    int L[m+1][n+1];
    char B[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++){
        L[i][0]=0;
        B[i][0]=0;
    }
    for(j=0;j<=n;j++){
        L[0][j]=0;
        B[0][j]=0;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                L[i][j]=L[i-1][j-1]+1;
                B[i][j]='\\';
            }
            else if(L[i-1][j]>=L[i][j-1]){
                L[i][j]=L[i-1][j];
                B[i][j]='|';
            }
            else{
                L[i][j]=L[i][j-1];
                B[i][j]='-';
            }
        }
    }
    printf("Length of LCS is %d\n",L[m][n]);
    int r = L[m][n];  
    char res[r+1];    
    res[r] = '\0';    

    i = m, j = n;
    while(i > 0 && j > 0) {
        if(B[i][j] == '\\') {
            res[r-1] = X[i-1];
            i--;
            j--;
            r--;
        }
        else if(B[i][j] == '-') {
            j--;
        }
        else {
            i--;
        }
    }
    printf("The Longest Common Subsequence is: %s\n", res);
}

int main(){
    char X[]="ABRTFG";
    char Y[]="WABGWTWGT";
    int size_X=strlen(X);
    int size_Y=strlen(Y);

    LCS(X,Y,size_X,size_Y);

    return 0;
}


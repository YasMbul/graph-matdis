#include <stdio.h>
#include <stdlib.h>

int main (){
    system("cls");
    int n;
    printf("Masukkan Jumlah Vertex : "); scanf("%d",&n);
    int m[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
            {
                m[i][j] = 0;
            }
            else {
                printf("Hubungan vertex ke-%d dengan vertex ke-%d = ", i+1, j+1); scanf("%d", &m[i][j]);
                m[j][i] = m[i][j];
            }
        }
    }

    system("cls");
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]); 
            if (j == n-1)
            {
                printf("\n");
            }
        }
    }

    




    return 0;
}

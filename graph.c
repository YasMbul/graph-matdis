#include <stdio.h>
#include <stdlib.h>


int main (){
    system("cls");
    int n;
    printf("Masukkan Jumlah Vertex : "); scanf("%d",&n);
    int m[n][n];
    int h[n];
    int a[n];
    printf("NB: Jika ada hubungan ketik 1, jika tidak ada ketik 0\n");
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
    
    //menampilkan matriks graph
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
    printf("\n");
    //ambil informasi hubungan vertex ke-0
    for (int i=0; i<n; i++)
    {
        h[i] = m[0][i];
    }
    
    //bandingkan dan or kan
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (m[i][j] == 1)
            {
                h[j] = 1;
            }
        }
    }
    
    //tampilkan isi h[]
    for (int i=0; i<n; i++)
    {
        printf("%d ", h[i]);
    }
    return 0;
}

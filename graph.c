#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int inputVertex (){
    int n;
    printf("Masukkan Jumlah Vertex : "); scanf("%d",&n);
    return n;
}

int main (){
    system("cls");
    int n = inputVertex();
    int m[n][n];
    int h[n];
    printf("NB: Jika ada hubungan ketik 1, jika tidak ada ketik 0\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                m[i][j] = 0;
            }
            else {
                int cek = 0;
                while (!cek){ // Mekanisme melarang input selain 0/1
                    printf("Hubungan vertex ke-%d dengan vertex ke-%d = ", i+1, j+1); scanf("%d", &m[i][j]);
                    if (m[i][j] == 0 || m[i][j] == 1){
                        cek = 1;
                    } else {
                        printf("Masukkan hanya nilai 1 dan 0!!!\n");
                    }
                }
            }
        }
    }

    printf("\n");
    //menampilkan graph dalam bentuk matriks
    printf("Bentuk matriks :\n");
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

    //ambil informasi edge vertex pertama
    for (int i=0; i<n; i++)
    {
        h[i] = m[0][i];
    }

    // Cek berarah atau tidak
    bool tanpaArah = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (m[i][j] != m[j][i]){
                tanpaArah = false;
            }
        }
    }

    // Mengecek keterhubungan sesuai arah
    if (tanpaArah){
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (m[i][j] == 1 && h[j] == 0)
                {
                    h[j] = 1;
                }
            }
        }
    }
    else {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (m[i][j] == 1 && h[j] == 0 || m[j][i] == 1 && h[j] == 0)
                {
                    h[j] = 1;
                }
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++){
        total += h[i];
    }

    // Mencetak informasi Jenis graph
    printf("Jenis graph ini :\n");
    
    if (total == n){
        printf("Graph terhubung\n");
    }
    else {
        printf("Graph tidak terhubung\n");
    }
    
    if (tanpaArah){
        printf("Graph tidak berarah\n");
    }
    else {
        printf("Graph berarah\n");
    }


    // Hitung derajat vertex dan derajat total
    int totalDerajat = 0;
    if (tanpaArah){ // Derajat vertex tanpa arah
        printf("\nJumlah derajat per vertex serta derajat total : \n");
        for (int i = 0; i < n; i++){
            int derajat = 0;
            for (int j = 0; j < n; j++){
                if (m[i][j] == 1){
                    derajat += m[i][j];
                    totalDerajat += 1;
                }
            }
            printf("Jumlah derajat vertex %d = %d\n", i+1, derajat);
        }
    }
    else { // Derajat vertex dengan arah
        printf("\nJumlah derajat per vertex serta derajat total : \n");
        for (int i = 0; i < n; i++){
            int derajat = 0;
            for (int j = 0; j < n; j++){
                if (m[i][j] == 1){
                    derajat += m[i][j];
                    totalDerajat += 1;
                }
                else if (m[j][i] == 1){
                    derajat += m[j][i];
                    totalDerajat += 1;
                }
            }
            printf("Jumlah derajat vertex %d = %d\n", i+1, derajat);
        }
    }
    printf("Jumlah derajat total = %d", totalDerajat);

    return 0;
}

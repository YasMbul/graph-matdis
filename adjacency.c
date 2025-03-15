#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int jumlahVertex()
{
  // Input jumlah vertex
  int v;
  printf("Masukkan jumlah vertex : ");
  scanf("%d", &v);
  return v;
}

void representasi()
{
  // Input jumlah vertex
  int v;
  printf("Masukkan jumlah vertex : ");
  scanf("%d", &v);
  // input graph ke matrix
  int A[v][v];
  printf("Jika kedua vertex terhubung ketik 1, jika tidak ketik 0 : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("Vertex %d dan vertex %d : ", i, j);
      scanf("%d", &A[i][j]);
    }
  }
  printf("\n");
  printf("Bentuk matriks : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
      printf("%d ", A[i][j]);
    printf("\n");
  }
}

void cekTidakBerarah()
{
  int v = jumlahVertex();
  // input graph ke matrix
  int A[v][v];
  printf("Jika kedua vertex terhubung ketik 1, jika tidak ketik 0 : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("Vertex %d dan vertex %d : ", i, j);
      scanf("%d", &A[i][j]);
    }
  }
  // Cetak Matriks
  printf("\nBentuk matriks : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Cek berarah atau tidak
  bool K = true;
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      if (A[i][j] != A[j][i])
      {
        K = false;
      }
    }
  }
  if (K)
  {
    printf("Graph tidak berarah\n\n");
  }
  else
  {
    printf("Graph berarah\n\n");
  }
}

void derajat()
{
  int v = jumlahVertex();
  // input graph ke matrix
  int A[v][v];
  printf("Jika kedua vertex terhubung ketik 1, jika tidak ketik 0 : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("Vertex %d dan vertex %d : ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  // Cek berarah atau tidak
  bool K = true;
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      if (A[i][j] != A[j][i])
      {
        K = false;
      }
    }
  }

  printf("Bentuk matriks : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  if (K)
  {
    printf("\nGraph tidak berarah\n\n");
  }
  else
  {
    printf("\nGraph berarah\n\n");
  }

  // Menghitung derajat vertex
  if (K)
  {
    /* Tidak berarah */
    int degree[v];
    int degreeTotal = 0;
    for (int i = 1; i <= v; i++)
    {
      degree[i] = 0;
      for (int j = 1; j <= v; j++)
      {
        degree[i] += A[i][j];
      }
      printf("Derajat vertex %d : %d\n", i, degree[i]);
      degreeTotal += degree[i];
    }

    printf("Derajat Graph : %d", degreeTotal);
  }
  else
  {
    /* Berarah */
    int degree[v][2];
    for (int i = 1; i <= v; i++)
    {
      degree[i][1] = 0;
      degree[i][2] = 0;
      for (int j = 1; j <= v; j++)
      {
        degree[i][1] += A[i][j]; // Baris
        degree[i][2] += A[j][i]; // Kolom
      }
      printf("Derajat keluar vertex %d : %d\n", i, degree[i][1]);
      printf("Derajat masuk  vertex %d : %d\n", i, degree[i][2]);
    }
  }
}

void cekGelang()
{
  int v = jumlahVertex();
  // input graph ke matrix
  int A[v][v];
  printf("Jika kedua vertex terhubung ketik 1, jika tidak ketik 0 : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("Vertex%d  dan vertex %d : ", i, j);
      scanf("%d", &A[i][j]);
    }
  }
  // cetak matriks
  printf("Bentuk matriks : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  // cek memiliki gelang
  bool loop = false;
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      if (i == j && A[i][j] != 0)
        loop = true;
    }
  }
  if (loop)
  {
    printf("\nGraph memiliki gelang");
  }
  else
  {
    printf("\nGraph tidak memiliki gelang");
  }
}

void keterhubungan()
{
  // Input matriks
  int v = jumlahVertex();
  int A[v][v];
  printf("Jika kedua vertex terhubung ketik 1, jika tidak ketik 0 : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("Vertex %d dan vertex %d : ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  // cetak matriks
  printf("Bentuk matriks : \n");
  for (int i = 1; i <= v; i++)
  {
    for (int j = 1; j <= v; j++)
    {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  // copy ke matrix M
  int M[v];      // mengetahui keterhubungan
  int T[v];      // apakah telah ditelusuri
  int count = 1; // menghitung banyaknya keterhubungan
  for (int i = 2; i <= v; i++)
  {
    M[i] = A[1][i];
    T[i] = 0;
  }

  // cek keterhubungan
  for (int j = 2; j <= v; j++) // menelusuri dari vertex 2 -> v
    if ((M[j] == 1) && (T[j] == 0))
    { // M[j] == 1 (apakah terhubung), T[j] == 0 (apakah belum ditelusuri)
      T[j] = 1;
      for (int k = 2; k <= v; k++)         // Penelusuran tiap kolom
        if ((A[j][k] == 1) && (M[k] == 0)) // Jika ada edge di matriks dan keterhubungannya masih 0, ubah menjadi 1
          M[k] = 1;
    }

  // print matrix M
  printf("Keterhubungan : ");
  for (int i = 2; i <= v; i++)
  {
    printf("%d ", M[i]);
    count += M[i];
  }
  printf("\n");

  if (count == v)
  {
    printf("\nGraph Terhubung");
  }
  else
  {
    printf("\nGraph Tidak Terhubung");
  }
}

int main()
{
  system("cls");
  // representasi();
  // cekTidakBerarah();
  // keterhubungan();
  derajat();
  // cekGelang();
}
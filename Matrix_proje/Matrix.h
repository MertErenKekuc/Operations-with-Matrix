#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

//Mert Eren Keküç   210229005   Yazýlým Mühendisliði 2.sýnýf

void collection(int line_number,int column_number, int matrix1[line_number][column_number],int matrix2[line_number][column_number])
{

    int result[line_number][column_number];

    printf("\nResult\n");
    for(int i=0; i<line_number; i++)
    {
        for(int j=0; j<column_number; j++)
        {
        result[i][j] = matrix1[i][j] + matrix2[i][j];     //2 matrisin toplanmasý iþlemi
        printf("%d  ",result[i][j]);     //toplam yine bir matris þeklinde yazdýrýlýr
        }
        printf("\n");
    }

}

void multiplication(int line_number,int column_number ,int matrix[line_number][column_number], int number)
{

    int result[line_number][column_number];

    printf("\nResult\n");
    for(int i=0; i<line_number; i++)
    {
        for(int j=0; j<column_number; j++)
        {
        result[i][j] = number * matrix[i][j];     //bir sayi ile matrisin çarpilmasi iþlemi
        printf("%d  ",result[i][j]);     //çarpim yine bir matris þeklinde yazdýrýlýr
        }
        printf("\n");
    }

}

float determinant(float matrix[4][4], int line_number)     //sadece kare matrislerin determinantý olur
{

    int i, j, a, m, n;
    float s = 1,det = 1,temp[4][4];     //gecici olarak kullanmak icin bir matris tanýmlýyoruz

    if (line_number == 1)
        {
        return (matrix[0][0]);
        }
    else
        {
        det = 0;
        for (a = 0; a <line_number; a++)
        {
            m = 0;
            n = 0;
            for (i = 0;i <line_number; i++)
            {
                for (j = 0 ;j <line_number; j++)
                {
                    temp[i][j] = 0;
                    if (i != 0 && j != a)
                    {
                    temp[m][n] = matrix[i][j];     //gecici matrisi kullanýyoruz(elemanlari atama)
                    if (n < (line_number - 2))
                    n++;
                    else
                    {
                     n = 0;
                     m++;
                    }
                    }
                }
            }
          det = det + s * (matrix[0][a] * determinant(temp, line_number - 1));     //burda satýr ve sütun sayisi birer azaltýlarak tekrar yazýlýyor
          s = -1 * s;      //bu formüldeki -1 olan kýsým
        }
    }
    return (det);

}

void cofactor(float matrix[4][4], int line_number)      //tersini hesaplayabilmemiz için kofaktöre ihtiyacýmýz var
{

    int i, j, p, q, m, n;
    float temp[4][4],cof[4][4];     //yine gecici matris kullanýyoruz

    for (q = 0;q <line_number; q++)
    {
    for (p = 0;p <line_number; p++)
        {
        m = 0;
        n = 0;
        for (i = 0;i <line_number; i++)
        {
            for (j = 0;j <line_number ;j++)
            {
                if (i != q && j != p)
                {
                temp[m][n] = matrix[i][j];
                if (n < (line_number - 2))
                n++;
                else
                {
                n = 0;
                m++;
                }
                }
            }
        }
        cof[q][p] = pow(-1, q + p) * determinant(temp, line_number - 1);
        }
    }
  transpose(matrix, cof, line_number);

}

void transpose(float matrix[4][4], float cof[4][4], int line_number)     //transpozunu aldýktan sonra tersini burda yazdýrýyoruz
{
    int i, j;
    float temp[4][4],inverse[4][4], d;

    for (i = 0;i <line_number; i++)
    {
        for (j = 0;j <line_number; j++)
        {
         temp[i][j] = cof[j][i];
        }
    }

    d = determinant(matrix,line_number);     //burda determinanta ihtiyacýmýz olduðu için tekrar çaðýrýyoruz üstteki fonksiyonu
    if(d==0)
    {
        printf("This determinant's inverse is not possible (determinant = 0)");
    }
    else
    {
        for (i = 0;i <line_number; i++)
        {
            for (j = 0;j <line_number; j++)
            {
            inverse[i][j] = temp[i][j] / d;
            }
        }

        printf("\nInverse of matrix \n");     //matrisin tersi burda matris olarak yazdýrýlýyor
        for (i = 0;i <line_number; i++)
        {
            for (j = 0;j <line_number; j++)
            {
            printf("%f  ", inverse[i][j]);
            }
            printf("\n");
        }
    }
}

#endif // MATRIX_H_INCLUDED

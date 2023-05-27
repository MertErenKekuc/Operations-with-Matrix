#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Mert Eren Kek��   210229005   Yaz�l�m M�hendisli�i 2.s�n�f

void collection(int line_number,int column_number, int matrix1[line_number][column_number],int matrix2[line_number][column_number]);
void multiplication(int line_number,int column_number ,int matrix[line_number][column_number], int number);
float determinant(float matrix[4][4], int line_number);
void cofactor(float matrix[4][4], int line_number);
void transpose(float matrix[4][4], float cof[4][4], int line_number);

int main()
{
    int choose;
    printf("Choose a number to calculate  1:collection 2:multiplication 3:determinant 4:inverse\n");
    scanf("%d",&choose);

    if (choose == 1)
    {

        int line_number,column_number;
        printf("Enter line and column number\n");
        scanf("%d%d",&line_number,&column_number);
        int matrix1[line_number][column_number];
        int matrix2[line_number][column_number];

        printf("\nFirst matrix \n");
        for(int i=0; i<line_number; i++)
        {
            for(int j=0; j<column_number; j++)
            {
            printf("[%d][%d]= ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
            }
        }
        printf("Twice matrix \n");
        for(int i=0; i<line_number; i++)
        {
            for(int j=0; j<column_number; j++)
            {
            printf("[%d][%d]= ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
            }
        }
        collection(line_number,column_number,matrix1,matrix2);
    }

    if (choose == 2)
    {
        int line_number,column_number,number;
        printf("Enter a number ");
        scanf("%d",&number);
        printf("Enter line and column number\n");
        scanf("%d%d",&line_number,&column_number);
        int matrix[line_number][column_number];

        printf("\nMatrix \n");
        for(int i=0; i<line_number; i++)
        {
            for(int j=0; j<column_number; j++)
            {
            printf("[%d][%d]= ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
            }
        }
        multiplication(line_number,column_number,matrix,number);
    }

    if(choose == 3)
    {
        int line_number;
        printf("Enter line or column number\n");
        scanf("%d",&line_number);
        float matrix[4][4];

        printf("\nMatrix \n");
        for(int i=0; i<line_number; i++)
        {
            for(int j=0; j<line_number; j++)
            {
            printf("[%d][%d]= ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
            }
        }
        float deter = determinant(matrix,line_number);
        printf("\n%f\n", deter);
    }

    if(choose == 4)
    {
        int line_number,deter;
        printf("Enter line or column number\n");
        scanf("%d",&line_number);
        float matrix[4][4];

        printf("\nMatrix \n");
        for(int i=0; i<line_number; i++)
        {
            for(int j=0; j<line_number; j++)
            {
            printf("[%d][%d]= ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
            }
        }

    cofactor(matrix, line_number);
    }

    return 0;
}

void collection(int line_number,int column_number, int matrix1[line_number][column_number],int matrix2[line_number][column_number])
{

    int result[line_number][column_number];

    printf("\nResult\n");
    for(int i=0; i<line_number; i++)
    {
        for(int j=0; j<column_number; j++)
        {
        result[i][j] = matrix1[i][j] + matrix2[i][j];     //2 matrisin toplanmas� i�lemi
        printf("%d  ",result[i][j]);     //toplam yine bir matris �eklinde yazd�r�l�r
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
        result[i][j] = number * matrix[i][j];     //bir sayi ile matrisin �arpilmasi i�lemi
        printf("%d  ",result[i][j]);     //�arpim yine bir matris �eklinde yazd�r�l�r
        }
        printf("\n");
    }

}

float determinant(float matrix[4][4], int line_number)     //sadece kare matrislerin determinant� olur
{

    int i, j, a, m, n;
    float s = 1,det = 1,temp[4][4];     //gecici olarak kullanmak icin bir matris tan�ml�yoruz

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
                    temp[m][n] = matrix[i][j];     //gecici matrisi kullan�yoruz(elemanlari atama)
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
          det = det + s * (matrix[0][a] * determinant(temp, line_number - 1));     //burda sat�r ve s�tun sayisi birer azalt�larak tekrar yaz�l�yor
          s = -1 * s;      //bu form�ldeki -1 olan k�s�m
        }
    }
    return (det);

}

void cofactor(float matrix[4][4], int line_number)      //tersini hesaplayabilmemiz i�in kofakt�re ihtiyac�m�z var
{

    int i, j, p, q, m, n;
    float temp[4][4],cof[4][4];     //yine gecici matris kullan�yoruz

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

void transpose(float matrix[4][4], float cof[4][4], int line_number)     //transpozunu ald�ktan sonra tersini burda yazd�r�yoruz
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

    d = determinant(matrix,line_number);     //burda determinanta ihtiyac�m�z oldu�u i�in tekrar �a��r�yoruz �stteki fonksiyonu
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

        printf("\nInverse of matrix \n");     //matrisin tersi burda matris olarak yazd�r�l�yor
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

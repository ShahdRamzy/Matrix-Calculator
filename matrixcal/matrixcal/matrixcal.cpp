#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

bool scalar(char text[100])
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' || text[i] == ',')
        {
            return 0;
        }
    }




    return 1;
}


float precision(float matresult)
{
    cout << setprecision(7);
    matresult = matresult * 100;
    matresult = int(matresult);
    matresult = matresult / 100;
    return matresult;
}









int main()
{
    int nrows1 = 1, mcols1 = 0;
    int nrows2 = 1, mcols2 = 0;
    //int rows = 0, cols = 0;
    char op;
    float mat1[100][100];
    float mat2[100][100];
    float matresult[100][100];
    char text1[100];
    char text2[100];
    float c;
    float d;
    float b;
    //float text3[100];
    //int x;
    cin.getline(text1, 100);

    // cout << endl;
     //cout << "enter op";
    cin >> op;
    // cout << op;
    cin.ignore();
    // cin.ignore();
     //cout << endl;

    cin.getline(text2, 100);
    for (int i = 0; i < strlen(text1); i++)
    {
        if (text1[i] >= 'a' && text1[i] <= 'z' || text1[i] >= 'A' && text1[i] <= 'Z')
        {
            cout << "ERROR!";
            return 0;
        }

    }

    for (int i = 0; i < strlen(text2); i++)
    {
        if (text2[i] >= 'a' && text2[i] <= 'z' || text2[i] >= 'A' && text2[i] <= 'Z')
        {
            cout << "ERROR!";
            return 0;
        }

    }

    for (int i = 0; i < strlen(text1) - 1; i++)
    {
        if (text1[i] == ' ' && text1[i + 1] == ' ')
        {
            cout << "ERROR!";
            return 0;
        }

    }

    for (int i = 0; i < strlen(text2) - 1; i++)
    {
        if (text2[i] == ' ' && text2[i + 1] == ' ')
        {
            cout << "ERROR!";
            return 0;
        }

    }



    bool e = scalar(text1);
    bool r = scalar(text2);
    //cout << "boolean = ";
   // cout << e << endl << r<<endl;


    int z = 1;
    int p = 1;
    for (int i = 0; i < strlen(text1); i++)
    {

        if (text1[i] == ',')
        {
            nrows1++;
        }

    }

    for (int j = 0; j < strlen(text1); j++)
    {
        if (text1[j] == ' ')
        {
            z++;
        }
        mcols1 = z / nrows1;
    }
    // cout << nrows1 <<endl<< mcols1;


    for (int i = 0; i < strlen(text2); i++)
    {
        if (text2[i] == ',')
        {
            nrows2++;
        }
    }
    for (int j = 0; j < strlen(text2); j++)
    {
        if (text2[j] == ' ')
        {
            p++;
        }
        mcols2 = p / nrows2;
    }
    // cout << nrows1 <<endl<< mcols1 <<endl<< nrows2 <<endl<< mcols2;

    // getinput1(text1, mat1);
    // getinput1(text2, mat2);


    // int nrows = 0, mcols = 0;
    int count = 1;

    int i = 0;
    int j = 1;
    char* bit = text1 + count;

    mat1[0][0] = atof(bit);

    //cout << mat1[0][0];



    while (count < strlen(text1) - 1 && i <= nrows1 && j <= mcols1)
    {
        if (*bit == ',')
        {
            i++;
            j = 0;
        }
        if (*bit == ' ')
        {
            mat1[i][j] = atof(bit);
            j++;

        }
        count++;
        bit = text1 + count;

    }

    /* for (int m = 0; m < nrows1; m++)
     {
         for (int n = 0; n < mcols1; n++)
         {
             cout << mat1[m][n] << " ";
         }
         cout << endl;
     }*/
    int count2 = 1;
    int t = 0, h = 1;
    char* bit2 = text2 + count2;
    mat2[0][0] = atof(bit2);


    while (count2 < strlen(text2) - 1 && t <= nrows2 && h <= mcols2)
    {
        if (*bit2 == ',')
        {
            t++;
            h = 0;
        }
        else if (*bit2 == ' ')
        {
            mat2[t][h] = atof(bit2);
            h++;

        }
        count2++;
        bit2 = text2 + count2;

    }

    /*  for (int m = 0; m < nrows2; m++)
      {
          for (int n = 0; n < mcols2; n++)
          {
              cout << mat2[m][n] << " ";
          }
          cout << endl;
      }*/


      // float x;


     //  cout << endl;

    if (op == '+')
    {
        if (nrows1 != nrows2 && mcols1 != mcols2)
        {
            cout << "ERROR!" << endl;
            return 0;
        }



        else
        {


            cout << "[";
            for (int i = 0; i < nrows1; i++)
            {
                for (int j = 0; j < mcols1; j++)
                {
                    matresult[i][j] = mat1[i][j] + mat2[i][j];

                    cout << matresult[i][j];

                    if (j != mcols1 - 1)
                    {
                        cout << " ";
                    }


                }
                if (i != nrows1 - 1)
                {
                    cout << ", ";
                }

            }
            cout << "]";

        }
    }


    else if (op == '-')
    {
        if (nrows1 != nrows2 && mcols1 != mcols2)
        {
            cout << "ERROR!" << endl;
            return 0;
        }



        else
        {
            cout << "[";
            for (int i = 0; i < nrows1; i++)
            {
                for (int j = 0; j < mcols1; j++)
                {
                    matresult[i][j] = mat1[i][j] - mat2[i][j];

                    cout << matresult[i][j];

                    if (j != mcols1 - 1)
                    {
                        cout << " ";
                    }


                }
                if (i != nrows1 - 1)
                {
                    cout << ", ";
                }

            }
            cout << "]";


        }
    }




    else if (op == '*')
    {
        if (e == 1)
        {
            c = atof(text1);
            cout << "[";
            for (int k = 0; k < nrows2; k++)
            {
                for (int h = 0; h < mcols2; h++)
                {
                    matresult[k][h] = c * mat2[k][h];
                    // cout<<setprecision(7);
                    b = precision(matresult[k][h]);
                    cout << b;
                    if (h != mcols2 - 1)
                    {
                        cout << " ";
                    }
                }
                if (k != nrows2 - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]";
        }

        else if (r == 1)
        {
            d = atof(text2);
            cout << "[";
            for (int k = 0; k < nrows1; k++)
            {
                for (int h = 0; h < mcols1; h++)
                {
                    matresult[k][h] = mat1[k][h] * d;
                    //  cout << setprecision(7);
                    b = precision(matresult[k][h]);
                    cout << b;
                    if (h != mcols1 - 1)
                    {
                        cout << " ";
                    }
                }
                if (k != nrows1 - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]";
        }





        else if (mcols1 != nrows2)
        {
            cout << "ERROR!" << endl;
            return 0;
        }



        else
        {
            cout << "[";
            for (int i = 0; i < nrows1; i++)
            {
                for (int j = 0; j < mcols2; j++)
                {
                    float sum = 0.0;
                    for (int z = 0; z < mcols1; z++)
                    {
                        sum += mat1[i][z] * mat2[z][j];


                    }
                    matresult[i][j] = sum;
                    cout << matresult[i][j];
                    if (j != mcols2 - 1)
                    {
                        cout << " ";
                    }

                }
                if (i != nrows1 - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]";




        }
    }


    else
    {
        cout << "ERROR!";
    }








}








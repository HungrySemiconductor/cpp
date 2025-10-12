#include <iostream>
#include <float.h>

struct Matrix
{
    int rows;
    int cols;
    float *pdata;
};

float matrix_max(struct Matrix mat)
{
    float max = FLT_MIN;
    for (int r = 0; r < mat.rows; r++)
    {
        for (int c = 0; c < mat.cols; c++)
        {
            float val = mat.pdata[r * mat.cols + c];
            max =  (max > val ? max : val);
        }
    }
    return max;
}

int main()
{
    using namespace std;

    Matrix matA = {2,4};
    matA.pdata = new float[matA.rows * matA.cols]{1.f, 2.f, 3.f};

    Matrix matB = {4,8};
    matB.pdata = new float[matB.rows * matB.cols]{10.f, 20.f, 30.f};

    Matrix matC = {6,10};
    matC.pdata = new float[matC.rows * matC.cols]{100.f, 200.f, 300.f};

    float maxa = matrix_max(matA);
    cout << "maxa: " << maxa << endl;
    float maxb = matrix_max(matB);
    cout << "maxb: " << maxb << endl;
    float maxc = matrix_max(matC);
    cout << "maxc: " << maxc << endl;
}
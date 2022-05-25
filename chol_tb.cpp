
/********* testbench of Cholesky **********/
//; $SIZE = param_define("SIZE", 4);
#include "chol.h"
#include "hls/linear_algebra/utils/x_hls_matrix_utils.h"
//#include "hls/linear_algebra/utils/x_hls_matrix_tb_utils.h"
using namespace hls;

int main ()
{
	int Cholesky_success = 0;
	int fail = 0;
	int i, j;
	int A[4][4]={{6,15,55,25},{15,55,225,70},{55,225,979,90},{25,70,90,1000}};
	float L[16];
	matrix_t Ar[matrix_size][matrix_size];

    int array[16];

    array[0]=A[0][0];
    array[1]=A[0][1];
    array[2]=A[0][2];
    array[3]=A[0][3];

    array[4]=A[1][0];
    array[5]=A[1][1];
    array[6]=A[1][2];
    array[7]=A[1][3];

    array[8] =A[2][0];
    array[9] =A[2][1];
    array[10]=A[2][2];
    array[11]=A[2][3];

    array[12]=A[3][0];
    array[13]=A[3][1];
    array[14]=A[3][2];
    array[15]=A[3][3];

     top(array, L);
	// Now re-create A: Ar = L * L'
    //hls::matrix_multiply<hls::NoTranspose,hls::Transpose,matrix_size,matrix_size,matrix_size,matrix_size,matrix_size,matrix_size,matrix_t,matrix_t>(L, L, Ar);

    printf("A = \n");
    //hls::print_matrix<matrix_size, matrix_size, matrix_t, hls::NoTranspose>(A, "   ");

    printf("L = \n");
    //hls::print_matrix<matrix_size, matrix_size, matrix_t, hls::NoTranspose>(L, "   ");

    printf("A reconstructed = \n");
    //hls::print_matrix<matrix_size, matrix_size, matrix_t, hls::NoTranspose>(Ar, "   ");

    // Generate error ratio and compare against threshold value
    // - LAPACK error measurement method
    // - Threshold taken from LAPACK test functions
    //int -> float

    return 0;
}

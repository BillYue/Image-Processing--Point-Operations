#include "mex.h"


double contrast_piecewise (int length, int width,  const unsigned char *input, unsigned char *output,int s1,int s2,int r1, int r2)
{
    
       double a1,a2,a3;
    
       if(s1 == 0)
       a1= 0;
       else
       a1= (r1/s1);
       
       a2 = (r2-r1)/(s2-s1);
       a3 = ((255)-r2)/((255)-s2);
   for (int y = 0; y < length; y++)
        for (int x = 0; x < width; x++)
        {
            int ind = x*length + y;
          
            if(input[ind] < r1)
            output[ind] = a1 * input[ind];
            
            else if((input[ind] >= r1) && (input[ind] < r2))
            output[ind] = (a2 * (input[ind] - r1)) + s1;
            
            else 
            output[ind] = (a3 *(input[ind] - r2)) + s2;
          
    }
}
void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{    
  
    unsigned char *input;
    if (nrhs < 1)
         mexErrMsgTxt("invert_colours can only accept one input argument");
    if (nlhs != 1)
         mexErrMsgTxt("invert_colours requires one output argument");
	 
	 
	 
  double *a, *b;
  int r1, r2, s1, s2; 
  const mxArray *img = prhs[0];
  a =  (double *)mxGetData(prhs[1]);
  b  = (double *)mxGetData(prhs[2]);

  r1 = (int) a[0];
  s1 = (int) a[1];
  r2 = (int) b[0];
  s2 = (int) b[1];
  const mwSize *dims = mxGetDimensions(prhs[0]);
  int height     = dims[0];
  int width      = dims[1];
  mxArray *output = mxCreateNumericArray(2, dims, mxGetClassID(prhs[0]), mxREAL);
  plhs[0] = output;
  unsigned char *out_ptr = (unsigned char *)mxGetData(output);
  unsigned char *img_ptr = (unsigned char *)mxGetData(img);
  mxIsUint8(img);
 
 contrast_piecewise(height, width, img_ptr, out_ptr,s1, s2, r1, r2);
 
}
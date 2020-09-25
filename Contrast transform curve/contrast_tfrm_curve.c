#include "mex.h"


double contrast_tfrm_curve(int length, int width,  const unsigned char *input, unsigned char *output,const unsigned char *T)
{
    
       int count = 0; 
    
    
   for (int y = 0; y < length; y++)
        for (int x = 0; x < width; x++)
        {
            int ind = x*length + y;
          
           
            output[ind] = (double)(T[input[ind]]);
            
            
          
    }
}
void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{    
  
    unsigned char *input,*T;
    if (nrhs < 1)
         mexErrMsgTxt("invert_colours can only accept one input argument");
    if (nlhs != 1)
         mexErrMsgTxt("invert_colours requires one output argument");
	 
	 
	 
  
  int r1, r2, s1, s2; 
  const mxArray *img = prhs[0];
    T = (unsigned char *) mxGetPr(prhs[1]);
  

  
  const mwSize *dims = mxGetDimensions(prhs[0]);
  
  int height     = dims[0];
  int width      = dims[1];
  mxArray *output = mxCreateNumericArray(2, dims, mxGetClassID(prhs[0]), mxREAL);
  plhs[0] = output;
  unsigned char *out_ptr = (unsigned char *)mxGetData(output);
  unsigned char *img_ptr = (unsigned char *)mxGetData(img);
  mxIsUint8(img);
 
 contrast_tfrm_curve(height, width, img_ptr, out_ptr,T);
 
}
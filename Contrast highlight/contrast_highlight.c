#include "mex.h"


void contrast_piecewise (int height, int width,  const unsigned char *input, unsigned char *output,int A,int B)
{
    
       double a1,a2,a3,minimum;
       int x,y;
        minimum = 20;
//for ( y = 0; y < height; y++)
  //      for ( x = 0; x < width; x++)
    //    {
		//	int ind = x*height + y;
			//if (input[ind] < minimum)
			//{
				//minimum = input[ind];
				
		//	}
        //}

  for (y = 0; y < height; y++)
        for ( x = 0; x < width; x++)
        {
            int ind = x*height + y;
          
            if(input[ind] < A)
            output[ind] = minimum;
            
            else if((input[ind] >= A) && (input[ind] < B))
            output[ind] = input[ind];
            
            else 
            output[ind] = minimum;
          
    }
}
void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{    
  
    unsigned char *input;
    if (nrhs < 1)
         mexErrMsgTxt("invert_colours can only accept one input argument");
    if (nlhs != 1)
         mexErrMsgTxt("invert_colours requires one output argument");
	 
	 
	 
  double A, B;
  int r1, r2, s1, s2; 
  const mxArray *img = prhs[0];
  A =  mxGetScalar(prhs[1]);
  B  = mxGetScalar(prhs[2]);


  const mwSize *dims = mxGetDimensions(prhs[0]);
  int height     = dims[0];
  int width      = dims[1];
  mxArray *output = mxCreateNumericArray(2, dims, mxGetClassID(prhs[0]), mxREAL);
  plhs[0] = output;
  unsigned char *out_ptr = (unsigned char *)mxGetData(output);
  unsigned char *img_ptr = (unsigned char *)mxGetData(img);
  mxIsUint8(img);
 
 contrast_piecewise(height, width, img_ptr, out_ptr,A,B);
 
}
#include "mex.h"
#include <math.h>
void invertDouble(int width, int height, const double *input, double *output)
{
}



double apply_mask(int width, int height, const unsigned char *input_a,const unsigned char *input_b,const unsigned char *input_m,unsigned char *output)
{

    int x,y;
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
        {
            int ind = x*height + y;
            if (input_m[ind] > input_b[ind])
			output[ind] = input_a[ind];
			
			else
			output[ind] = input_m[ind];	
        }
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
//  double B=1;
//  double C=1;
  //if (nlhs != 1)
    //    mexErrMsgTxt("invert_colours can only accept one input argument");
    
   // if (nrhs != 1)
     //   mexErrMsgTxt("invert_colours requires one output argument");
    
    
    const mxArray *img_m = prhs[0];
	const mxArray *img_a = prhs[1];
	const mxArray *img_b = prhs[2];

    mwSize ndims = mxGetNumberOfDimensions(img_m);
	//mwSize ndims2 = mxGetNumberOfDimensions(img_a);
	// mwSize ndims3 = mxGetNumberOfDimensions(img_b);

    const mwSize *dims = mxGetDimensions(img_m);
//	const mwSize *dims2 = mxGetDimensions(img_a);
//	const mwSize *dims3 = mxGetDimensions(img_b);

    int height_m   = dims[0];
    int width_m    = dims[1];
   
//   int height_a   = dims_a[0];
//    int width_a    = dims_a[1];
	
//    int height_b   = dims_b[0];
//    int width_b    = dims_b[1];
	
	
    
	mxClassID input_type = mxGetClassID(img_m);
    
    mxArray *output = mxCreateNumericArray(ndims, dims, input_type, mxREAL);
    plhs[0] = output;
   
    mxIsUint8(img_m);
	 mxIsUint8(img_a);
	 mxIsUint8(img_b);
    
        unsigned char *img_ptr_m = (unsigned char *)mxGetData(img_m);
		unsigned char *img_ptr_a = (unsigned char *)mxGetData(img_a);
		unsigned char *img_ptr_b = (unsigned char *)mxGetData(img_b);
        unsigned char *out_ptr = (unsigned char *)mxGetData(output);
      
        apply_mask(width_m, height_m, img_ptr_a, img_ptr_b, img_ptr_m, out_ptr);
    
    
}

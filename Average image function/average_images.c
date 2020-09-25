#include "mex.h"
#include <math.h>
void invertDouble(int width, int height, const double *input, double *output)
{
}



double average_images(int width, int height, const unsigned char *input_1,const unsigned char *input_2,const unsigned char *input_3,const unsigned char *input_4,unsigned char *output)
{

    int x,y;
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
        {
            int ind = x*height + y;
            
			output[ind] = (input_1[ind]+input_2[ind]+input_3[ind]+input_4[ind])/4;
			
			
        }
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
//  double B=1;
//  double C=1;
  //if (nlhs != 1)
    //    mexErrMsgTxt("invert_colours can only accept one input argument");
    
   // if (nrhs != 1)
     //   mexErrMsgTxt("invert_colours requires one output argument");
    
    
    const mxArray *img_1 = prhs[0];
	const mxArray *img_2 = prhs[1];
	const mxArray *img_3 = prhs[2];
	const mxArray *img_4 = prhs[3];

    mwSize ndims = mxGetNumberOfDimensions(img_1);
	//mwSize ndims2 = mxGetNumberOfDimensions(img_a);
	// mwSize ndims3 = mxGetNumberOfDimensions(img_b);

    const mwSize *dims = mxGetDimensions(img_1);
//	const mwSize *dims2 = mxGetDimensions(img_a);
//	const mwSize *dims3 = mxGetDimensions(img_b);

    int height   = dims[0];
    int width    = dims[1];
   
//   int height_a   = dims_a[0];
//    int width_a    = dims_a[1];
	
//    int height_b   = dims_b[0];
//    int width_b    = dims_b[1];
	
	
    
	mxClassID input_type = mxGetClassID(img_1);
    
    mxArray *output = mxCreateNumericArray(ndims, dims, input_type, mxREAL);
    plhs[0] = output;
   
    mxIsUint8(img_1);
	 mxIsUint8(img_2);
	 mxIsUint8(img_3);
	 mxIsUint8(img_4);
    
        unsigned char *img_ptr_1 = (unsigned char *)mxGetData(img_1);
		unsigned char *img_ptr_2 = (unsigned char *)mxGetData(img_2);
		unsigned char *img_ptr_3 = (unsigned char *)mxGetData(img_3);
		unsigned char *img_ptr_4 = (unsigned char *)mxGetData(img_4);
        unsigned char *out_ptr = (unsigned char *)mxGetData(output);
      
    average_images(width, height, img_ptr_1, img_ptr_2, img_ptr_3,img_ptr_4 ,out_ptr);
    
    
}

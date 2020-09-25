#include "mex.h"
#include <math.h>
void invertDouble(int width, int height, const double *input, double *output)
{
}



double contrast_stretch(int width, int height, const unsigned char *input, unsigned char *output)
{
	
	int x,y;
    double minimum = input[0];
	double maximum = input[0];

   
	 for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
        {
			int ind = x*height + y;
			if (input[ind] < minimum)
			{
				minimum = input[ind];
				
			}
        }
		
		
	 for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
        {
			int ind = x*height + y;
			if (input[ind] > maximum)
			{
				maximum = input[ind];
				
			}
        }
          printf("max is %lf, min is %lf" , maximum,minimum);
    
	
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
        {
            int ind = x*height + y;
           output[ind] = (double)(255*((1/(maximum-minimum)*input[ind])-(minimum/(maximum-minimum))));
		
	    }
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
//  double B=1;
//  double C=1;
  if (nlhs != 1)
        mexErrMsgTxt("invert_colours can only accept one input argument");
    
    if (nrhs != 1)
        mexErrMsgTxt("invert_colours requires one output argument");
    
    
    const mxArray *img = prhs[0];
    if (!mxIsDouble(img) && !mxIsUint8(img))
        mexErrMsgTxt("invert_colours can only accept images of type 'double' or 'uint8'");
    
    
    mwSize ndims = mxGetNumberOfDimensions(img);
    const mwSize *dims = mxGetDimensions(img);
    
    
    int height   = dims[0];
    int width    = dims[1];
    
    
    mxClassID input_type = mxGetClassID(img);
    
    mxArray *output = mxCreateNumericArray(ndims, dims, input_type, mxREAL);
    plhs[0] = output;
   
   
     if (mxIsUint8(img))
    {
        unsigned char *img_ptr = (unsigned char *)mxGetData(img);
        unsigned char *out_ptr = (unsigned char *)mxGetData(output);
        
         contrast_stretch(width, height, img_ptr, out_ptr);
    }
    else if (mxIsDouble(img))
    {
        // TODO: implement this
    }
  
      
       
    
    
}

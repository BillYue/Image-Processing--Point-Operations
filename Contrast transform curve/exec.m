%a = 2;
x = 0:255;
%lut = 255 ./ (1+exp(-a*(x-127)/32));
lut = x;

mex contrast_tfrm_curve.c
%img = imread(3096.jpg');
img = imread('208001.jpg');
out =  contrast_tfrm_curve(img,x); %format is(img,a,b) where a and b are [r1,s1],[r2,s2]
figure(1); imshow(img); title('Original');
figure(2); imshow(out); title('Reconstructed image with lookup table');

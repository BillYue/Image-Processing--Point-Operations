
mex contrast_piecewise.c
%img = imread('7.1.01.tiff');
img = imread('7.2.01.tiff');
%out =  contrast_piecewise(img,[95,32],[160,223]); %format is(img,a,b) where a and b are [r1,s1],[r2,s2]
out =  contrast_piecewise(img,[50,80],[170,200]); %format is(img,a,b) where a and b are [r1,s1],[r2,s2]
figure(1); imshow(img); title('Original');
figure(2); imshow(out); title('Contrast pieacewise image');

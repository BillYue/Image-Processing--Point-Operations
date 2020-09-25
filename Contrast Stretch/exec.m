
mex contrast_stretch.c
%img = imread('183087.jpg');
img = imread('motion01.512.tiff');
out =  contrast_stretch(img); %format is(img,B,C) where Ip=C*I+B
figure(1); imshow(img); title('Original');
figure(2); imshow(out); title('Contrast stretched image');

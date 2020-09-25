
mex contrast_highlight.c
%img = imread(3096.jpg');
img = imread('208001.jpg');
out =  contrast_highlight(img,55,255); %format is(img,a,b) where a and b are [r1,s1],[r2,s2]
figure(1); imshow(img); title('Original');
figure(2); imshow(out); title('Contrast hightlighted image');

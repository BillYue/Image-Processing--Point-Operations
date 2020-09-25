
mex apply_point_tfrm.c
img = imread('183087.jpg');
%img = imread('207056.jpg');
out = apply_point_tfrm(img,110,3); %format is(img,B,C) where Ip=C*I+B
imshow(out); title('point operated Image');

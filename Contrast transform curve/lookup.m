a = 2;
x = 0:255;
lut = 255 ./ (1+exp(-a*(x-127)/32));
plot (lut)
clc
clear all
close all
tic

filename = 'D:\FDU\Template\CS\数学建模\coordinate.txt';
[index,cor_x,cor_y,cor_z] = textread(filename,'%n%n%n%n');
cor_data = [index cor_x cor_y cor_z];
LIFE = 600;
DELTA_T = 0.1;
SCALE = 60; 
for ii = 0:round(LIFE/DELTA_T);
    temp_x = cor_x(1+ii*100:ii*100+100,1);
    temp_y = cor_y(1+ii*100:ii*100+100,1);
    temp_z = cor_z(1+ii*100:ii*100+100,1);
    plot3(temp_x,temp_y,temp_z,'*')
    axis([-100*SCALE,100*SCALE,-100*SCALE,100*SCALE,-100*SCALE,100*SCALE])
    grid on
    pause(0.01)
    
end
toc
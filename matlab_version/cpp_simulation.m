clc
clear all
close all
tic

filename = 'D:\FDU\Template\CS\数学建模\coordinate.txt';
%[x1,x2,x3,x4,x5] = textread(filename,'%7.6f%7.6f%7.6f%7.6f%7.6f');
[index,cor_x,cor_y,cor_z,radius,tails] = textread(filename,'%n%n%n%n%n%s');
cor_data = [index cor_x cor_y cor_z];
LIFE = 1000;
DELTA_T = 0.1;
SCALE = 60; 
SIZE = 2;
see_scare = 0.5;
for ii = 0:round(LIFE/DELTA_T)
    temp_x = cor_x(1+ii*SIZE:ii*SIZE+SIZE,1);
    temp_y = cor_y(1+ii*SIZE:ii*SIZE+SIZE,1);
    temp_z = cor_z(1+ii*SIZE:ii*SIZE+SIZE,1);
    plot3(temp_x,temp_y,temp_z,'*')
    axis([-see_scare*SCALE,see_scare*SCALE,-see_scare*SCALE,see_scare*SCALE,-see_scare*SCALE,see_scare*SCALE])
    grid on
    
    %to save the plot as gif
    F = getframe(gcf);
    I = frame2im(F);
    [I,map] = rgb2ind(I,256);
    if ii == 0
        imwrite(I,map,'2_molecule.gif','gif','Loopcount',inf,'DelayTime',0.001);
    elseif rem(ii,100)==0
        imwrite(I,map,'2_molecule.gif','gif','WriteMode','append','DelayTime',0.001);
    end
    
    pause(0.001)
    
end
toc
clc
clear all
close all
tic
s = 100;
% r = 1:100;
k1 = 1;
k2 = 1.5;
% F1 = k1./r.^2;
% F2 = k2./r.^3;

% F = F2 - F1;
num = 500;

X = s*rand(num,1)-50;
Y = s*rand(num,1)-50;
Z = s*rand(num,1)-50;
alpha = 1;

Vx = 1*rand(num,1)-0.5;
Vy = 1*rand(num,1)-0.5;
Vz = 1*rand(num,1)-0.5;
t = 1;


figure;

for ii = 1:5000;
    
    Xa = repmat(X,1,num); Xa(logical(eye(num)))=99999;
    XX = repmat(X',num,1);
%     ax = sum(alpha*( (k2./(Xa - XX).^2) - (k1./(Xa - XX).^2) + 0 ))';
    
    
    
    Ya = repmat(Y,1,num); Ya(logical(eye(num)))=99999;
    YY = repmat(Y',num,1);
%     ay = sum(alpha*( (k2./(Ya - YY).^2) - (k1./(Ya - YY).^2) + 0 ))';
    
    
    Za = repmat(Z,1,num); Za(logical(eye(num)))=99999;
    ZZ = repmat(Z',num,1);
%     az = sum(alpha*( (k2./(Za - ZZ).^2) - (k1./(Za - ZZ).^2) + 0 ))';
    
    a = alpha*( (k2./( (Xa - XX).^2+(Ya - YY).^2+(Za - ZZ).^2 )) - (k1./sqrt( (Xa - XX).^2 + (Ya - YY).^2 + (Za - ZZ).^2 ).^3) );
    
    dx = XX-Xa;
    dy = YY-Ya;
    dz = ZZ-Za;
    L = sqrt(dx.^2 + dy.^2 + dz.^2);
    dx = dx./L;
    dy = dy./L;
    dz = dz./L;
    
    ax = -sum(a.*dx)';
    ay = -sum(a.*dy)';
    az = -sum(a.*dz)';
    
    
    
    X = X + 0.5*ax*t^2 + Vx*t;
    Vx = Vx+ax*t;
    Vxx = Vx;
    Vxx(abs(X)<1*s)=0;
    Vx(abs(X)>=1*s)=0;
    Vx = Vx - Vxx;
    
    Y = Y + 0.5*ay*t^2 + Vy*t;
    Vy = Vy+ay*t;
    Vyy= Vy;
    Vyy(abs(Y)<1*s)=0;
    Vy(abs(Y)>=1*s)=0;
    Vy = Vy - Vyy;
    
    Z = Z + 0.5*az*t^2 + Vz*t;
    Vz = Vz+az*t;
    Vzz = Vz;
    Vzz(abs(Z)<1*s)=0;
    Vz(abs(Z)>=1*s)=0;
    Vz = Vz - Vzz;
    
    plot3(X,Y,Z,'*')
    axis([-2*s,2*s,-2*s,2*s,-2*s,2*s])
    grid on
    pause(0.01)
    
end



toc

close all;
clear;
clc


%Reading logging file from veristand simple thrust allocation
Array = csvread('C:\Users\MCLab\Documents\GitHub\GROUP4_CS_Enterprise_CRIOlab\Logs\2017\02\06\Log File_10_05_59.csv', 1);

L2_continious = Array(:,1);
PosXRight = Array(:,2);
R2_continous = Array(:,3);
alpha_VPS1 = Array(:,4);
u_BT = Array(:, 5);
u_VSP1= Array(:, 6);
PosYRight = Array(:,7)
t = Array(:, 8) - Array(1, 8);
alpha_VPS2 = Array(:,9);
u_VSP2= Array(:, 10);



%figure
subplot(3,1,1)
hold on;
plot(t,u_VSP1,'-r');
plot(t,u_VSP2,'-b');
legend('u\_VSP1','u\_VPS2');
title('u\_VSP1 and u\_VSP2');
ylabel('u [N]');
xlabel('Absolute time [s]')
axis([0 60 -1.2 1.2])
grid on;


subplot(3,1,2)
plot(t,u_BT,'-r');
title('u\_BT');
ylabel('u [N]');
xlabel('Absolute time [s]')
grid on;


subplot(3,1,3)
hold on;
plot(t,alpha_VPS1,'-r');
plot(t,alpha_VPS2,'-b');
legend('alpha\_VPS1','alpha\_VPS2');
title('alpha\_VPS1 and alpha\_VPS2');
xlabel('Absolute time [s]');
ylabel('alpha [rad]');
grid on;


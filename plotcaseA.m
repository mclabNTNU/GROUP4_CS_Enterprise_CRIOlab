%Reading logging file from veristand simple thrust allocation
Array = csvread('C:\Users\MCLab\Documents\GitHub\GROUP4_CS_Enterprise_CRIOlab\Logs\2017\02\03\Log File_10_49_31.csv', 1);
u_BT = Array(:, 1);
u_VSP= Array(:, 2);
t = Array(:, 3) - Array(1, 3);

%Plotting the forces and moments
figure(1)
plot(t,u_BT);
title('Joystick control yaw')
xlabel('Time');
ylabel('Yaw moment');
grid on;

figure(2)
plot(t,u_VSP);
title('Joystick control surge')
xlabel('Time');
ylabel('Surge force');
grid on;


function [] = calc_pi(u)
n = 1;
while n <= u
    [krog1, kvadrat1, nic1] = mcc_pi(n);
    [aproksimacija, odstopanje] = area_pi(krog1, kvadrat1)
    n = n*10;
end

x1 = krog1(:, 1);
y1 = krog1(:, 2);

x2 = kvadrat1(:, 1);
y2 = kvadrat1(:, 2);

x3 = nic1(:, 1);
y3 = nic1(:, 2);

m = linspace(-1, 1, 1001);
zgoraj = @(m) sqrt(1 - m.^2);
spodaj = @(m) -sqrt(1 - m.^2);

axis square
plot(x1, y1, "ro", "DisplayName","točke znotraj krožnice")
hold on
axis square
plot(x2, y2, "bx","DisplayName","točke znotraj kvadrata in izven krožnice")
hold on
axis square
plot(x3, y3, "k.", "DisplayName","točke izven kvadrata")
hold on
axis square
plot(m, zgoraj(m), "k","DisplayName","zgornji in", LineWidth = 2)
plot(m, spodaj(m), "k","DisplayName","spodnji del krožnice", LineWidth = 2)
legend
title("Aproksimacija π po metodi Monte Carlo")
xlabel("x")
ylabel("y")

function [aproksimacija1, odstopanje1] = area_pi(krog1, kvadrat1)
kr = size(krog1, 1);
kv = size(kvadrat1, 1) + kr;
aproksimacija1 = 4*(kr/kv);
odstopanje1 = aproksimacija1 - pi;
end

end
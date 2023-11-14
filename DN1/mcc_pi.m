function [krog, kvadrat, nic] = mcc_pi(u)
krog = [];
kvadrat = [];
nic = [];
i = 0;
while i < u
    x = 3*rand(1) - 1.5;
    y = 3*rand(1) - 1.5;
    i = i + 1;
    if x^2 + y^2 <= 1
        krog = [krog; x, y];
    elseif x >= -1 && x <= 1 && y >= -1 && y <= 1
        kvadrat = [kvadrat; x, y];
    else
        nic = [nic; x, y];
    end
end
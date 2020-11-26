data = load('doan2.txt');
x = [data(:,1)];
y = [data(:,2)];

% Plot the Data
%plot(x, y, 'r*','Linewidth',1);
%title('Hinh anh');
%xlabel('x'); 
%ylabel('y');

n = length(x);    
X = [ones(n,1),x];
N = 1000000;  %gioi han vong lap         
alpha = 6;  %leaning rate 
esp=1e-6;
% khoi tao gia tri ban dau
w(1)=0;
w(2)=w(1);
dh1(1)=1;dh2(1)=1;
L(1)=0;L(2)=1;
% Gradient Descent
k=2
while ((k <=N) & (abs(L(k)-L(k-1))>esp))
    k=k+1; 
    Y = X*w';
    L(k)=(1/2*n) * sum((Y-y).^2);%ham mat mat
    dh1(k)=(1 / n) * sum(Y - y);%dao ham rieng w1
    dh2(k)=(1 / n) * sum((Y - y) .* x);%dao ham rieng w2
    w(1) = w(1) - (alpha * dh1(k));
    w(2) = w(2) - (alpha * dh2(k));
end
%hold on;
%plot(x,X*w','-g','Linewidth',2);
plot(L,'Linewidth',2);
 

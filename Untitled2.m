m=randn(1,1000);
x=m';
y=3*x-4;
A=[m;y'];
fid=fopen('cotx2.txt','w');
%fprintf(fid,'cot X\n');
fprintf(fid,'%.2f \n',x);
fclose(fid);
fid=fopen('coty2.txt','w');
%fprintf(fid,'cot y\n');
fprintf(fid,'%.2f \n',y);
fclose(fid);
fid=fopen('doan3.txt','w');
fprintf(fid,'%6.2f %12.2f\n',A);
fclose(fid);
type doan3.txt
type cotx1.txt
type coty1.txt

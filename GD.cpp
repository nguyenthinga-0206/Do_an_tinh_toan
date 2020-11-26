#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;
  
void Nhap(float x[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for(int i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
}
void Intput(float x[], float y[], int n )
{
	float data[1001][2];
	ifstream doan("doan1.txt");
	//doc du lieu tu file 
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < 2; j++)
        {
            doan >> data[i][j];
        }
    }        
    //xuat du lieu tu file
    cout << "\nNhap X:" << endl;
    for(int i = 0; i < n; i++)
    {
    	x[i] = data[i][0];
        cout << x[i] << " ";
    }
    cout << "\nNhap Y:" << endl;
    for(int i = 0; i < n; i++)
    {
    	y[i] = data[i][1];
        cout << y[i] << " ";
    }
    //dong file
    doan.close();
}
/* Ham tri tuyet doi */
float fab(float a)
{
	if(a >= 0)
		return a;
	else 
		return (-1)*a;
}
/* Ham gradient */
void Gradient(float x[], float y[], int n, float alpha, float w0, float w1, float esp, int N)
{
	float L[N], Y[1001], ss[1001], MSE=0;
	float dh0 = 1, dh1 = 1;
	L[0] = 0; L[1] = 1; 
	
	int k = 1;
	while(k <= N && fab(L[k]-L[k-1]) > esp)
	{
		k++;
		
		/* Ham mat mat */
		L[k] = 0;
		for(int i = 0; i < n; i++)
		{
			L[k] += (pow((w0 + w1 * x[i]) - y[i],2));
		}
		L[k] /= (2*n);
		
		/* Tinh gia tri dao ham rieng doi voi w0 */
		dh0 = 0;
		for(int i = 0; i < n; i++)
		{
			dh0 += ((w0 + w1 * x[i]) - y[i]);
		}
		dh0 /= n;
		
		/* Tinh gia tri dao ham rieng doi voi w1 */
		dh1 = 0;
		for(int i = 0; i < n; i++)
		{
			dh1 += (((w0 + w1 * x[i])- y[i]) * x[i]);
		}
		dh1 /= n;
		
		/* Cap nhat lai gia tri */
		w0 = w0 - (alpha * dh0);
		w1 = w1 - (alpha * dh1);
		
		/* Xuat cac gia tri */	
		cout << fixed;//ki hieu dau phay dong co dinh
		cout << setprecision(5);
		cout << "Vong lap thu " << k-1 << ": \tw0 = " <<w0 << "\tw1 = " << w1 << "\tHam mat mat= " << L[k] << "\tDo lech= " << fab(L[k]-L[k-1]) <<endl;
	}
	
	/*In ham*/
	if((L[k]-L[k-1]) <= esp)
	{
		cout << "\nHam can tim la:" << endl;
		if(w0 > 0)
		{
			cout << "\t\ty = " << w1 << "x + " << w0 << endl; 
		}
		else if(w0 < 0)
		{
			cout << "\t\ty = " << w1 << "x - " << (-1)*w0 << endl; 
		}
		else 
		{
			cout << "\t\ty = " << w1 << "x" << endl;
		}
		/*Ket qua du doan va sai so*/
		cout << "\n\t\t============================BANG KET QUA DU DOAN==================================\n" << endl;
		cout << "\t\tCotx \t\tCoty \t\tKq du doan \t\tSai so" << endl;
		for(int i = 0; i < n; i++)
		{
			Y[i] = x[i] * w1 + w0;
			ss[i] = Y[i] - y[i];
			cout << fixed;
			cout << setprecision(5);
			cout << "\t\t" << x[i] << " \t" << y[i] << " \t" << Y[i] << " \t\t" << ss[i] << endl;
		}
		
		cout << "\nSai so du doan:\t";
		for(int i = 0; i < n; i++)
		{
			MSE += pow(ss[i],2);
		}
		MSE = sqrt(MSE/n);
		cout << MSE;
	}
	else
	{
		cout << "\nChua tim duoc ham" << endl;
	}
	
}
/*Ham chinh*/
int main()
{
	float x[1001], y[1001], alpha, w0, w1, esp;
	int n, N;
	int s;
	
	cout << "Chon cach nhap du lieu(doc file chon 1, nhap tay chon 2): ";
	cin >> s;
	
	switch(s)
	{
		case 1:
			Intput(x, y, n);
			break;
		case 2:
			cout << "Nhap x: ";
			Nhap(x,n);
			cout << "\nNhap y: ";
			Nhap(x,n);
	}
	
	cout << "Nhap n: ";
	cin >> n;
	
	cout << "\n\nGioi han duoi esp= ";
	cin >> esp;
	cout << "\nGioi han vong lap N= ";
	cin >> N;
	cout << "\nNhap alpha(learning rate)= ";
	cin >> alpha;
	cout << "\nGia tri khoi tao " <<endl;
	cout << "\t w0 = w1 = ";
	cin >> w0;
	w1 = w0;
	
	cout << "\n\t\t======================GIA TRI TUONG UNG VOI MOI LAN LAP===========================\n" << endl;
	Gradient(x, y, n, alpha, w0, w1, esp ,N);
	
	return 0;
}

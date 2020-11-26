 #include<iostream>
#include<math.h>
#include<fstream>
#include<iomanip>
#include <stdlib.h>
#define max 100
using namespace std;
// THEM MOT HANG VAO MA TRAN
float them(float X1[max][max],int n,int m,float a[max][max])
{     
int i,j,k;
cout<<"\n chen 1 hang vao ma tran";
cout<<"\nNhap hang can chen:k=";cin>>k;
    for(i=n;i>k-2;i--)
    {
         for(j=0;j<m;j++)
         {
              X1[i+1][j]=a[i][j];
          }
    }
    for(j=0;j<m;j++)
    {
     X1[k-1][j]=1;
    }
}
// HAM TINH DINH THUC CUA MA TRAN
float tinhdet(float X[][max], int n) {
	float c[max][max];
	for (int r = 0; r < n; r++) {
		for (int t = 0; t < n; t++){
			c[r][t] = X[r][t];
	           }
       }
	for (int i = 0; i < n - 1; i++){
		int j = i;
		while (c[j][i] == 0) {
			j++;
		}
		if (j != i) {
			for (int k = 0; k < n; k++) {
				float A = c[i][k];
				c[i][k] = c[j][k];
				c[j][k] = A;
			}
		}
		for (int p = i + 1; p < n; p++) {
			if (c[p][i] == 0) continue;
			if (c[p][i] != 0) {
				float m = -c[p][i] / c[i][i];
				for (int q = i; q < n; q++) 
                                            {
					c[p][q] = c[p][q] + (c[i][q] * m);
				}
			}
		}
	}
	float d = 1;
	for (int w = 0; w < n; w++) {
		d = d * c[w][w];
	}
	return d;
}
// TIM MA TRAN PHU HOP
void phuhop(float X[][max], int n) {
	float c[max][max];
	for (int r = 0; r < n; r++) {
		for (int t = 0; t < n; t++) {
			c[r][t] = X[r][t];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			float x[max][max];
			for (int H = 0; H < n - 1; H++) {
				int h = H;
				if (h >= i) h = h + 1;
				for (int K = 0; K < n - 1; K++) {
					int k = K;
					if (K >= j) k = k + 1;
					x[H][K] = c[h][k];
				}
			}
			int s = pow((-1), (i + j));
			X[i][j] = s * tinhdet(x, n - 1);
		}
	}}
// HAM CHUYEN VI CUA MA TRAN
void chuyenvi(float A[][max], int n, int m, float A1[][max]) 
{
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			A1[j][i] = A[i][j];
		}
	}
}
// HAM NHAN 2 MA TRAN
void nhanmt(float a[max][max], int n, int m, float f[max][max], float T[][max], int m1) 
{
	float sum;
	for (int i = 0; i < n; i++) {   // n: so dong cua ma tran a
		for (int j = 0; j < m1; j++)   // m1 la so cot cua ma tran f
		 {   
			sum = 0;
			for (int k = 0; k < m; k++) // m so dong cua ma tran f
			 {
				sum += a[i][k] * f[k][j];
			}
			T[i][j] = sum;
		}
	}
}
// HAM TIM MA TRAN KHA NGHICH
void khanghic(float a[][max], int n, float d) 
{
	for (int i = 0; i < n; i++) {     
		for (int j = 0; j < n; j++) {
			a[i][j] = a[i][j] * (1 / d);
		}
	}
}
//HAM DU DOAN KET QUA
void dudoan(float W[][max],int n,int m,float A[][max],float kqdd[][max])
{
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
				kqdd[i][j]= W[1][0] * A[i][j] + W[0][0];	
		}	
	}
}
// HAM TIM SAI SO GIUA GIA TRI DU DOAN VA GIA TRI THUC 
float ERR(int n,int m,float err[max][max],float kqdd[max][max],float B[max][max])
{
		float tt;
		for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){ 
		 err[i][j]= (kqdd[i][j]-B[i][j]);	
		} 	
	}
}
int  main()
{    //doc file du lieu x.txt
	ifstream File;
	File.open("cotx.txt", ios_base::in);
	float A[max][max];
	int n, m;
	cout << "So hang cua ma tran A=";
	cin >> n;
	cout << "So cot cua ma tran A=";
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			File >> A[i][j];
		}
	}
	cout<<"du lieu  chieu cao \n ";
		for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout<< A[i][j]<<" ";
		}
		cout<<"\n";
	}
	//doc file du lieu y.txt
		ifstream Filetien;
	Filetien.open("coty.txt", ios_base::in);
	float B[max][max];
	int n1, m1;
	cout << "So hang cua ma tran B=";
	cin >> n1;
	cout << "So cot cua ma tran B=";
	cin >> m1;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			Filetien >> B[i][j];
		}
	}
	cout<<"Du lieu  can nang \n";
	for(int i=0;i<n1;i++)
	{
		for(int  j=0;j<m1;j++)
		{
			cout<<B[i][j]<<"\t";
		}
		cout<<"\n";
	}

	float X1[max][max];
	them(X1,n,m,A);   // X1 la ma tran sau khi them mot cot
	int z;                  // z la so hang cua ma tran sau khi them
	z=n+1;
	float X[max][max];
	chuyenvi(X1,z,m,X);  //  X la ma tran chuyen vi cua X1
	float  Y[max][max];
	chuyenvi(B,n1,m1,Y);     // Y la ma tran chuyen vi cua B
	float L[max][max];
	nhanmt(X1,z,m1,Y,L,n1); //ma tran L= X^-1 * Y
	float T[max][max];
	nhanmt(X1,z,m,X,T,z);  // ma tran T= X^-1 * X
	                                      //z la so hang  cua X1 
	                                     //m la so cot cua X1;z la so cot cua X;
   float d=tinhdet(T,z);
    phuhop(T, z);                     // kha nghich
    khanghic(T, z, d);            //tinh  ma tran nghich dao T^-1
	float W[max][max];
	nhanmt(T,z,z,L,W,n1); // W=T * L
	cout<<" KET QUA  :\n";
	if(W[0][0]>0)
	cout<<"\t y="<<W[1][0]<<"*x+"<<W[0][0]<<"\n";
     else cout<<" \t y="<<W[1][0]<<"*x"<<W[0][0]<<"\n";
	cout<<"\n";
	float kqdd[max][max];
	dudoan(W,n,m,A,kqdd);//du doan ket qua 
	float err[max][max];
	ERR(n,m,err,kqdd,B);// tim sai so giua gia tri du doan va gia tri thuc
	cout<<"stt"<<setw(11)<<"cotx"<<setw(13)<<"coty"<<setw(20);
       cout<<"dudoan"<<setw(21)<<"saiso"<<endl;
      cout<<"-----------------------------------------------------------------\n";
      for (int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
	cout<<j+1<<setw(12)<<A[i][j]<<setw(14)<<B[i][j]<<setw(22);
       cout<<kqdd[i][j]<<setw(22)<< err[i][j]<<endl;
		}
	}
     // tinh sai so du doan tren tap du lieu 
	float ss=0,M=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{    
		  ss+=kqdd[i][j]-B[i][j];
		  M++; 	
		} 	
	}
	cout<<"\n SAI SO DU DOAN TREN TAP DU LIEU \n";
	float MSE;
	MSE=sqrt((double)pow(ss,2)/M);
	cout<<"\tMSE="<<MSE;
	return 0;	
}



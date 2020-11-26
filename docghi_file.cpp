#include <iostream> 
#include <fstream> 

using namespace std;
/*void innput(float x[], int n)
{
	for(i=0;i<n;i++)
	{
		cout << x[i] << " ";
	}
}*/
int main()
{
    float data[2004][2];
    int n;
    cout << "Nhap n: ";
    cin >> n;
    
    ifstream doan("doan2.txt");
    if(! doan.is_open())
    {
        cout<<"Khong the mo file.\n";
        return 0;
    }
    else 
	{
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < 2; j++)
	        {
	            doan>>data[i][j];
	        }
        }        
    }
    cout << "\nNhap X:" << endl;
    for(int i =0; i < n; i++)
    {
        cout<<data[i][0] <<" ";
    }
    cout << "\nNhap Y:" << endl;
    for(int i =0; i < n; i++)
    {
        cout<<data[i][1] <<" ";
    }
    doan.close();
    //system("pause");
    return 0;
}

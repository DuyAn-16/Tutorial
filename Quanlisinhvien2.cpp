#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<fstream>
#include <string.h>
using namespace std;
struct danhsach{
	int ma_hs;
	char ten_hs[25],xeploai[10];
	float diem_toan,diem_ly,diem_hoa,diem_tb;
};
int stt=0;
danhsach hs[99];
danhsach hs2[99];
int thutu[99];
//NHAP THONG TIN
void nhap(int n){
	system("cls");
	for(int i=1;i<=n;i++){
		cout<<"Nhap thong tin hoc sinh thu "<<i<<": "<<endl;
		stt=stt+1;
		thutu[stt]=stt;
		cout<<"Ma so: ";cin>>hs[stt].ma_hs;
		fflush(stdin);
		cout<<"Ten HS: ";cin.getline(hs[stt].ten_hs,25);
		cout<<"Diem Toan: ";cin>>hs[stt].diem_toan;
		cout<<"Diem Ly: ";cin>>hs[stt].diem_ly;
		cout<<"Diem Hoa: ";cin>>hs[stt].diem_hoa;
	}
	system("pause");	
}
void diemTB(){
	system("cls");
	for(int i=1;i<=stt;i++){
		hs[i].diem_tb=(hs[i].diem_toan+hs[i].diem_ly+hs[i].diem_hoa)/3;
		if(hs[i].diem_tb>=9){
			strcpy(hs[i].xeploai,"Xuat sac");
	   }else if(hs[i].diem_tb>=8&&hs[i].diem_tb<9){
			strcpy(hs[i].xeploai,"Gioi");
	   }else if(hs[i].diem_tb>=7&&hs[i].diem_tb<8){
			strcpy(hs[i].xeploai,"Kha");
	   }else if(hs[i].diem_tb>=5&&hs[i].diem_tb<7){
			strcpy(hs[i].xeploai,"Trung binh");
	   }else if(hs[i].diem_tb<5){	
			strcpy(hs[i].xeploai,"Yeu");
	   }else {
			cout<<"Diem khong hop le";
	   }
	}
	cout<<"\n\n\n[-Da tinh diem trung binh va xep loai-]\n\n\n\n\n";
	system("pause");
}
void in(){
	system("cls");
 	cout<<setw(5)<<"STT"<<setw(8);
 	cout<<"Maso"<<setw(25);
 	cout<<"Ho ten"<<setw(15);
 	cout<<"Diem Toan"<<setw(10);
 	cout<<"Diem Ly"<<setw(10);
 	cout<<"Diem Hoa"<<setw(15);
 	cout<<"Diem TB"<<setw(15);
 	cout<<"Xep loai"<<endl;
    for(int i=1;i<=stt;i++) {
        cout<<setw(5)<<i<<setw(8);
		cout<<hs[i].ma_hs<<setw(25);
		cout<<hs[i].ten_hs<<setw(15);
		cout<<hs[i].diem_toan<<setw(10);
		cout<<hs[i].diem_ly<<setw(10);
		cout<<hs[i].diem_hoa<<setw(15);
		cout<<hs[i].diem_tb<<setw(15);
		cout<<hs[i].xeploai<<endl;
	}
    system("pause");
}
void sapxep(danhsach hs1[]){
	system("cls");
	for(int i=1;i<=stt;i++){
		hs1[i].ma_hs=hs[i].ma_hs;
		strcpy(hs1[i].ten_hs,hs[i].ten_hs);
		hs1[i].diem_toan=hs[i].diem_toan;
		hs1[i].diem_ly=hs[i].diem_ly;
		hs1[i].diem_hoa=hs[i].diem_hoa;
		hs1[i].diem_tb=hs[i].diem_tb;
		strcpy(hs1[i].xeploai,hs[i].xeploai);
	}
	danhsach temp;
	for(int i=1;i<=stt;i++){
		for(int j=i+1;j<=stt;j++){
			if(hs1[i].diem_tb<hs1[j].diem_tb){
				temp=hs1[i];
				hs1[i]=hs1[j];
				hs1[j]=temp;
			}
		}
	}
	cout<<setw(5)<<"STT"<<setw(8);
 	cout<<"Maso"<<setw(25);
 	cout<<"Ho ten"<<setw(15);
 	cout<<"Diem Toan"<<setw(10);
 	cout<<"Diem Ly"<<setw(10);
 	cout<<"Diem Hoa"<<setw(15);
 	cout<<"Diem TB"<<setw(15);
 	cout<<"Xep loai"<<endl;
    for(int i=1;i<=stt;i++) {
        cout<<setw(5)<<i<<setw(8);
		cout<<hs2[i].ma_hs<<setw(25);
		cout<<hs2[i].ten_hs<<setw(15);
		cout<<hs2[i].diem_toan<<setw(10);
		cout<<hs2[i].diem_ly<<setw(10);
		cout<<hs2[i].diem_hoa<<setw(15);
		cout<<hs2[i].diem_tb<<setw(15);
		cout<<hs2[i].xeploai<<endl;
	}
    system("pause");
}
void timmax(){
	system("cls");
	int thutu,i=0;
	int max = hs[0].diem_hoa;
	for(int i=1;i<=stt;i++){
		if(hs[i].diem_hoa>max){
			max = hs[i].diem_hoa;
			thutu=i;
		}
	}
	cout<<setw(5)<<"STT"<<setw(8);
 	cout<<"Maso"<<setw(25);
 	cout<<"Ho ten"<<setw(15);
 	cout<<"Diem Toan"<<setw(10);
 	cout<<"Diem Ly"<<setw(10);
 	cout<<"Diem Hoa"<<setw(15);
 	cout<<"Diem TB"<<setw(15);
 	cout<<"Xep loai"<<endl;
   	cout<<setw(5)<<i<<setw(8);
	cout<<hs[thutu].ma_hs<<setw(25);
	cout<<hs[thutu].ten_hs<<setw(15);
	cout<<hs[thutu].diem_toan<<setw(10);
	cout<<hs[thutu].diem_ly<<setw(10);
	cout<<hs[thutu].diem_hoa<<setw(15);
	cout<<hs[thutu].diem_tb<<setw(15);
	cout<<hs[thutu].xeploai<<endl;
	system("pause");
}
void xoa(){
	system("cls");
    int diem_ly,dem=0;
    cout<<"NHAP: ";cin>>diem_ly;cout<<"\n";
    for(int i=1;i<=stt;i++){
        if(hs[i].diem_ly>diem_ly){
        	dem=dem+1;
			hs[dem].ma_hs=hs[i].ma_hs;
			strcpy(hs[dem].ten_hs,hs[i].ten_hs);
			hs[dem].diem_toan=hs[i].diem_toan;
			hs[dem].diem_ly=hs[i].diem_ly;
			hs[dem].diem_hoa=hs[i].diem_hoa;
			hs[dem].diem_tb=hs[i].diem_tb;
			strcpy(hs[dem].xeploai,hs[dem].xeploai);
        }
    }
    stt=dem;
    cout<<"Da xoa nhung diem ly<diem_ly nhap tu ban phim\n\n\n";
	system("pause");
}
void luutep(){
	system("cls");
	ofstream outfile;
	outfile.open("sv1.dat",ios::app);
    for(int i=1;i<=stt;i++) {
        outfile<<setw(5)<<i<<setw(8);
		outfile<<hs[i].ma_hs<<setw(25);
		outfile<<hs[i].ten_hs<<setw(15);
		outfile<<hs[i].diem_toan<<setw(10);
		outfile<<hs[i].diem_ly<<setw(10);
		outfile<<hs[i].diem_hoa<<setw(15);
		outfile<<hs[i].diem_tb<<setw(15);
		outfile<<hs[i].xeploai<<endl;
	}
	outfile.close();
	cout<<"GHI TEP THANH CONG\n";
	system("pause");
}
void docfile(){
	system("cls");
 	cout<<setw(5)<<"STT"<<setw(8);
 	cout<<"Maso"<<setw(25);
 	cout<<"Ho ten"<<setw(15);
 	cout<<"Diem Toan"<<setw(10);
 	cout<<"Diem Ly"<<setw(10);
 	cout<<"Diem Hoa"<<setw(15);
 	cout<<"Diem TB"<<setw(15);
 	cout<<"Xep loai"<<endl;
	ifstream infile;
	infile.open("sv1.dat");
	string data;
	while(getline(infile,data)){
		cout<<data<<endl;
	}
	infile.close();
    system("pause");
}
int main(){
	int option,soluong;
	int exit=0;
	while(exit==0){
		system("cls");
		cout<<" --------------------------Menu----------------------------"<<endl;
		cout<<"  1. Nhap thong tin hoc sinh"<<endl;
		cout<<"  2. Tinh diem trung binh va xep loai"<<endl;
		cout<<"  3. In thong tin hoc sinh"<<endl;
		cout<<"  4. Sap xep hoc sinh theo diem trung binh"<<endl;
		cout<<"  5. In thong tin hoc sinh co diem hoa cao nhat"<<endl;
		cout<<"  6. Xoa danh sach hoc sinh co diem li<diem_ly"<<endl;
		cout<<"  7. Luu file"<<endl;
		cout<<"  8. Doc file"<<endl;
		cout<<"  9. Thoat chuong trinh"<<endl;
		cout<<" --------------------------END-----------------------------"<<endl;
		cout<<"MOI BAN CHON MENU: ";
		cin>>option;
		switch(option){
			case 1:{
				cout<<"Hoc sinh: ";cin>>soluong;
				nhap(soluong);
				break;
			}
			case 2:{
				diemTB();
				break;
			}
			case 3:{
				in();
				break;
			}
			case 4:{
				sapxep(hs2);
				break;
			}
			case 5:{
				timmax();
				break;
			}
			case 6:{
				xoa();
				break;
			}
			case 7:{
				luutep();
				break;
			}
			case 8:{
				docfile();
				break;
			}
			case 9:{
				exit=1;
				break;
			}
		}
	}
	}

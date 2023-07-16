#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include <iostream>
#include<fstream>
#include <string.h>
#define MAX 100
using namespace std;
 
struct SinhVien {
	int masv;
    int id;
    char ten[30];
    char gioiTinh[5];
    int namsinh;
    float diemTB = 0;
    char hocbong[10] = "-";
};
 
typedef SinhVien SV;
 
void printLine(int n);
void nhapThongTinSV(SV &sv, int id);
void nhapSV(SV a[], int id, int n);
void capNhatThongTinSV(SV &sv);
void capNhatSV(SV a[], int masv, int n);
int xoaTheoMSV(SV a[], int masv, int n);
void sapXepGT(SV a[], char ten[], int n);
void xeploai(SV &sv);
int idLonNhat(SV a[], int n);
void sapxepTheoDTB(SV a[], int n);
void showStudent(SV a[], int n);
void showbestStudent(SV a[], int n);
int docFile(SV a[], char fileName[]);
void ghiFile(SV a[], int n, char fileName[]);
void pressAnyKey();

int main() {
    int key;
    char fileName[] = "sinhvien.dat";
    SV arraySV[MAX];
    int soluongSV = 0;
    int idCount = 0;

    idCount = idLonNhat (arraySV, soluongSV);
 
    while(true) {
        cout << "             CHUONG TRINH QUAN LY SINH VIEN        "<<endl;
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Cap nhat thong tin sinh vien theo MSV.        **\n";
        cout << "**  3. Xoa sinh vien theo MSV.                       **\n";
        cout << "**  4. Hien sinh vien diem cao nhat theo gioi tinh.  **\n";
        cout << "**  5. Hien thi danh sach sinh vien.                 **\n";
        cout << "**  6. Sap xep sinh vien theo diem trung binh.       **\n";
        cout << "**  7. Ghi danh sach sinh vien vao file.             **\n";
        cout << "**  8. Doc danh sach sinh vien tu file.              **\n";
        cout << "**  0. Thoat.                                        **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Them sinh vien.";
                idCount++;
                nhapSV(arraySV, idCount, soluongSV);
                cout<<"\nThem sinh vien thanh cong!";
                soluongSV++;
                pressAnyKey();
                break;
            case 2:
                if(soluongSV > 0) {
                    int masv;
                    cout << "\n2. Cap nhat thong tin sinh vien. ";
                    cout << "\n Nhap MSV cua sinh vien: "; cin >> masv;
                    capNhatSV(arraySV, masv, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 3:
                if(soluongSV > 0) {
                    int masv;
                    cout << "\n3. Xoa sinh vien.";
                    cout << "\n Nhap Ma Sinh Vien: "; cin >> masv;
                    if (xoaTheoMSV(arraySV, masv, soluongSV) == 1) {
                    	cout << "\nSinh vien co MSV "<<masv<<" da bi xoa";
                        soluongSV--;
                    }
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 4:
                if(soluongSV > 0) {
                    cout << "\n4. Sinh vien diem cao nhat theo gioi tinh.";
                    char strGioitinh[5];
                    cout << "\nNhap gioi tinh: "<< endl; fflush(stdin); gets(strGioitinh);
                    cout << "Sinh vien "<<strGioitinh<<" diem cao nhat la:";
                    sapXepGT(arraySV, strGioitinh, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 5:
            	if(soluongSV > 0){
                    cout << "\n7. Hien thi danh sach sinh vien.";
                    showStudent(arraySV, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 6:
            	if(soluongSV > 0) {
                    cout << "\n5. Sap xep sinh vien theo diem trung binh.";
                    sapxepTheoDTB(arraySV, soluongSV);
                    showStudent(arraySV, soluongSV);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                pressAnyKey();
                break;
            case 7:
                if(soluongSV > 0){
                    cout << "\n8. Ghi danh sach sinh vien vao file.";
                    ghiFile(arraySV, soluongSV, fileName);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                cout << "\n Ghi danh sach sinh vien vao file "<< fileName<< " thanh cong!";
                pressAnyKey();
                break;
            case 8:
                if(soluongSV > 0){
                    cout << "\n8. Doc danh sach sinh vien tu file.";
                    docFile(arraySV, fileName);
                }else{
                    cout << "\nDanh sach sinh vien trong!";
                }
                cout << "\n Ghi danh sach sinh vien vao file "<< fileName<< " thanh cong!";
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}
 
void xeploai(SV &sv) {
    if(sv.diemTB >= 9) strcpy(sv.hocbong, "8tr");
    else if(sv.diemTB >= 8) strcpy(sv.hocbong, "5tr");
    else if(sv.diemTB >= 7) strcpy(sv.hocbong, "3tr");
    else strcpy(sv.hocbong, "0tr");
}
  
void nhapThongTinSV(SV &sv, int id) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap ma sinh vien: "; cin>> sv.masv;
    cout << " Nhap gioi tinh: "; cin >> sv.gioiTinh;
    cout << " Nhap nam sinh: "; cin >> sv.namsinh;
    cout << " Nhap diem Trung binh: "; cin >> sv.diemTB;
    sv.id = id;
    xeploai(sv);
}
 
void nhapSV(SV a[], int id, int n) {
    printLine(40);
    cout <<"\n Nhap sinh vien thu "<<n+1<<".";
    nhapThongTinSV(a[n], id);
    printLine(40);
}
 
void capNhatThongTinSV(SV &sv) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap ma sinh vien: "; cin >> sv.masv;
    cout << " Nhap gioi tinh: "; cin >> sv.gioiTinh;
    cout << " Nhap nam sinh: "; cin >> sv.namsinh;
    cout << " Nhap diem TB: "; cin >> sv.diemTB;
    xeploai(sv);
}
 
void capNhatSV(SV a[], int masv, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].masv == masv) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin sinh vien co MSV = " << masv;
            capNhatThongTinSV(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
    	cout <<"\n Sinh vien co MSV la "<< masv << " khong ton tai.";
    }
}
 
int xoaTheoMSV(SV a[], int masv, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].masv == masv) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa SV co MSV = " << masv;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
    	cout <<"\n Sinh vien co MSV la "<< masv << " khong ton tai.";
        return 0;
    } else {
        return 1;
    }
}
 
void sapXepGT(SV a[], char gioiTinh[], int n) {
    SV arrayFound[MAX];
    char GioitinhSV[5];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(GioitinhSV, a[i].gioiTinh);
        if(strstr(strupr(GioitinhSV), strupr(gioiTinh))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    int k = 1; 
    sapxepTheoDTB(arrayFound, found);
    showbestStudent(arrayFound, found);
}
 
void showStudent(SV a[], int n) {
    printLine(100);
    cout <<"\n\STT \tMa Sinh Vien \tHo va ten \tGioi tinh \tNam Sinh \tDiem TB \tHoc Bong";
    for(int i = 0; i < n; i++) {
    	cout << "\n" << i + 1;
    	cout << "\t" << a[i].masv;
    	cout << "\t\t" << a[i].ten;
    	cout << "\t\t" << a[i].gioiTinh;
    	cout << "\t\t" << a[i].namsinh;
    	cout << "\t\t" << a[i].diemTB;
    	cout << "\t\t" << a[i].hocbong;
    }
    printLine(100);
}
void showbestStudent(SV a[], int n) {
    printLine(100);
    cout <<"\n\STT \tMa Sinh Vien \tHo va ten \t\tGioi tinh \tNam Sinh \tDiem TB \tHoc Bong"<<endl;
    	cout <<"1";
    	cout << "\t" << a[0].masv;
    	cout << "\t\t" << a[0].ten;
    	cout << "\t" << a[0].gioiTinh;
    	cout << "\t\t\t" << a[0].namsinh;
    	cout << "\t\t" << a[0].diemTB;
    	cout << "\t\t" << a[0].hocbong;
    printLine(100);
}
  
void sapxepTheoDTB(SV a[], int n) {
    SV tmp;
    for(int i = 0;i < n;i++) {
        for(int j = i+1; j < n;j++) {
            if(a[i].diemTB < a[j].diemTB) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
int idLonNhat  (SV a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].id;
        for(int i = 0;i < n; i++) {
            if (a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}
 
int docFile(SV a[], char fileName[]) {
 	cout<<"STT"<<setw(8);
 	cout<<"Maso"<<setw(25);
 	cout<<"Ho ten"<<setw(15);
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
 
void ghiFile(SV a[], int n, char fileName[]) {
	ofstream outfile;
	outfile.open("sv1.dat", ios::app);
    for(int i=1;i<=n;i++) {
        cout<<i<<setw(8);
		cout<<a[i].masv;
		cout<<a[i].ten;
		cout<<a[i].gioiTinh;
		cout<<a[i].diemTB;
		cout<<a[i].hocbong<<endl;
	}
	outfile.close();
	cout<<"GHI TEP THANH CONG\n";
}
 
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
 
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}


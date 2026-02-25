/******************************************************************************
 * Họ và tên: [Nguyễn Quốc Hiệp]
 * MSSV:      [PS48461]
 * Lớp:       [CS21301]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>

// ====== CHUC NANG 1: KIEM TRA SO NGUYEN TO ======
void kiemTraSoNguyenTo() {
    int n, i, flag = 1;
    printf("Nhap so: ");
    scanf("%d", &n);

    if(n < 2) flag = 0;
    for(i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("%d la so nguyen to\n", n);
    else
        printf("%d khong phai so nguyen to\n", n);
}

// ====== CHUC NANG 2: UCLN VA BCNN ======
void ucln_bcnn() {
    int a, b, tempA, tempB;
    printf("Nhap 2 so: ");
    scanf("%d%d", &a, &b);

    tempA = a;
    tempB = b;

    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    printf("UCLN = %d\n", a);
    printf("BCNN = %d\n", (tempA * tempB) / a);
}

// ====== CHUC NANG 3: TINH TIEN KARAOKE ======
void tinhTienKaraoke() {
    int gioBatDau, gioKetThuc;
    float tien;

    printf("Nhap gio bat dau: ");
    scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc: ");
    scanf("%d", &gioKetThuc);

    int soGio = gioKetThuc - gioBatDau;

    if(soGio <= 3)
        tien = soGio * 150000;
    else
        tien = 3 * 150000 + (soGio - 3) * 100000;

    printf("Tien thanh toan: %.0f\n", tien);
}

// ====== CHUC NANG 4: TINH TIEN DIEN ======
void tinhTienDien() {
    int soDien;
    float tien = 0;

    printf("Nhap so dien: ");
    scanf("%d", &soDien);

    if(soDien <= 50)
        tien = soDien * 1678;
    else if(soDien <= 100)
        tien = 50 * 1678 + (soDien - 50) * 1734;
    else
        tien = 50 * 1678 + 50 * 1734 + (soDien - 100) * 2014;

    printf("Tien dien: %.0f\n", tien);
}

// ====== CHUC NANG 5: DOI TIEN ======
void doiTien() {
    int tien;
    printf("Nhap so tien: ");
    scanf("%d", &tien);

    printf("So to 500k: %d\n", tien / 500000);
    tien %= 500000;

    printf("So to 200k: %d\n", tien / 200000);
    tien %= 200000;

    printf("So to 100k: %d\n", tien / 100000);
}

// ====== CHUC NANG 6: TINH LAI VAY ======
void tinhLaiVay() {
    float tienVay = 100000000;
    float laiSuat = 0.05;
    int thang = 12;

    for(int i = 1; i <= thang; i++) {
        float lai = tienVay * laiSuat;
        printf("Thang %d: Lai = %.0f\n", i, lai);
    }
}

// ====== CHUC NANG 7: VAY MUA XE ======
void vayMuaXe() {
    float giaXe = 500000000;
    float traTruoc = giaXe * 0.2;
    float vay = giaXe - traTruoc;

    printf("Tien tra truoc: %.0f\n", traTruoc);
    printf("Tien vay: %.0f\n", vay);
}

// ====== CHUC NANG 8: SAP XEP SINH VIEN ======
void sapXepSinhVien() {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);

    float diem[n];

    for(int i = 0; i < n; i++) {
        printf("Nhap diem SV %d: ", i+1);
        scanf("%f", &diem[i]);
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(diem[i] < diem[j]) {
                float temp = diem[i];
                diem[i] = diem[j];
                diem[j] = temp;
            }
        }
    }

    printf("Danh sach sau sap xep:\n");
    for(int i = 0; i < n; i++)
        printf("%.2f\n", diem[i]);
}

// ====== MENU ======
int main() {
    int choice;

    do {
        printf("\n===== MENU ASM2 =====\n");
        printf("1. Kiem tra so nguyen to\n");
        printf("2. Tim UCLN & BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai vay\n");
        printf("7. Vay mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: kiemTraSoNguyenTo(); break;
            case 2: ucln_bcnn(); break;
            case 3: tinhTienKaraoke(); break;
            case 4: tinhTienDien(); break;
            case 5: doiTien(); break;
            case 6: tinhLaiVay(); break;
            case 7: vayMuaXe(); break;
            case 8: sapXepSinhVien(); break;
            case 0: printf("Thoat chuong trinh\n"); break;
            default: printf("Lua chon khong hop le\n");
        }

    } while(choice != 0);

    return 0;
}